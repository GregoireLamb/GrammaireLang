#pragma once

#include "etat.h"
#include "E2.h"
#include "E3.h"
#include "E7.h"
#include "automate.h"


class Automate;


class E4 : public Etat{
    public:
        E4(string name);
        virtual ~E4();
        void print() const;
        bool transition(Automate * automate, Symbole * s);
    protected:
        string name;
};