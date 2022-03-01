#pragma once

#include "etat.h"
#include "E4.h"
#include "E5.h"
#include "automate.h"


class Automate;


class E1 : public Etat{
    public:
        E1(string name);
        virtual ~E1();
        void print() const;
        bool transition(Automate * automate, Symbole * s);
    protected:
        string name;
};