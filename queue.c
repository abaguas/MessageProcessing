#define DIM 501

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"


/* CONSTRUTORES */

Queue QUEUEinit_all(int utilizadores){
  int i;
  Queue controlo = (Queue)malloc(utilizadores*sizeof(struct queue));
  for(i=0;i<utilizadores;i++)
      QUEUEinit(controlo+i);
  return controlo;
}

void QUEUEinit(Queue pos){
  pos->head=NULL;
  pos->tail=NULL;
  pos->size=0;
}


/* SELETORES */

int SIZE(Queue pos){
  return pos->size;
}

Link HEAD(Queue pos){
  return pos->head;
}


/* MODIFICADORES */

Link QUEUEcheck(Queue pos){
  if (QUEUEempty(pos))
    return NULL;
  else
    return QUEUEget(pos);
}

Link QUEUEget(Queue pos){ 
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

  /*atualiza o size e a tail (se necessário) da fila de mensagens*/

  if (QUEUEempty(pos))
    (pos->tail)=NULL;

  pos->size --;

  /*elimina o primeiro elemento da fila*/

  DELETElink(pos->head);

  /*atualiza a head*/

  pos->head=t;

  return link;
}

void QUEUEfree(Queue pos){ 
  Link solta = pos->head->next;

  DELETElink(pos->head);

  pos->head=solta;
}

void DELETEqueue(Queue controlo){
  free(controlo);
}


/* TESTES */

int QUEUEempty(Queue pos){ 
  return (pos->head==NULL);
}

void QUEUEput(Queue pos, Link novo){
  pos->size ++;
  if (QUEUEempty(pos)){
    pos->tail = novo;
    pos->head = novo;
  }
  else{
    pos->tail->next = novo;
    pos->tail = novo;
  }
}


