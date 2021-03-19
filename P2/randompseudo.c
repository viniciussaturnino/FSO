#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct test {
  int mi;
  int bi;
} Test;

int seed1, seed2, v1[100000], v2[100000], aux=0;
pthread_t tid1;
pthread_t tid2;
sem_t sid;

void initSemaphore() {
  sem_init(&sid, 0, 1);
}

void *insertVector1(void *a) {
  for(int i=0; i<100000; i++)
    v1[i] = rand_r(&seed1);
}


void *calcV1(void *a) {
  Test t = *((Test*)a);
  for(int i=0; i<100000; i++)
    if(v1[i]%t.mi==t.bi){
      sem_wait(&sid);
      aux++;
      sem_post(&sid);
    }
}

void *insertVector2(void *a) {
  for(int i=0; i<100000; i++)
    v2[i] = rand_r(&seed2);
}

void *calcV2(void *a) {
  Test t = *((Test*)a);
  for(int i=0; i<100000; i++)
    if(v2[i]%t.mi==t.bi){
      sem_wait(&sid);
      aux++;
      sem_post(&sid);
    }
}

void readSeeds() {
  Test t;
  while(scanf(" %d %d", &t.mi, &t.bi) != EOF) {
    pthread_create(&tid1, NULL, &calcV1, (void*)&t);
    pthread_create(&tid2, NULL, &calcV2, (void*)&t);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    printf("%d\n", aux);
    aux = 0;
  }
}

int main(void) {
  scanf(" %d %d", &seed1, &seed2);
  initSemaphore();
  pthread_create(&tid1, NULL, &insertVector1, NULL);
  pthread_create(&tid2, NULL, &insertVector2, NULL);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  readSeeds();
}