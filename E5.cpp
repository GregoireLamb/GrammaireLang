#include "E5.h"
#include "Automate.h"
E5::E5(const string name) : Etat(name) {

}

E5::~E5() {

}

void E5::print() const {
    Etat::print();
}

bool E5::transition(Automate * automate,Symbole * s) {
    switch (*s){
        case OPENPAR:
            automate->decalage(s, new E2("Etat 2"));
            break;
        case INT:
            automate->decalage(s, new E3("Etat 3"));
            break;
        case EXPR:
            automate->decalage(s, new E8("Etat 8"));
            break;
        default:
            this->error();
            return false;
    }
    return true;
}