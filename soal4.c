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
    int i=0,j=0,angka,N[100];
    int err;
    if(argc<2) printf("Belum ada angka yang dimasukkan\n");
    while(1){
    	if(argv[j+1] == NULL) break;
	angka=atoi(argv[j+1]);
	N[j]=angka;
	j++;
    }
    while(i<j)
    {
        err=pthread_create(&(tid[i]),NULL,&faktorial,&N[i]);//membuat thread
        if(err!=0)//cek error
        {
            printf("\n can't create thread : [%s]",strerror(err));
        }
        i++;
    }
    i=0;
    while(i<j)
    {
	pthread_join(tid[i],NULL);
	i++;
    }
    return 0;
}
