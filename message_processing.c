/* Directivas de pre-compilador*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Projeto2_abstrato.h"


/* Funcoes auxiliares*/

Item vetoriza (Link head, int size){
  int i;
  struct mensagem msg;
  Link headaux;
  Item tabela = (Item) malloc(size*sizeof(struct mensagem));
  
  headaux=head;

  for (i=0; i<size; i++){
    msg = LINKstructmsg(headaux);
    tabela[i] = msg;
    headaux=NEXT(headaux);
  }

  return tabela;

}


Queue POScontrolo(Queue controlo, int recetor){
  return controlo+recetor;

}


char* NEWcommand (){
  char* command=(char*)malloc(11*sizeof(char));
  return command;

}


/* Funcoes principais */

void imprime(Link link){

  if(LINKnull(link))
    printf("NULL\n");
  else
    printf("%d %d %s\n", RECETOR2(link), EMISSOR2(link), MENSAGEM2(link));
       
}


void novaMensagem(Queue controlo){
  
  Item item;
  Link novo;
  int recetor, emissor;
  char* msg;
  
  scanf("%d",&emissor);

  scanf("%d",&recetor);

  msg=NEWmsg();

  item=NEWitem(emissor, recetor, msg);

  novo=NEWlink(item);
  
  QUEUEput(POScontrolo(controlo,recetor), novo);

}


void sort(Queue controlo){
  
  int recetor, size, i;
  Item tabela;
  Queue pos;

  scanf("%d",&recetor);

  pos= POScontrolo(controlo, recetor);
  
  if (QUEUEempty(pos))
    printf("NULL\n");
  
  else{

  size=SIZE(pos);

  tabela = vetoriza(HEAD(pos), size);

  qsort(tabela, size, sizeof(struct mensagem), COMPARAmsg);

  for (i=0;i<size;i++)
    printf("%d %d %s\n",RECETOR(tabela[i]), EMISSOR(tabela[i]), MENSAGEM(tabela[i]));

  free(tabela);
  
  }

}


void lista(Queue controlo, int recetor){
  Link link;
  Queue pos = POScontrolo(controlo, recetor);
  int i, size = SIZE(pos);
  
  link = HEAD(pos);
  
  if (size==0)
    imprime(link);
  else
    for (i=0; i<size; i++){
      imprime(link);
      link=NEXT(link);
  }

}


void processaMensagem(Queue controlo){
   
  int recetor;
  Link link;
  Queue pos;

  scanf("%d",&recetor);

  pos = POScontrolo(controlo, recetor);

  link = QUEUEcheck(pos);

  imprime(link);

  if (link!=NULL){
    DELETElink(link);
  }

}


void apaga(Queue controlo, int recetor){
  int i, size;
  Queue pos;

  pos=POScontrolo(controlo, recetor);
  
  size=SIZE(pos);

  if (~ QUEUEempty(pos)){

    for(i=0; i<size; i++)
      QUEUEfree(pos);

  QUEUEinit(pos);

  }

}


void sai(Queue controlo, int utilizadores){
  int i;
  
  for(i=0; i<utilizadores; i++){
    apaga(controlo, i);

  }       

  DELETEqueue(controlo);
}


