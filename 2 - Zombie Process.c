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
          printf("I'm the father , i want to sleep 40 secondes ...\n");
          sleep(40);
          printf("I'm te father ===> Now , i'm a ZOMBIE PROCESS");          
    }else{
          printf("I'm the son , i'm over \n");
          exit(0);
          // all instructions will not run here because the proc son is over ..
          printf("Test the over of proc son ..\n");

    }

} 