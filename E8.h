#pragma once
#include "etat.h"
#include "E4.h"
#include "E5.h"
#include "automate.h"


class Automate;


class E8 : public Etat{
    public:
        E8(string name);
        virtual ~E8();
        void print() const;
        bool transition(Automate * automate, Symbole * s);
    protected:
        string name;
};