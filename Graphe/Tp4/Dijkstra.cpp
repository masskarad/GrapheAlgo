#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include "Dijkstra.h"

using namespace std;

Point::Point(){
  abscisse = rand()%(612);
  ordonee = rand()%(792);
  deja_traite = 0;
  voisins = new vector<int>;
}

int Point::get_abscisse(){
  return abscisse;
}

int Point::get_ordonee(){
  return ordonee;
}

Dijkstra::Dijkstra(int p_sommets, int p_distance_maximum){
  nb_sommets = p_sommets;
  distance_maximum = p_distance_maximum;
  points = new Point[nb_sommets];
}

void Dijkstra::generer_sommets(){
  for (int i = 0; i<nb_sommets; i++){
    points[i] = Point();
  }
}

void Dijkstra::afficher_sommets(){
  for (int i = 0; i<nb_sommets; i++){
    cout << i << " || abscisse : " << points[i].get_abscisse() << " || ordonee : " << points[i].get_ordonee() << endl;
  }
}

void Dijkstra::generer_aretes(){
  for (int i = 0; i < nb_sommets; i++) {
    if
  }
  if
}

int Dijkstra::distance_sommets(int sommet_a, int sommet_b){
  return sqrt(pow(abs(points[sommet_a].get_abscisse()-points[sommet_b].get_abscisse()),2)+pow(abs(points[sommet_a].get_ordonee()-points[sommet_b].get_ordonee()),2));
}

void Dijkstra::afficher_aretes(){
/*  ofstream output;
   output.open("Exemple.ps",ios::out);
   output << "%!PS-Adobe-3.0" << endl;
   output << "%%BoundingBox: 0 0 612 792" << endl;
   output << endl;
   for(int i=0;i<n;i++)
     {output << points[i].abs << " " << points[i].ord << " 3 0 360 arc" <<endl;
     output << "0 setgray" <<endl;
     output << "fill" <<endl;
     output << "stroke"<<endl;
     output << endl;
     }
   output << endl;
   for(int i=0;i<nb_sommets-1;i++)
     {output << point[arbre[i][0]].abs << " " << point[arbre[i][0]].ord
  	   << " moveto" << endl;
     output << point[arbre[i][1]].abs << " " << point[arbre[i][1]].ord
  	  << " lineto" << endl;
     output << "stroke" << endl;
     output << endl;
     }
   output << "showpage";
   output << endl;*/
}

int main(){
  int sommet;             //Le nombre de sommets.
  int distance_max = 50;
  cout << "Entrer le nombre de sommets: ";
  cin >> sommet;
  Dijkstra dijkstra (sommet, distance_max);
  dijkstra.generer_sommets();
  dijkstra.afficher_sommets();
  /*
  dijkstra.generer_aretes();
*/
  return 1;
}
