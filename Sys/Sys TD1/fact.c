#include <stdio.h>
#include <stdlib.h>

int factorielle(int exp){
	if (exp == 1)
		return 1;
	else 
		return exp * factorielle(exp -1);
}

int main(int argc, char *argv[]){
	int f = factorielle(3);
	printf("%d\n", f);
	return 0;
}


