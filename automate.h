#pragma once

#include "symbole.h"
#include "etat.h"
#include "lexer.h"

#include <vector>
#include <string>
using namespace std;

class Etat;
class E0;

class Automate{
    public:
      Automate(string);
      void decalage(Symbole * s,Etat * etat);
      void reduction(int n,Symbole * s);
      int calcul(int n,vector<Symbole*> calc);
      vector<Symbole *> getPileSymboles(){return pileSymboles;};
      void run();

   protected:
      vector<Etat *>  listeEtats;
      vector<Symbole *> pileSymboles;
      Lexer * lexer;
};