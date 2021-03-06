#include "E4.h"
#include "Automate.h"
E4::E4(const string name) : Etat(name) {

}

E4::~E4() {

}

void E4::print() const {
    Etat::print();
}

bool E4::transition(Automate * automate,Symbole * s) {
    switch (*s){
        case OPENPAR:
            automate->decalage(s, new E2("Etat 2"));
            break;
        case INT:
            automate->decalage(s, new E3("Etat 3"));
            break;
        case EXPR:
            automate->decalage(s, new E7("Etat 7"));
            break;
        default:
            this->error();
            return false;
    }
    return true;
}