#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

char input[100];

void readInput() {
  if(scanf(" %s", input) == EOF)
    exit(0);
}

void handle_SIGUSR1() {
  readInput();
  if(strcmp(input, "Igor3k") == 0)
    printf("Certo\n");
  else
    printf("Erro\n");
}

void handle_SIGUSR2() {
  readInput();
  if(strcmp(input, "Monark") == 0)
    printf("Certo\n");
  else
    printf("Erro\n");
}

void handle_SIGINT() {
  readInput();
  if(strcmp(input, "Con1") == 0)
    printf("Certo\n");
  else
    printf("Erro\n");
}

void handle_SIGTERM() {
  readInput();
  if(strcmp(input, "Con2") == 0)
    printf("Certo\n");
  else
    printf("Erro\n");
}

void handle_SIGALRM() {
  readInput();
  if(strcmp(input, "Silencio") == 0)
    printf("Certo\n");
  else
    printf("Erro\n");
}

int main() {
  signal(SIGTERM, handle_SIGTERM);
  signal(SIGUSR1, handle_SIGUSR1);
  signal(SIGUSR2, handle_SIGUSR2);
  signal(SIGINT, handle_SIGINT);
  signal(SIGALRM, handle_SIGALRM);
  while(1)
    pause();
}