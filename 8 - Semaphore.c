#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
#include <string.h>

sem_t mutex; 
int counter; 
  
void* theard_of_process(void* arg) 
{ 
   char OrderProc[] = "Other" ;
   counter+=1 ; 
   if (counter < 2 ) {
          strcpy(OrderProc,"Some");
   }
    //wait 
    sem_wait(&mutex); 
    printf("\n%s theard of process Entered..\n",OrderProc); 
  
    //critical section 
    sleep(5); 
      
    //signal 
    printf("\nJust Exiting...\n"); 
    sem_post(&mutex); 
} 
  
  
int main() 
{ 
    sem_init(&mutex, 0, 1); 
    pthread_t t1,t2; 
    pthread_create(&t1,NULL,theard_of_process,NULL); 
    sleep(2); 
    pthread_create(&t2,NULL,theard_of_process,NULL); 
    pthread_join(t1,NULL); 
    pthread_join(t2,NULL); 
    sem_destroy(&mutex); 
    return 0; 
} 