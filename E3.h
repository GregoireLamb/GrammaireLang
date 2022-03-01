#pragma once

#include "etat.h"
#include "automate.h"


class Automate;


class E3 : public Etat{
    public:
        E3(string name);
        virtual ~E3();
        void print() const;
        bool transition(Automate * automate, Symbole * s);
    protected:
        string name;
};