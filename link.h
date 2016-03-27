/* Directivas de pre-compilador */

#include "item.h"

/* Definicao de tipos */

typedef struct node{
  Item item;
  struct node* next;
}*Link;


/* Prototipos */


/* CONSTRUTORES */

Link new_link(Item item); /* recebe um Item e retorna um Link preenchido */


/* SELETORES */

Link next(Link link);  /* recebe um Link e retorna o seu next */

struct mensagem link_structmsg (Link link); /* recebe um Link e retorna o struct mensagem apontado pelo seu Item */


/* MODIFICADORES */ 

void delete_link(Link link); /* recebe um Link e elimina-o */


/* TESTES */

int link_null(Link link); /* recebe um Link e verifica se e igual a NULL */

