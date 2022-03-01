#include "E2.h"
#include "Automate.h"
E2::E2(const string name) : Etat(name) {

}

E2::~E2() {

}

void E2::print() const {
    Etat::print();
}

bool E2::transition(Automate * automate,Symbole * s) {
    switch (*s){
        case INT:
            automate->decalage(s, new E3("Etat 3"));
            break;
        case EXPR:
            automate->decalage(s, new E6("Etat 6"));
            break;
        case OPENPAR:
            automate->decalage(s, new E2("Etat 2"));
            break;
        default:
            this->error();
            return false;
    }
    return true;
}