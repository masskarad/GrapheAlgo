using namespace std;

typedef int indice;
typedef int valeur;

class ArbreComplet{

  private:
    indice indice_premier_sommet_libre;
    int nombre_maximal_sommets;
    valeur contenu [];

  public:
    ArbreParfait(int p_nombre_maximal_sommet){
      indice_premier_sommet_libre = 1;
      nombre_maximal_sommets = p_nombre_maximal_sommet;
      contenu [nombre_maximal_sommets + 1]; //Pas de case 0
    }

    void add(valeur p_valeur){
      if (indice_premier_sommet_libre <= nombre_maximal_sommets){

        }
      }
    }
};

int main(){
  return 0;
}

 
