#include "E9.h"
#include "Automate.h"
E9::E9(const string name) : Etat(name) {

}

E9::~E9() {

}

void E9::print() const {
    Etat::print();
}

bool E9::transition(Automate * automate,Symbole * s) {
    switch (*s){
        case PLUS:
            automate->reduction(3,s);
            break;
        case MULT:
            automate->reduction(3,s);
            break;
        case CLOSEPAR:
            automate->reduction(3,s);
            break;
        case FIN:
            automate->reduction(3,s);
            break;
        default:
            this->error();
            return false;
    }
    return true;
}