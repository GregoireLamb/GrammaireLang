#pragma once
#include "etat.h"
#include "E4.h"
#include "E5.h"
#include "automate.h"


class Automate;


class E7 : public Etat{
    public:
        E7(string name);
        virtual ~E7();
        void print() const;
        bool transition(Automate * automate, Symbole * s);
    protected:
        string name;
};