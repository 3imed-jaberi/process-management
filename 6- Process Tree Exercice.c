/*
Sorry the exercice in french :'( < you can translate .. > : 
Ecrire un programme C qui permet d’obtenir l’arborescence des processus
suivante :
- Le premier processus fils A exécute « ls ».
- Le deuxième processus fils B exécute « ps -e ».
- Le troisième processus fils C crée un autre processus fils D.
- Le processus C doit attendre la mort de D et affiche un message indiquant la fin de D.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void main(){
          pid_t i,j,k, n, pid,s;
          i=fork();
          if (i==0){
                    execlp("ls", NULL); 
          }
          if (i>0)
                    j=fork();
                    if (j==0){
                                execlp("ps","-e", NULL); 
                              }
                    if (j>0)
                              k=fork();
                              if (k==0) {
                                          n = fork();
                                          if (n>0){
                                                  pid=wait(&s);
                                                  printf("Le petit fils de pid %d est mort \n", pid); 
                                          }else if (n==0){
                                                            exit(1); 
                                          }
                                        }
} 