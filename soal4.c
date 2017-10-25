#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[100];

void* faktorial(void *arg)
{
    int i, iter=1;
    int *num=arg;
  
    for(i=*num;i>1;i--)
    {
    	iter*=i;
    }
    printf("Hasil %d! = %d\n",*num,iter);
  
    return NULL;
}

int main(int argc, char *argv[])
{
    int i,angka,N[100];
    if(argc<2) printf("Belum ada angka yang dimasukkan\n");
    for(i=1;i<argc;i++)
    {
        N[i]=atoi(argv[i]);
	pthread_create(&(tid[i]),NULL,&faktorial,&N[i]);
    }
   
    for(i=0;i<argc;i++)
    {
	pthread_join(tid[i],NULL);
    }
    return 0;
}
