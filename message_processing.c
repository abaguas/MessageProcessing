/* Directivas de pre-compilador*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

int main(){

    int utilizadores,flag, recetor;
    char* command;
    Queue controlo;  

    scanf("%d",&utilizadores);

    command=new_command();

    controlo=queue_init_all(utilizadores);

    /* Comandos do Programa */

    do {scanf("%s",command);
        flag=1;

        if (strcmp(command,"send")==0){

            /* Chama a funcao responsavel pela execucao do comando send */

            flag=0;
            nova_mensagem(controlo);
        }

        if (strcmp(command,"process")==0){

            /* Chama a funcao responsavel pela execucao do comando process */

            flag=0;
            processa_mensagem(controlo);
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
    
    delete_string(command);
    
    return 0;

}
