#include <iostream>
#include "lexer.h"
#include "automate.h"


int main(void) {
   string chaine;
   
   cin >> chaine ;

   Lexer l(chaine);

   Automate a(chaine);   
   
   return 0;
}

