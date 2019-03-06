#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

void main() 
{ 

    pid_t value_state_of_creation = fork(); 

    if (value_state_of_creation < 0) {
          printf("Creation failed ..");
    }else if (value_state_of_creation > 0 ){
          printf("I'm the father , my pid is : %d \n",(int)getpid());
    }else{
          printf("I'm the son , my pid is : %d \n",(int)getpid());
    }

} 