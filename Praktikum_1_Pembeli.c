#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int *MP4A1, *PM2_V1, *SPR_3, *SS2_V5, *SPG1_V3, *MINE;

void display(){
	printf("Toko\n");
	printf("Stock MP4A1 %d\n",*MP4A1);
	printf("Stock PM2_V1 %d\n", *PM2_V1);
	printf("Stock SPR_3 %d\n", *SPR_3);
	printf("Stock SS2_V5 %d\n", *SS2_V5);
	printf("Stock SPG1_V3 %d\n", *SPG1_V3);
	printf("Stock MINE %d\n", *MINE);
}

void beli(){
	char key[10];
	int tambah;

	scanf("%s %d",key,&tambah);

	if (!strcmp(key,"MP4A1") && *MP4A1-tambah>=0) *MP4A1-=tambah;
	else if (!strcmp(key,"PM2_V1") && *PM2_V1-tambah>=0) *PM2_V1-=tambah;
	else if (!strcmp(key,"SPR_3") && *SPR_3-tambah>=0) *SPR_3-=tambah;
	else if (!strcmp(key,"SS2_V5") && *SS2_V5-tambah>=0) *SS2_V5-=tambah;
	else if (!strcmp(key,"SPG1_V3") && *SPG1_V3-tambah>=0) *SPG1_V3-=tambah;
	else if (!strcmp(key,"MINE") && *MINE-tambah>=0) *MINE-=tambah;
	else printf("barang di stock tidak cukup\n");
}

int main () {

	int shmid = shmget(1, sizeof(int), IPC_CREAT | 0666);
    MP4A1 = shmat(shmid, NULL, 0);

	shmid = shmget(2, sizeof(int), IPC_CREAT | 0666);
    PM2_V1 = shmat(shmid, NULL, 0);

	shmid = shmget(3, sizeof(int), IPC_CREAT | 0666);
    SPR_3 = shmat(shmid, NULL, 0);

	shmid = shmget(4, sizeof(int), IPC_CREAT | 0666);
    SS2_V5 = shmat(shmid, NULL, 0);

	shmid = shmget(5, sizeof(int), IPC_CREAT | 0666);
    SPG1_V3 = shmat(shmid, NULL, 0);

	shmid = shmget(6, sizeof(int), IPC_CREAT | 0666);
    MINE = shmat(shmid, NULL, 0);

	int play = 1;
	int key;
	while(play){
		printf("Menu\n");
		printf("1. Display Stock\n");
		printf("2. Beli\n");

		scanf("%d",&key);

		if (key == 1)display();
		else if (key == 2)beli();
	}
}
