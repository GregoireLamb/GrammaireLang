#pragma once
#include <vector>
#include "symbole.h"
#include "automate.h"

#include <iostream>
#include <string>
using namespace std;
class Automate; 

class Etat{
    public:
        Etat(string name):name(name){ };
        virtual ~Etat(){};
        void print() const{cout<<name<<endl;};
        void error(){cout<<"Caractere inconnu"<<endl;};
        virtual bool transition(Automate * automate, Symbole * s) = 0;
    protected:
        string name;

};