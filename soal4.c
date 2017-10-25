#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
/*******************************************************
*compile dengan cara gcc -pthread -o [output] input.c *
*******************************************************/

pthread_t tid[100];


void* faktorial(void *arg)
{
    int i, iter=1;
    int *num=(void *)arg;
    pthread_t id=pthread_self();
  
        for(i=*num;i>1;i--)
        {
            iter*=i;
        }
	printf("Hasil %d! = %d\n",*num,iter);
  
    return NULL;
}
int main(void)
{
    int i=0,j=0,angka,N[100];
    char tes;
    int err;
    while(1){
    	scanf("%d",&angka);
	scanf("%c",&tes);
	N[j]=angka;
	j++;
	if(tes=='\n') break;
    }
    while(i<j)
    {
        err=pthread_create(&(tid[i]),NULL,&faktorial,&N[i]);//membuat thread
        if(err!=0)//cek error
        {
            printf("\n can't create thread : [%s]",strerror(err));
        }
        else
        {
            //printf("\n create thread success");
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
