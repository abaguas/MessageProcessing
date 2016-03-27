/* Directivas de pre-compilador*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"


/* Funcoes auxiliares*/

void imprime(Link link){
  if(link_null(link)) {
    printf("NULL\n");
  }
  else {
    printf("%d %d %s\n", recetor(link_structmsg(link)), emissor(link_structmsg(link)), mensagem(link_structmsg(link)));
  }     
}


Item vetoriza (Link head, int size){
  int i;
  struct mensagem msg;
  Link headaux = head;
  Item tabela = (Item) malloc(size*sizeof(struct mensagem));

  for (i=0; i<size; i++){
    msg = link_structmsg(headaux);
    tabela[i] = msg;
    headaux=next(headaux);
  }
  return tabela;
}


char* new_command (){
  char* command=(char*)malloc(11*sizeof(char));
  return command;
}


/* Funcoes principais */

void nova_mensagem(Queue controlo){
  Item item;
  Link novo;
  int recetor, emissor;
  char* msg;
  
  scanf("%d",&emissor);
  scanf("%d",&recetor);
  msg=new_msg();
  item=new_item(emissor, recetor, msg);
  novo=new_link(item);
  queue_put(pos_controlo(controlo,recetor), novo);
}


void processa_mensagem(Queue controlo){
   
  int recetor;
  Link link;
  Queue pos;

  scanf("%d",&recetor);
  pos = pos_controlo(controlo, recetor);

  if (queue_empty(pos)){
    link = NULL;
  }
  else {
    link = queue_get(pos);
  }
  imprime(link);
  if (link != NULL){
    delete_link(link);
  }
}


void lista(Queue controlo, int recetor){
  Link link;
  Queue pos = pos_controlo(controlo, recetor);
  int i, siz = size(pos);
  
  link = head(pos);
  if (siz==0){
    imprime(link);
  }
  else{
    for (i=0; i<siz; i++){
      imprime(link);
      link=next(link);
    }
  }
}


void sort(Queue controlo){
  int receiver, siz, i;
  Item tabela;
  Queue pos;

  scanf("%d",&receiver);
  pos= pos_controlo(controlo, receiver);
  if (queue_empty(pos)){
    printf("NULL\n");
  }
  else{
    siz=size(pos);
    tabela = vetoriza(head(pos), siz);
    qsort(tabela, siz, sizeof(struct mensagem), compara_msg);
    for (i=0;i<siz;i++) {
      printf("%d %d %s\n", recetor(tabela[i]), emissor(tabela[i]), mensagem(tabela[i]));
    }
    free(tabela);
  }
}


void apaga(Queue controlo, int recetor){
  int i, siz;
  Queue pos;

  pos=pos_controlo(controlo, recetor);
  siz=size(pos);

  if (~ queue_empty(pos)){
    for(i=0; i<siz; i++){
      queue_free(pos);
    }
  queue_init(pos);
  }
}


void sai(Queue controlo, int utilizadores){
  int i;
  
  for(i=0; i<utilizadores; i++){
    apaga(controlo, i);
  }       
  delete_queue(controlo);
}
