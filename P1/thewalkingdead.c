#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

pid_t fk;
int count = 0;

void handleZombie() {
  if(count == 0) {
    fk = fork();
    if(fk == 0)
      exit(0);
    count++;
  }
  else if(count == 1) {
      wait(NULL);
      count++;
  }
  else if(count > 1) {
    exit(0);
    count++;
  }
}

int main() {
  signal(SIGUSR1, handleZombie);
  signal(SIGUSR2, handleZombie);
  while(1)
    pause();
}