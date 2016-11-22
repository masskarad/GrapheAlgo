//AB.cpp

#include "AB.h"


Sommet::Sommet(Valeur v){
  racine=v;
}

Sommet::Sommet(Sommet& s){
  Pere = NULL;
  SAG = s.SAG;
  SAD = s.SAD;
}


bool Sommet::FeuilleP(){
  //� impl�menter
}


void Sommet::SupprimerSAG(){
  //� impl�menter
}


void Sommet::SupprimerSAD(){
  //� impl�menter
}


void Sommet::GrefferSAG(AB g){
  //� impl�menter
 }

void Sommet::GrefferSAD(AB d){
  //� impl�menter
 }


void Sommet::RemplacerPourLePerePar(AB Ar){
  //le pere existe
  //� impl�menter
}

int main(int argc, char const *argv[]) {

  return 0;
}
