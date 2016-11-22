#include <stdio.h>

int main(int argc, char const *argv[]) {
  printf("%s test \n");
  execl("/bin/ls","ls","-l",NULL);
  return 0;
}
