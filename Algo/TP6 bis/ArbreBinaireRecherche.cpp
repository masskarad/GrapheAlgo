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
  //implémenter
  }



ABR SommetABR::RechercherValeur(Valeur v){
  //implémenter
  } 

void SommetABR::InsererValeur(Valeur v){
  //implémenter
  }

ABR SommetABR::SupMin(){
  //implémenter
  }


ABR SommetABR::SupprimerValeur(Valeur v){
  //implémenter
  }





int main() {
  ABR A1=new SommetABR(11);
  //implémenter
  return 1;
}

/* compiler avec g++  ArbreBinaireRecherche.cpp SortieLatex.cpp  */
