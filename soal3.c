#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>


int hp_lohan;
int hp_kepiting;

int play;

void* lohan(void* args) {
	while(play){
		sleep(10);
		hp_lohan-=15;
		printf("lohan %d\n",hp_lohan);
	}
}

void* kepiting(void* args) {
	while(play){
		sleep(20);
		hp_kepiting-=10;
		printf("kepiting %d\n",hp_kepiting);
	}
}

int main () {

	int key;

	hp_lohan = 100;
	hp_kepiting = 100;

   	pthread_t tid[2];
	pthread_create(tid+0, NULL, &lohan, NULL);
 	pthread_create(tid+1, NULL, &kepiting, NULL);
	
	play=1;

	printf("Beri makan :\n");
	printf("1. Lohan\n");
	printf("2. Kepiting\n");
	while(play){
		if (hp_lohan>0 && hp_kepiting>0 && hp_kepiting<101 && hp_lohan<101)scanf("%d",&key);
		else play = 0;
		if (key == 1)hp_lohan+=10;
		else if (key == 2)hp_kepiting+=10;
		printf("lohan %d\n",hp_lohan);
		printf("kepiting %d\n",hp_kepiting);
	}
	printf("Game Over\n");

	return 0;	
}
