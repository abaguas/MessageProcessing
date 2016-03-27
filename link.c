/* Directivas de pre-compilador*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "link.h"


/* CONSTRUTORES */

Link new_link(Item item){
  Link novo = (Link)malloc(sizeof(struct node));

  novo->item=item;
  novo->next=NULL;
  return novo;
}


/* SELETORES */

Link next(Link link){
  return link->next;
}


struct mensagem link_structmsg (Link link){
  return *(link->item);
}


/* MODIFICADORES */

void delete_link(Link link){
  delete_item(link->item);
  free(link);
}


/* TESTES*/

int link_null(Link link){
  return (link==NULL);
}

