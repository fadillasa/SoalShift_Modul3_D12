#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int mines[20];
int turn;
int player1,player2; // score

void* display_score(void* args){
	system("clear");
	printf("Score :\n");
	printf("Player1 : %d\n",player1);
	printf("Player2 : %d\n\n",player2);
}

void* put_bomb(void* args){
	pthread_t tid[2];
	int i,key,n;

	//display_score();
	pthread_create(tid+0, NULL, &display_score, NULL);
	pthread_join(tid[0], NULL);

	printf("Player%d Putting the Bomb\n",turn);
	printf("How many bomb do you want to put : ");

	scanf("%d",&n); // banyaknya bomb	
	for (i=0;i<n;i++){
		scanf("%d",&key);
		mines[key]=1;
	}
}

void* guess_bomb(void* args){
	pthread_t tid[2];
	int key,i;

	//display_score();
	pthread_create(tid+0, NULL, &display_score, NULL);
	pthread_join(tid[0], NULL);

	if (turn == 1) printf("Player2 Guessing the Bomb\n");
	else if (turn == 2) printf("Player1 Guessing the Bomb\n");

	for (i=0;i<4;i++){
		scanf("%d",&key);

		if (mines[key]) {
			if (turn == 1) player2++;
			else if (turn == 2)player1++;
		} else {
			if (turn == 1) player1++;
			else if (turn == 2) player2++;
		}
	}
}

void* init(void* args){
	int i;	
	for (i=0;i<16;i++)mines[i]=0;
}

int main () {
	pthread_t tid[2];	
	int play = 1;

	player1=0;
	player2=0;
	turn = 1;

	while(play){
//		init();
		pthread_create(tid+0, NULL, &init, NULL);
		pthread_join(tid[0], NULL);

//		put_bomb();
		pthread_create(tid+0, NULL, &put_bomb, NULL);
		pthread_join(tid[0], NULL);

//		guess_bomb();
		pthread_create(tid+0, NULL, &guess_bomb, NULL);
		pthread_join(tid[0], NULL);

		if (turn == 1) turn = 2;
		else if (turn == 2) turn = 1;
	}
}
