#include <iostream>
#include "lexer.h"
#include "automate.h"


int main(void) {
   string chaine("(5+3)*123");

   Lexer l(chaine);

   /*Symbole * s;
   while(*(s=l.Consulter())!=FIN) {
      s->Affiche();
      cout<<endl;
      l.Avancer();
   }*/

   Automate a(chaine);
   return 0;
}

