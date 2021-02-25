#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

int x = 0;

void handleLazy(int sig) {
  if(sig == SIGUSR1)
    printf("SIGUSR1 eh para aproveitar mais um pouco\n");
  else if(sig == SIGALRM && x<2) {
    printf("Ai que sono, quero dormir mais um pouco\n");
    x++;
  }
  else if(x==2) {
    printf("Os incomodados que se mudem, tchau\n");
    exit(0);
  }
}

int main() {
  signal(SIGUSR1, handleLazy);
  signal(SIGALRM, handleLazy);
  while(1)
    pause();
}