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
  
    FILE* fi;
    fi=fopen("novel.txt","r");
    
    while(fgets(c,256,fi) != NULL){
    	if(strstr(c,kata) != NULL){
	    jumlah++;
	}
    }    
    printf("%s : %d",kata,jumlah);
    fclose(fi);

    return NULL;
}

int main(int argc, char *argv[])
{
    
    return 0;
}
