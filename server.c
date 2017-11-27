#include <pthread.h>
#include "stdio.h"
#include <unistd.h> 

#define NUM 6
int main()
{
    void print_msg(void*);
   
    pthread_t t1,t2;
    pthread_create(&t1,NULL,(void*)print_msg,(void *)"hello,");
    pthread_create(&t2,NULL,(void*)print_msg,(void *)"world!\n");
   
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);  
}
void print_msg(void* m)
{
    char *cp=(char*)m;
    int i;
    for(i=0;i<NUM;i++)
    {
        printf("%s",cp);
		sleep(1);
    }
}