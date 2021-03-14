#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int n;
int arr1[10000000];
int arr2[10000000];

int isEqual(void *a, void *b) {
  return ((*(int*)a>*(int*)b) ? 1 : 0);
}

void *function(void *arg) {
  qsort(arr2, n, sizeof(int), isEqual);
}

int main() {
  scanf(" %d", &n);
  pthread_t tid;
  for(int i=0; i<n; i++)
    scanf(" %d", &arr1[i]);
  for(int i=0; i<n; i++)
    scanf(" %d", &arr2[i]);

  pthread_create(&tid, NULL, &function, NULL);
  qsort(arr1, n, sizeof(int), isEqual);

  pthread_join(tid, NULL);

  for(int i=0; i<n; i++)
    if(arr1[i]!=arr2[i]) {
      printf("Diferentes\n");
      exit(0);
    }
  printf("Mesmos elementos\n");
  return 0;
}