#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>

using namespace std;
class Point{
  private:

    int abscisse;
    int ordonee;

  public:

    Point();

    int getAbscisse();

    int getOrdonee();

}

class Dijkstra{
  private:

    int nb_sommets;
    int nb_aretes;
    int *distance;
    point *coordonee;
    int **arbre;
    int *pere;
    vector<int> *voisins;

  public:

    Dijkstra(int, int);

    void GenererAretes();

    void AfficherAretes();

    void GenererSommets();
};

#endif
