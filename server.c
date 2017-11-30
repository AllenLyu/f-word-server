#include <pthread.h>
#include "stdio.h"
#include <unistd.h> 

#define NUM 6
int a = 0;
pthread_mutex_t lock;
int main()
{
    void print_msg(void*);
    pthread_mutex_init(&lock,NULL);
    pthread_t t1,t2;
    pthread_create(&t1,NULL,(void*)print_msg,(void *)"t1\n");
    pthread_create(&t2,NULL,(void*)print_msg,(void *)"t2\n");
   
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);  
	printf("final a is %d \n",a);
}
void print_msg(void* m)
{
    char *cp=(char*)m;
	for(int i = 0;i<10000;i++){
        pthread_mutex_lock(&lock);
		a++;
        pthread_mutex_unlock(&lock);
	}
    
}