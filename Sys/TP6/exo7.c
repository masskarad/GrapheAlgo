#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  struct stat buf;
  if (stat(argv[0],&buf) >= 0){
    int size = buf.st_size;
    printf("%d\n",size);
  }
  return 0;
}
