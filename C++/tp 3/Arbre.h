#ifndef ARBRE_H
#define ARBRE_H

#include <vector>

using namespace std;

class Graphe{
  private:

  int nb_sommets;
  int nb_aretes;
  int *pere;            // L'arbre en largeur.
  int *ordre;           // L'ordre de parcours.
  int *niveau;          // Le niveau du point.
  int *debut;
  int *fin;
  vector<int> *voisins;

  public:

  Graphe(int, int);

  void GenererAretes();

  void AfficherAretes();

  void ParcoursLargeur(int);

  void EcritureNiveau();

  void ParcoursProfondeur(int);
};

#endif
