#include "E6.h"
#include "Automate.h"
E6::E6(const string name) : Etat(name) {

}

E6::~E6() {

}

void E6::print() const {
    Etat::print();
}

bool E6::transition(Automate * automate,Symbole * s) {
    switch (*s){
        case PLUS:
            automate->decalage(s, new E4("Etat 4"));
            break;
        case MULT:
            automate->decalage(s, new E5("Etat 5"));
            break;
        case CLOSEPAR:
            automate->decalage(s, new E9("Etat 9"));
            break;
        default:
            this->error();
            return false;
    }
    return true;
}