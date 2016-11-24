#include "ArbreBinaireRecherche.h"

SommetABR::SommetABR(Valeur v){
  racine=v; SAG=NULL; SAD=NULL;Pere=NULL;
}

SommetABR::SommetABR(SommetABR& s){
  racine=s.racine; SAG=NULL; SAD=NULL;
  if (s.SAG) GrefferSAG(new SommetABR(*(s.SAG)));
  if (s.SAD) GrefferSAD(new SommetABR(*(s.SAD)));
}

ABR SommetABR::PlusPetit(){
  //impl�menter
}

ABR SommetABR::RechercherValeur(Valeur v){
  //impl�menter
}

void SommetABR::InsererValeur(Valeur v){
  //impl�menter
}

ABR SommetABR::SupMin(){
  //impl�menter
}


ABR SommetABR::SupprimerValeur(Valeur v){
  //impl�menter
}

int main() {
  ABR A1=new SommetABR(11);
  //impl�menter
  return 1;
}

/* compiler avec g++  ArbreBinaireRecherche.cpp SortieLatex.cpp  */
