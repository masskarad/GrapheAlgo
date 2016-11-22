#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int dichotomie() {
  if () {

  }
}

int dichotomie_aux() {

}

int lirefichier() {

}

int main(int argc, char const *argv[]) {
  int fichier = open(p_nom_fichier, O_RDONLY);
	if(fichier == -1)
	{
		exit(1);
	}

	char buffer [128] = "";

	int nread = read(fichier, buffer, 128);

	if(nread == -1)
		exit(1);

  return 0;
}
