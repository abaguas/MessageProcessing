/* Directivas de pre-compilador*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Projeto2_abstrato.h"

int main()
{
    int utilizadores,flag, recetor;
    char* command;
    Queue controlo;  

    scanf("%d",&utilizadores);

    command=NEWcommand();

    controlo=QUEUEinit_all(utilizadores);

    /* Comandos do Programa */

    do {scanf("%s",command);
        flag=1;

        if (strcmp(command,"send")==0){

            /* Chama a funcao responsavel pela execucao do comando send */

            flag=0;
            novaMensagem(controlo);
        }

        if (strcmp(command,"process")==0){

            /* Chama a funcao responsavel pela execucao do comando process */

            flag=0;
            processaMensagem(controlo);
        }
           
        if (strcmp(command,"list")==0){

            /* Chama a funcao responsavel pela execucao do comando list */

            flag=0;
            scanf("%d",&recetor);
            lista(controlo, recetor);
        }
            
        if (strcmp(command,"listsorted")==0){

            /* Chama a funcao responsavel pela execucao do comando listsorted */

            flag=0;
	    sort(controlo);
            /*ainda nao esta feito*/
        }
          
        if (strcmp(command,"kill")==0){

            /* Chama a funcao responsavel pela execucao do comando kill */

            flag=0;
            scanf("%d",&recetor);
            apaga(controlo, recetor);
        }
	
	if (strcmp(command,"quit")==0)
	   flag=0;

	if (flag)
            printf("ERRO: Comando desconhecido\n");
        
    }while(strcmp(command,"quit")!=0);
    sai(controlo, utilizadores);
    DELETEstring(command);
    return 0;
}
