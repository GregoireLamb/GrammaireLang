#pragma once
#include "etat.h"
#include "automate.h"


class Automate;


class E9 : public Etat{
    public:
        E9(string name);
        virtual ~E9();
        void print() const;
        bool transition(Automate * automate, Symbole * s);
    protected:
        string name;
};