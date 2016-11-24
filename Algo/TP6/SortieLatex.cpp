//SortieLatex.cpp

#include <iostream>
#include <fstream>
#include <sstream>

typedef int Valeur;

class SommetABR;

typedef SommetABR* ABR;

void SortieLatex(ABR Ar);

class SommetABR {
  protected:
  Valeur racine;
  ABR Pere,SAG, SAD;

  int hauteur,balanceGmoinsD;

  public:
  SommetABR(Valeur v);
  SommetABR(SommetABR& s);

 ABR remonterToutEnHaut();

  void GrefferSAG(ABR g);
  void GrefferSAD(ABR d);

  void SupprimerSAG();
  void SupprimerSAD();

  bool FeuilleP();

  void RemplacerPourLePerePar(ABR);

  friend std::string* TikzRecursABR(int ligne,int gauche, int droite, int numeroPere, int typeFils, ABR Ar);


};

std::string* TikzRecursABR(int ligne,int gauche, int droite, int numeroPere, int typeFils, ABR Ar);



std::string * TikzRecursABR(int ligne,int gauche, int droite, int numeroPere, int typeFils, ABR Ar){
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
    if (Ar->SAG) stres+=*TikzRecursABR(ligne -1 ,gauche,mil-1, numero,0,Ar->SAG);
    if (Ar->SAD) stres+=*TikzRecursABR(ligne - 1,mil+1,droite, numero,1,Ar->SAD);
 }
  return new std::string(stres);
}

std::string * TikzABR(ABR Ar){
  return TikzRecursABR(1,1,10,1, -1,Ar);
}

 void SortieLatex(ABR Ar){
 std::ofstream fichier("fig.tex", std::ios::out | std::ios::trunc);
 std::string preamb ("\\documentclass[a4paper]{article} \n \\usepackage{tikz} \n \\begin{document} \n \\begin{tikzpicture}\n");
  std::cout<<preamb<<"\n";
std::string post("\\end{tikzpicture}\n  \\end{document} \n");
  std::cout<<post<<"\n";
 std::cout<<*TikzABR(Ar)<<"\n";
std::string   res1(preamb + *TikzABR(Ar));
 std::string   res(res1 + post);
 //std::cout<<res1<<"\n";
  fichier <<res<<"\n";
  fichier.close();
  std::system("pdflatex -interaction nonstopmode fig.tex; rm fig.log; rm fig.tex; rm fig.aux; open fig.pdf");
  return;
}



// g++ -c SortieLatex.cpp
