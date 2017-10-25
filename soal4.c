#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
/*******************************************************
*compile dengan cara gcc -pthread -o [output] input.c *
*******************************************************/

pthread_t tid[3];//inisialisasi array untuk menampung thread dalam kasus ini ada 3 thread


void* faktorial(void *arg)
{
    int i, iter=1;
    int *num=(int*) arg;
    pthread_t id=pthread_self();
  
   // if(pthread_equal(id,tid[0]))//thread untuk menjalankan counter
   // {
        for(i=*num;i>0;i--)
        {
            iter*=i;
        }
	printf("Hasil %d! = %d\n",*num,iter);
   // }
   // else
   // {
        
   // }
    return NULL;
}
int main(void)
{
    int i=0,N[]={2,3,4};
    int err;
    while(i<3)//looping membuat thread 3x
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
    while(i<3)
	{
	    pthread_join(tid[i],NULL);
	    i++;
	}
    return 0;
}
