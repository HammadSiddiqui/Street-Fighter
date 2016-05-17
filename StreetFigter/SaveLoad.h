#pragma once
#include "CircleLinkedList.h"
#include "Background.h"
#include "Enemy.h"
class SaveLoad
{
    friend class CircleLinkedList<Fighter>;
    public:
        SaveLoad();
        SaveLoad(CircleLinkedList<Fighter*>*, Background*);
        void Save();
        void Load(BITMAP*);
        ~SaveLoad();

    protected:
        CircleLinkedList<Fighter*>* lst;
        Background* area;

    private:
};
