//AB.cpp

#include "AB.h"


Sommet::Sommet(Valeur v){
  racine=v;
  SAG = NULL;
  SAD = NULL;
  Pere = NULL;
}

Sommet::Sommet(Sommet& s){
  Pere = NULL;
  if (s.SAG != NULL){
    SAG = new Sommet(*s.SAG);
  }
  if (s.SAD != NULL){
    SAD = new Sommet(*s.SAD);
  }
}


bool Sommet::FeuilleP(){
  if (SAG == NULL && SAD == NULL)
    return true;
  return false;
}


void Sommet::SupprimerSAG(){
  SAG = NULL;
}


void Sommet::SupprimerSAD(){
  SAD = NULL;
}


void Sommet::GrefferSAG(AB g){
  SAG = g;
}

void Sommet::GrefferSAD(AB d){
  SAD = d;
}


void Sommet::RemplacerPourLePerePar(AB Ar){
  //le pere existe
  //� impl�menter
}

int main(int argc, char const *argv[]) {
  AB aBinaire = new Sommet(6);
  AB aBinaire024 = new Sommet(0);
  aBinaire024->GrefferSAD(new Sommet(4));
  aBinaire024->GrefferSAG(new Sommet(2));
  aBinaire->GrefferSAG(aBinaire024);
  aBinaire->GrefferSAD(aBinaire024);
  SortieLatex(aBinaire);
  return 0;
}
