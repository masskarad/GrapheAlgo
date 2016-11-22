//SortieLatex.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdlib.h>

typedef int Valeur;

class Sommet;

typedef Sommet* AB;

void SortieLatex(AB Ar);

class Sommet {
  protected:
  Valeur racine;
  AB Pere,SAG, SAD;

  int hauteur,balanceGmoinsD;

  public:
  Sommet(Valeur v);
  Sommet(Sommet& s);

 AB remonterToutEnHaut();

  void GrefferSAG(AB g);
  void GrefferSAD(AB d);

  void SupprimerSAG();
  void SupprimerSAD();

  bool FeuilleP();

  void RemplacerPourLePerePar(AB);

  friend std::string* TikzRecursAB(int ligne,int gauche, int droite, int numeroPere, int typeFils, AB Ar);


};

std::string* TikzRecursAB(int ligne,int gauche, int droite, int numeroPere, int typeFils, AB Ar);



std::string * TikzRecursAB(int ligne,int gauche, int droite, int numeroPere, int typeFils, AB Ar){
  std::ostringstream ossnum, osslign,osscol,ossnumPere, ossbal, ossnum2Pere,ossnumRac;

      std::string stres("");

      if (Ar) {
    ossnumPere<<numeroPere;
    ossnumRac<<Ar->racine;
    if (Ar->Pere )ossnum2Pere<<Ar->Pere->racine; else ossnum2Pere<<0;
    int numero;
    if (typeFils==-1) numero=1; else numero= 2*numeroPere + typeFils;
    ossnum<<numero;
    osslign<<ligne;
    int mil = (gauche + droite)/2;
    osscol<<mil;

    stres="\\node[draw] (SZ" + ossnum.str() + ") at (" + osscol.str() + ", " + osslign.str() + ") { " + ossnumRac.str() + "};\n";

    if (typeFils!=-1) stres+="\\draw (SZ"+ossnumPere.str()+") -- (SZ"+ossnum.str() +");\n";
    if (Ar->SAG) stres+=*TikzRecursAB(ligne -1 ,gauche,mil-1, numero,0,Ar->SAG);
    if (Ar->SAD) stres+=*TikzRecursAB(ligne - 1,mil+1,droite, numero,1,Ar->SAD);
 }
  return new std::string(stres);
}

std::string * TikzAB(AB Ar){
  return TikzRecursAB(1,1,10,1, -1,Ar);
}

 void SortieLatex(AB Ar){
 std::ofstream fichier("fig.tex", std::ios::out | std::ios::trunc);
 std::string preamb ("\\documentclass[a4paper]{article} \n \\usepackage{tikz} \n \\begin{document} \n \\begin{tikzpicture}\n");
  std::cout<<preamb<<"\n";
std::string post("\\end{tikzpicture}\n  \\end{document} \n");
  std::cout<<post<<"\n";
 std::cout<<*TikzAB(Ar)<<"\n";
std::string   res1(preamb + *TikzAB(Ar));
 std::string   res(res1 + post);
 //std::cout<<res1<<"\n";
  fichier <<res<<"\n";
  fichier.close();
  std::system("pdflatex -interaction nonstopmode fig.tex; rm fig.log; rm fig.tex; rm fig.aux; open fig.pdf");
  return;
}



// g++ -c SortieLatex.cpp
