#include "automate.h"
#include "symbole.h"
#include "E0.h"
#include "etat.h"
#include <iostream>
using namespace std;

Automate::Automate(string chaine) {
    lexer=new Lexer(chaine);
    listeEtats.push_back(new E0("Etat 0"));
    run();
}
void Automate::run(){
    Symbole *s;
    bool res=true;
    while(*(s=lexer->Consulter())!=FIN && res){
        s->Affiche();
        cout<<endl;
        cout<<"listeEtat :"<< endl;
        for(int i=0;i<listeEtats.size();i++){
            listeEtats.at(i)->print();
        }
        cout<<endl;
        res=listeEtats.back()->transition(this,s);
        lexer->Avancer();
    }
    while(pileSymboles.size() > 0 && res){
        res=listeEtats.back()->transition(this,s);
    }
}


void Automate::decalage(Symbole * s,Etat * etat){
    listeEtats.push_back(etat);
    pileSymboles.push_back(s);
    if(s->isTerminal() == 1){
        lexer->Avancer();
        cout << "----------------------" << endl;
    }
    
}

void Automate::reduction(int n,Symbole * s){
    //cout<<"n=" << n <<endl;
    vector<Symbole*> enlever;
    // cout << "rEDUCTION symboles" <<endl;
    // for(int i=0 ; i< pileSymboles.size() ; i++)
    // {
    //     pileSymboles.at(i)->Affiche();
    //}
    for(int i=0;i<n;i++){
        //cout << i<<endl;
        //delete(listeEtats.back());
        listeEtats.pop_back();
        enlever.push_back(pileSymboles.back());
        //pileSymboles.back()->Affiche();
        pileSymboles.pop_back();
    }
    int val = calcul(n,enlever); 
    cout<<"resultat intermediaire : "<<val<<endl;
    //pileSymboles.push_back(new Expr(val));
    lexer->AddSymbole(s);
    listeEtats.back()->transition(this,new Expr(val));
}

int Automate::calcul(int n, vector<Symbole*> calc){
    int res;

    if(n==1){
        res=calc.back()->getValeur();
    }else if(n==3){
        if(*calc.front()==OPENPAR && *calc.back()==CLOSEPAR){
            res=calc.at(1)->getValeur();
        }else{
            if(*calc.at(1)==PLUS){
                res=calc.at(0)->getValeur() + calc.at(2)->getValeur();
            }else if(*calc.at(1)==MULT){
                res=calc.at(0)->getValeur() * calc.at(2)->getValeur();
            }
        }
    }
    return res;

}