// Synchronization of father and son processes

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>


void main(void)
{
    pid_t value_state_of_creation , ret_son , state ;


    printf("I'm the process father with pid %d \n",(int)getpid());
    value_state_of_creation = fork();
    switch(value_state_of_creation){
        case 0 :
            printf("\t\t\t\t********\n\t\t\t\t* FILS *\n\t\t\t\t********\n");
            printf("\t\t\t\tProc son with pid %d , the pid of my father is %d \n",(int)getpid(),(int)getppid());
            printf("\t\t\t\tI want to sleep 30 secondes ...\n");
            sleep(3);
            printf("\t\t\t\tI wake up , \n\t\t\t\tI finish my execution with EXIT(7)\n");
            exit(7);
        case -1 :
            printf("The fork failed");
            exit(2);
        default :
            printf("********\n* PERE *\n********\n");
            printf("Proc father with pid %d \nProc son with pid %d \n",(int)getpid(),value_state_of_creation);
            printf("I'm waiting for the end of my son ... \n");
            ret_son = wait(&state); // you can replace wait with the < WEXITSTATUS(state) > pre-processor .. 
            printf("My son with pid %d is over, \n His state is : %0x \n",ret_son,state); 

    }
}
