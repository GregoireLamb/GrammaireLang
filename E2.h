#pragma once

#include "etat.h"
#include "E3.h"
#include "E6.h"
#include "automate.h"


class Automate;


class E2 : public Etat{
    public:
        E2(string name);
        virtual ~E2();
        void print() const;
        bool transition(Automate * automate, Symbole * s);
    protected:
        string name;
};