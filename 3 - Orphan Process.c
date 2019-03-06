#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h> 

int main() 
{
    printf("I'm the father , my pid is : %d \n",(int)getpid());
    pid_t value_state_of_creation = fork(); 

    if (value_state_of_creation < 0) {
          printf("Creation failed ..");
    }else if (value_state_of_creation > 0 ){
          printf("I'm the father , i'm over \n");
          exit(0);
          // all instructions will not run here because the proc son is over ..
          printf("Test the over of proc father ..\n");     
    }else{
          printf("I'm the son , i want to sleep 40 secondes ...\n");
          sleep(4);
          printf("I'm the son .. I wake up ... \n");
          // now the father of the proc son here is the proc grand-father of all procs ( INIT ) .. 
    }

} 
  