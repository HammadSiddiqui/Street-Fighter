#pragma once
#include <iostream>

template <typename Type>
struct Node {
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
        void DeleteAt(int);
        int GetLength();
        void PrintAll();
        void Draw(BITMAP*);
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
    while(this->length != 0){
        this->Pop();
    }
    std::cout << "Circular Singly Linked List Destroyed" << std::endl;
}

//Head Does not change in QUEUE
//Node is inserted at the end of the queue/list
template <typename Type>
void CircleLinkedList<Type>::Insert(Type d) {
    Node<Type>* data = new Node<Type>;
    data->data = d;
    if(this->head == NULL) {

        head = data;
        data->next = head;
    }
    else {
        Node<Type>* temp = head;

        while(temp->next != head) {
            temp = temp->next;
        }
        data->next = this->head;
        temp->next = data;
    }
    length++;
}


//First in First Out
template <typename Type>
void CircleLinkedList<Type>::Pop() {
    /* We will have two temp pointers. Temp2 will treverse through the list to get to the end node that is pointing
    *  its next to head. We will tell that last node to point to the next of head.
    *  Then our temp node will be used to hold access to head while we change the head pointer. Once we change the head to head.next.
    *  We can delete the previous head via temp
    */
    Node<Type>* temp = head;
    Node<Type>* temp2 = head;
    while(temp2->next != head) {
        temp2 = temp2->next;
    }
    temp2->next = head->next;
    head = head->next;
    delete temp;
    length--;
}

template <typename Type>
void CircleLinkedList<Type>::DeleteAt(int index) {

    if(length == 1)
    {
        Pop();
    }

    else
    {
        Node<Type>* temp = head;
        Node<Type>* temp2 = head;
        while (index != 1) {
            temp2 = temp2->next; //node before the one that is to be deleted
            index--;
        }
        temp = temp2->next;
        temp2->next = temp->next;
        delete temp;
    }
}

template <typename Type>
Node<Type>* CircleLinkedList<Type>::GetHead() {
    return this->head;
}


template <typename Type>
int CircleLinkedList<Type>::GetLength() {
    return length;
}

template <typename Type>
void CircleLinkedList<Type>::Draw(BITMAP* buffer) {
    if(length == 1) {
        head->data->Draw(buffer);
    }
    else {

        Node<Type>* temp = this->head;
        while(temp->next != this->head) {
            temp->data->Draw(buffer);
            temp= temp->next;
        }
       temp->data->Draw(buffer);
    }

}



