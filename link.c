/* Directivas de pre-compilador*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "link.h"


/* CONSTRUTORES */

Link NEWlink(Item item){
  Link novo = (Link)malloc(sizeof(struct node));

  novo->item=item;
  novo->next=NULL;
  return novo;
}


/* SELETORES */

Link NEXT(Link link){
  return link->next;
}

int RECETOR2(Link link){
  return link->item->recetor;
}

int EMISSOR2(Link link){
  return link->item->emissor;
}

char* MENSAGEM2(Link link){
 return link->item->mensagem;
}

struct mensagem LINKstructmsg (Link link){
  return *(link->item);
}


/* MODIFICADORES */

void DELETEstring(char* string){
  free(string);
}

void DELETEitem(Item item){
  DELETEstring(item->mensagem);
  free(item);
}

void DELETElink(Link link){
  DELETEitem(link->item);
  free(link);
}


/* TESTES*/

int LINKnull(Link link){
  return (link==NULL);
}


