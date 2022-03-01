#pragma once

#include "etat.h"
#include "E1.h"
#include "E2.h"
#include "E3.h"

class Automate;

class E0 : public Etat{
    public:
        E0(string name);
        virtual ~E0();
        void print() const;
        bool transition(Automate * automate, Symbole * s);
    protected:
        string name;
};