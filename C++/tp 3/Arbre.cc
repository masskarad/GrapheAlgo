#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include "Arbre.h"

using namespace std;

Graphe::Graphe(int p_sommets, int p_aretes){
  nb_sommets = p_sommets;
  nb_aretes = p_aretes;
  voisins = new vector<int> [nb_sommets];
  pere = new int[nb_sommets];
  ordre = new int[nb_sommets];
  niveau = new int[nb_sommets];
  debut = new int[nb_sommets];
  fin = new int[nb_sommets];
}

void Graphe::GenererAretes(){

  for(int i = 0; i<nb_aretes;i++){
    bool areteOk = false;
    while (!areteOk) {
      areteOk = true;
      int rand1 = rand()%(nb_sommets);
      int rand2 = rand()%(nb_sommets);
      if (rand1 == rand2){
        areteOk = false;
      }
      else{
        for(int j=0; j<voisins[rand1].size();j++){
          if(rand2 == voisins[rand1][j] )
            areteOk = false;
        }
      }
      if(areteOk == true){
        voisins[rand1].push_back(rand2);
        voisins[rand2].push_back(rand1);
      }
    }
  }
}

void Graphe::AfficherAretes(){
  for(int i = 0; i<nb_sommets; i++)
    for(int j = 0; j<voisins[i].size(); j++)
      cout << i << " | " << voisins[i][j] << endl;
}

void Graphe::ParcoursLargeur(int p_racine){
  int temps = 2;
  std::vector<int> aTraiter;
  int *dejaVu = new int[nb_sommets];
  dejaVu[p_racine] = 1;
  ordre[p_racine] = 1;
  pere[p_racine] = p_racine;
  niveau[p_racine] = 0;
  aTraiter.push_back(p_racine);
  while (!aTraiter.empty()){
    int enTraitement = aTraiter.front();
    aTraiter.erase(aTraiter.begin());
    for(int i = 0; i<voisins[enTraitement].size(); i++){
      if(dejaVu[voisins[enTraitement][i]] == 0){
        dejaVu[voisins[enTraitement][i]] = 1;
        aTraiter.push_back(voisins[enTraitement][i]);
        ordre[voisins[enTraitement][i]] = temps++;
        pere[voisins[enTraitement][i]] = enTraitement;
        niveau[voisins[enTraitement][i]] = niveau[enTraitement] + 1;
        cout << niveau[voisins[enTraitement][i]] << endl;
      }
    }
  }
}

void Graphe::EcritureNiveau(){
  int *niveauxDifferents = new int[nb_sommets];
  for (int i = 0; i<nb_sommets; i++)
    niveauxDifferents[i] =0;
  for (int i = 0; i<nb_sommets; i++){
    niveauxDifferents[niveau[i]] ++;
    cout << niveau[i] << endl;
  }
  for (int i = 0; i<nb_sommets; i++)
    if (niveauxDifferents[i]>0)
      cout << niveauxDifferents[i] << " sommets de niveau " << i << endl;
}

void Graphe::ParcoursProfondeur(int p_racine){
  int temps = 2;
  std::vector<int> aTraiter;
  int *dejaVu = new int[nb_sommets];
  dejaVu[p_racine] = 1;
  ordre[p_racine] = 1;
  pere[p_racine] = p_racine;
  niveau[p_racine] = 0;
  debut[p_racine] = 1;
  aTraiter.push_back(p_racine);
  while (!aTraiter.empty()){
    int enTraitement = aTraiter.back();

    if(voisins[enTraitement].empty())
    {
      aTraiter.pop_back();
      fin[enTraitement] = temps++;
    }
    else
    {
      int voisin = voisins[enTraitement].back();
      voisins[enTraitement].pop_back();
      if(dejaVu[voisin] == 0){
        dejaVu[voisin] = 1;
        aTraiter.push_back(voisin);
        debut[voisin] = temps++;
        pere[voisin] = enTraitement;
        niveau[voisin] = niveau[enTraitement] + 1;
        cout << niveau[voisin] << endl;
      }
    }
  }
}



int main(){
  int sommet;             //Le nombre de sommets.
  int aretes;
  cout << "Entrer le nombre de sommets: ";
  cin >> sommet;
  cout << "Entrer le nombre d'aretes: ";
  cin >> aretes;
  Graphe graphe (sommet, aretes);
  graphe.GenererAretes();
  Graphe graphe_bis = graphe;
  graphe.AfficherAretes();
  graphe.ParcoursLargeur(1);
  graphe.EcritureNiveau();

  graphe_bis.ParcoursProfondeur(0);
  return 1;
}
