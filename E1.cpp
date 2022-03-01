#include "E1.h"
#include "Automate.h"
E1::E1(const string name) : Etat(name) {

}

E1::~E1() {

}

void E1::print() const {
    Etat::print();
}

bool E1::transition(Automate * automate,Symbole * s) {
    switch (*s){
        case PLUS:
            automate->decalage(s, new E4("Etat 4"));
            break;
        case MULT:
            automate->decalage(s, new E5("Etat 5"));
            break;
        case FIN:
            return false;
            break;
        default:
            this->error();
            return false;
    }
    return true;
}