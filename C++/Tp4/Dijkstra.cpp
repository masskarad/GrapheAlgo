#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include "Arbre.h"

using namespace std;

Point::Point(){
  abscisse = rand()%(612);
  ordonee = rand()%(792);
}

int Point::getAbscisse(){
  return abscisse;
}

int Point::getOrdonee(){
  return ordonee;
}

Dijkstra::Dijkstra(int p_sommets, int p_aretes){
  nb_sommets = p_sommets;
  nb_aretes = p_aretes;

}

void Dijkstra::GenererSommets(){

}

void Dijkstra::AfficherAretes(){

}

int main(){
  int sommet;             //Le nombre de sommets.
  int aretes;
  cout << "Entrer le nombre de sommets: ";
  cin >> sommet;
  cout << "Entrer le nombre d'aretes: ";
  cin >> aretes;
  Dijkstra dijkstra (sommet, aretes);
  dijkstra.GenererSommets();
  dijkstra.GenererAretes();

  return 1;
}
