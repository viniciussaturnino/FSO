#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>

int k,d, in2, fi2, d2, resp;

void* ob(void *a) {
		int	seed = in2;
		resp=0;
		for(int j=1;j<100000;j++)
			rand_r(&seed);
		if(rand_r(&seed)%8 == d)
			resp=in2;
}

void* c(void *a) {
	int in, fi;
	int seed;
	pthread_t tid;

	scanf("%d %d %d", &in, &fi, &d);

	for(int i=in;i<=fi;i++) {
		seed = i;
		in2 = i+1;
		pthread_create(&tid, NULL, &ob, NULL);
		for(int j=1;j<100000;j++)
			rand_r(&seed);
		if(rand_r(&seed)%8 == d)
			printf("%d\n", i);
		i++;
		pthread_join(tid,NULL);
		if(resp!=0)
			printf("%d\n", resp);
	}
}

int main(void) {
	pthread_t tid;
	pthread_create(&tid, NULL, &c, NULL);
	pthread_join(tid,NULL);
  return 0;
}
