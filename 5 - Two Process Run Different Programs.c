// Father and son run different programs .. 
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

/* /usr/bin/ps  argement ... */ 

void main(int argc, char *argv[])
{
    pid_t value_state_of_creation , ret_son , state ;

    if(argc != 2) {
        printf("Use : %s_.c to run !\n",argv[0]);
        exit(1);  
    }

    printf("I'm the process father with pid %d i want to create son process \n",(int)getpid());
    value_state_of_creation = fork();
    switch(value_state_of_creation){
        case 0 :
            printf("Coucou ! i'm the son with pid %d \n",(int)getpid());
            printf("%d : Code be remplace with %s \n",(int)getpid(),argv[1]);
            /*
            //   execute and leave which means that a process will get executed
            //   and then terminated by execlp.
            */
            execlp(argv[1],argv[1],NULL);
            printf("%d : Erreur lors du exec \n",(int)getpid());
            exit(2);
        case -1 :
            printf("The fork failed");
            exit(3);
        default :
            /* THE FATHER WAIT THE OVER OF HIS SON .. */
            printf("Father with pid %d wait .. \n",(int)getpid()); 
            ret_son = wait(&state);
            printf("Proc son is : %d ",ret_son);
            printf(" ... His state is : %0x (hex) \n",state);
    
    }
}
