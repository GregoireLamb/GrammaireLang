#include "E0.h"
#include "Automate.h"

E0::E0(const string name) : Etat(name) {

}

E0::~E0() {

}

void E0::print() const {
    Etat::print();
}

bool E0::transition(Automate * automate,Symbole * s) {
    switch (*s){
        case EXPR:
            automate->decalage(s, new E1("Etat 1"));
            break;
        case OPENPAR:
            automate->decalage(s, new E2("Etat 2"));
            break;
        case INT:
            automate->decalage(s, new E3("Etat 3"));
            break;
        default:
            this->error();
            return false;
    }
    return true;
}