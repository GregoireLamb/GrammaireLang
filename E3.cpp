#include "E3.h"
#include "Automate.h"
E3::E3(const string name) : Etat(name) {

}

E3::~E3() {

}

void E3::print() const {
    Etat::print();
}

bool E3::transition(Automate * automate,Symbole * s) {
    switch (*s){
        case PLUS:
            automate->reduction(1,s);
            break;
        case MULT:
            automate->reduction(1,s);
            break;
        case CLOSEPAR:
            automate->reduction(1,s);
            break;
        case FIN:
            automate->reduction(1,s);
            break;
        default:
            this->error();
            return false;
    }
    return true;
}