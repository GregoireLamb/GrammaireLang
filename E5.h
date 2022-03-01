#pragma once

#include "etat.h"
#include "E2.h"
#include "E3.h"
#include "E8.h"

#include "automate.h"


class Automate;


class E5 : public Etat{
    public:
        E5(string name);
        virtual ~E5();
        void print() const;
        bool transition(Automate * automate, Symbole * s);
    protected:
        string name;
};