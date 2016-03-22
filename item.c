/* Directivas de pre-compilador*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "item.h"


/* CONSTRUTORES */

char* NEWmsg (){
  int i;
  char* msg = (char*)malloc(DIM*sizeof(char));
  getchar();
  for (i=0; (msg[i]=getchar())!=EOF && msg[i]!='\n' && i<DIM; i++);
  msg[i]='\0';
  msg = (char*)realloc(msg, i+1*sizeof(char));
  return msg;
}


Item NEWitem(int emissor, int recetor, char* msg){
  Item novo = (Item)malloc(sizeof(struct mensagem));
  novo->emissor = emissor;
  novo->recetor = recetor;
  novo->mensagem = msg;
  return novo;
}


/* SELETORES */

int RECETOR(struct mensagem item){
  return item.recetor;
}

int EMISSOR(struct mensagem item){
  return item.emissor;
}

char* MENSAGEM(struct mensagem item){
  return item.mensagem;
}


/* TESTES */

int COMPARAmsg (const void * c, const void * d){
  Item a = (Item) c;
  Item b = (Item) d;
  

  if (strcmp(a->mensagem, b->mensagem)<0)
    return -1;

  if (strcmp(a->mensagem, b->mensagem)>0)
    return 1;

  else{
    if  (a->emissor<b->emissor)
      return -1;
    else
      return 1;
  }
}


