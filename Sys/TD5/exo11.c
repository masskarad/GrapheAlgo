#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
   system("ls -l");
   chmod("a.out", S_IXOTH);
   return 0;
 }
