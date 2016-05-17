#pragma once
#include <iostream>
#include "allegro.h"
#include "Fighter.h"

template <typename Type>
struct Node
{
    Type data;
    Node<Type>* next;

};

template <typename Type>
class CircleLinkedList
{
public:
    CircleLinkedList();
    ~CircleLinkedList();
    Node<Type>* GetHead();
    void Pop();
    void Insert(Type);
    int GetLength();
    void CollisionDetection(Node<Type>*);
    void CollisionFunction();
    void DeleteDead();
    void Draw(BITMAP*);
    void AI();
protected:


private:
    Node<Type>* head;
    int length;
};

template <typename Type>
CircleLinkedList<Type>::CircleLinkedList()
{
    std::cout << "Circular Singly Linked List Created" << std::endl;
    this->head = NULL;
    length = 0;
}
template <typename Type>
CircleLinkedList<Type>::~CircleLinkedList()
{
    while(this->length != 0)
    {
        this->Pop();
        std::cout << length << std::endl;
    }

    std::cout << "Circular Singly Linked List Destroyed" << std::endl;
}

//Head Does not change in QUEUE
//Node is inserted at the end of the queue/list
template <typename Type>
void CircleLinkedList<Type>::Insert(Type d)
{
    Node<Type>* temp = new Node<Type>;
    temp->data = d;
    if(this->head == NULL)
    {

        head = temp;
        temp->next = head;
    }
    else
    {
        Node<Type>* temp2 = head;

        while(temp2->next != head)
        {
            temp2 = temp2->next;
        }
        temp->next = this->head;
        temp2->next = temp;
    }

    length++;
}


//First in First Out
template <typename Type>
void CircleLinkedList<Type>::Pop()
{
    /* We will have two temp pointers. Temp2 will treverse through the list to get to the end node that is pointing
    *  its next to head. We will tell that last node to point to the next of head.
    *  Then our temp node will be used to hold access to head while we change the head pointer. Once we change the head to head.next.
    *  We can delete the previous head via temp
    */

    Node<Type>* temp = head;
    if (head == NULL || head->next == head)
    {

        if(head != NULL) {
            head = NULL;
            delete temp;
        }
        length = 0;
        return;
    }
    else
    {
        Node<Type>* temp2 = head;
        while(temp2->next != head)
        {
            temp2 = temp2->next;
        }
        temp2->next = head->next;
        head = head->next;
        delete temp;
        length--;
    }
}

template <typename Type>
Node<Type>* CircleLinkedList<Type>::GetHead()
{
    return this->head;
}


template <typename Type>
int CircleLinkedList<Type>::GetLength()
{
    return length;
}

template <typename Type>
void CircleLinkedList<Type>::Draw(BITMAP* buffer)
{
    if(length == 1)
    {
        head->data->Draw(buffer);
    }
    else
    {

        Node<Type>* temp = this->head;
        while(temp->next != this->head)
        {
            temp->data->Draw(buffer);
            temp= temp->next;
        }
        temp->data->Draw(buffer);
    }

}

template <typename Type>
void CircleLinkedList<Type>::CollisionDetection(Node<Type>* enemy)
{

    Node<Type>* fighter = this->head;

    //Collision Detection when Bounding boxes overlap and the sprites are in attack state.
    if((fighter->data->GetState() == PUNCH || fighter->data->GetState() == KICK) &&
            ((fighter->data->GetPosition().x + fighter->data->GetFrameWidth() - enemy->data->GetPosition().x) > 10))
    {
        enemy->data->TakeDamage(10);

    }
    else if((enemy->data->GetState() == PUNCH || enemy->data->GetState() == KICK) &&
            ((fighter->data->GetPosition().x + fighter->data->GetFrameWidth() - enemy->data->GetPosition().x) > 0))
    {
        fighter->data->TakeDamage(10);
    }

}

//This Function checks all nodes and delete the ones in which the object is not alive
template <typename Type>
void CircleLinkedList<Type>::DeleteDead()
{
    if(this->head == NULL)
    {
        return;

    }
    else
    {


        int nodePos = 0;
        Node<Type>* temp = head;
        //if our player is dead, which is present at the head of the list
        if(head->data->isAlive() == false)
        {

            //The last node is pointing to current head. We have to make it point to head->next
            if(length == 1)
            {

                head = NULL;
                delete temp;
            }
            else{

                Node<Type>* temp2 = head;
                while(temp2->next != head)
                {
                    temp2 = temp2->next;
                }
                head = head->next;
                temp2->next = head;
                //after pointing the last node to new head, we delete the old head and it's data
                delete temp->data;
                delete temp;
            }
        }
        else
        {
            //else we loop through all the rest of the nodes and remove the dead nodes.
            while(temp->next != head)
            {

                if(temp->next->data->isAlive() == false)
                {

                    Node<Type>* temp2 = temp->next;
                    temp->next = temp2->next;
                    delete temp2->data;
                    delete temp2;
                    length--;

                }
                temp = temp->next;
                nodePos++;

            }
            //this has to be especially called again as the LAST NODE is not checked in the while loop above in a Circled linked list
            if(temp->next->data->isAlive() == false)
            {

                Node<Type>* temp2 = temp->next;
                temp->next = temp2->next;
                delete temp2->data;
                delete temp2;
                length--;

            }


        }
    }
}


template <typename Type>
void CircleLinkedList<Type>::CollisionFunction()
{
    //Runs Artificial Intelligence on Enemies. Head is our Player, rest are enemies.
    if (head == NULL or head->next == head)
    {
        return;
    }
    else
    {
        Node<Type>* temp = head->next;
        while(temp->next != head)
        {
            this->CollisionDetection(temp);
            temp = temp->next;
        }
        this->CollisionDetection(temp);
    }
}

template <typename Type>
void CircleLinkedList<Type>::AI()
{
    //Runs Artificial Intelligence on Enemies. Head is our Player, rest are enemies.
    Node<Type>* temp = head;
    while(temp->next != head)
    {
        temp->data->AI();
        temp = temp->next;
    }
    temp->data->AI();
}
