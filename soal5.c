#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[100];

void* cari(void *arg)
{
    int jumlah=0;
    char c[256],kata[256];
    strcpy(kata,arg);

    FILE *fi;
    fi=fopen("Novel.txt","r");

    while(fscanf(fi,"%s",c) != EOF){
   	if(strstr(c,kata) != NULL){
	   jumlah++;
	}
    }
    printf ("%s : %d\n",kata,jumlah);
    fclose(fi);
}

int main(int argc, char *argv[])
{
    int i=0;

    for(i=1;i<argc;i++)
    {
	pthread_create(&(tid[i]),NULL,&cari,(void*)argv[i]);
    }
   
    for(i=0;i<argc;i++)
    {
	pthread_join(tid[i],NULL);
    }
    return 0;
}
