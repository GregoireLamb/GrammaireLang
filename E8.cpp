#include "E8.h"
#include "Automate.h"
E8::E8(const string name) : Etat(name) {

}

E8::~E8() {

}

void E8::print() const {
    Etat::print();
}

bool E8::transition(Automate * automate,Symbole * s) {
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