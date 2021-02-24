#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

int count = 0;

void handle_SIGTERM(int nsig) {
  printf("Recebi %d\n", nsig);
  if(count == 2) {
    count = 3;
    printf("Senha acionada\n");
  }
  else
    count = 0;
}

void handle_SIGUSR1(int nsig) {
  printf("Recebi %d\n", nsig);
  if(count == 3) {
    count = 4;
    printf("Tchau\n");
    exit(0);
  }
  else
    count = 0;
}

void handle_SIGUSR2(int nsig) {
  if(count == 1)
    count = 2;
  else
    count = 0;
  printf("Recebi %d\n", nsig);
}

void handle_SIGINT(int nsig) {
  printf("Recebi %d\n", nsig);
  count = 1;
}

int main() {
  signal(SIGTERM, handle_SIGTERM);
  signal(SIGUSR1, handle_SIGUSR1);
  signal(SIGUSR2, handle_SIGUSR2);
  signal(SIGINT, handle_SIGINT);
  while(1)
    pause();
}