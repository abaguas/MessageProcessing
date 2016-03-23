#define DIM 501

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"


/* CONSTRUTORES */

Queue queue_init_all(int utilizadores){

  int i;

  Queue controlo = (Queue)malloc(utilizadores*sizeof(struct queue));

  for(i=0;i<utilizadores;i++)
      queue_init(controlo+i);
  return controlo;

}

void queue_init(Queue pos){

  pos->head=NULL;
  pos->tail=NULL;
  pos->size=0;

}


/* SELETORES */

Queue pos_controlo(Queue controlo, int recetor){

  return controlo+recetor;

}


int size(Queue pos){

  return pos->size;

}


Link head(Queue pos){

  return pos->head;

}


/* MODIFICADORES */

void queue_put(Queue pos, Link novo){

  pos->size ++;

  if (queue_empty(pos)){
    pos->tail = novo;
    pos->head = novo;
  }

  else{
    pos->tail->next = novo;
    pos->tail = novo;
  }

}


Link queue_get(Queue pos){ 

  Link t;

  /*copia o primeiro elemento da fila em 'link'*/
  
  Link link = (Link)malloc(sizeof(struct node));

  link->item = (Item)malloc(sizeof(struct mensagem));

  link->item->mensagem = (char*)malloc(DIM*sizeof(char));

  strcpy(link->item->mensagem, (pos->head)->item->mensagem);

  link->item->recetor = (pos->head)->item->recetor;

  link->item->emissor = (pos->head)->item->emissor;

  link->next=NULL; 

  /*guarda o novo primeiro elemento da fila em 't'*/

  t = pos->head->next;

  /*elimina o primeiro elemento da fila*/

  delete_link(pos->head);

  /*atualiza a head*/

  pos->head=t;

  /*atualiza o size e a tail (se necessário) da fila de mensagens*/

  if (queue_empty(pos))
    (pos->tail)=NULL;

  pos->size --;

  return link;

}


void queue_free(Queue pos){ 

  Link solta = pos->head->next;

  delete_link(pos->head);

  pos->head=solta;

}


void delete_queue(Queue controlo){

  free(controlo);

}


/* TESTES */

int queue_empty(Queue pos){ 

  return (pos->head==NULL);

}

