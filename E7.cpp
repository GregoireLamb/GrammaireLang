#include "E7.h"
#include "Automate.h"
E7::E7(const string name) : Etat(name) {

}

E7::~E7() {

}

void E7::print() const {
    Etat::print();
}

bool E7::transition(Automate * automate,Symbole * s) {
    switch (*s){
        case MULT:
            automate->decalage(s, new E5("Etat 5"));
            break;
        case PLUS:
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