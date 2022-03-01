#pragma once

#include <string>
#include <map>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR" };

class Symbole {
   public:
      Symbole(int i) : ident(i) {  }
      Symbole(int i,bool terminal) : ident(i), terminal(terminal) {  }
      virtual ~Symbole() { }
      operator int() const { return ident; }
      virtual void Affiche();
      bool isTerminal(){return terminal;}
      virtual int getValeur(){return -1;};
      int getIdent () {return ident;};
   protected:
      int ident;
      bool terminal;
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT), valeur(v) { }
      ~Entier() { }
      virtual void Affiche();
      int getValeur(){return valeur;}
   protected:
      int valeur;
};

class Expr : public Symbole {
   public:
      Expr():Symbole(EXPR,false), valeur(0) { }
      Expr(int v):Symbole(EXPR,false), valeur(v) { }
      virtual ~Expr() {}
      int getValeur(){return valeur;}
      //virtual double eval(const map<string, double>
      // & valeurs);
   protected:
      int valeur;
};

