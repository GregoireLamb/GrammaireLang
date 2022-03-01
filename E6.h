#pragma once

#include "etat.h"
#include "E4.h"
#include "E4.h"
#include "E9.h"

#include "automate.h"


class Automate;


class E6 : public Etat{
    public:
        E6(string name);
        virtual ~E6();
        void print() const;
        bool transition(Automate * automate, Symbole * s);
    protected:
        string name;
};