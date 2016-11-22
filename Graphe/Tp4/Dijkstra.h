#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>

using namespace std;
class Point{
  private:
    int deja_traite;
    int abscisse;
    int ordonee;
    int distance_racine;
    vector<int> *voisins;
    int pere;

  public:

    Point();

    int get_traite(int);

    int get_abscisse();

    int get_ordonee();

};

class Dijkstra{
  private:

    int nb_sommets;
    int nb_aretes;
    int distance_maximum;
    Point *points;
    int **arbre;



  public:

    Dijkstra(int,int);

    int distance_sommets(int, int);

    void generer_aretes();

    void afficher_aretes();

    void generer_sommets();

    void afficher_sommets();
};

#endif
