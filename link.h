/* Directivas de pre-compilador */

#include "item.h"

/* Definicao de tipos */

typedef struct node{
  Item item;
  struct node* next;
}*Link;


/* Prototipos */


/* CONSTRUTORES */

Link NEWlink(Item item); /* recebe um Item e retorna um Link preenchido */


/* SELETORES */

Link NEXT(Link link);  /* recebe um Link e retorna o seu next */

int RECETOR2(Link link); /* recebe um Link e retorna o recetor do struct mensagem apontado pelo seu Item */

int EMISSOR2(Link link); /* recebe um Link e retorna o emissor do struct mensagem apontado pelo seu Item */

char* MENSAGEM2(Link link); /* recebe um Link e retorna a mensagem do struct mensagem apontado pelo seu Item */

struct mensagem LINKstructmsg (Link link); /* recebe um Link e retorna o struct mensagem apontado pelo seu Item */


/* MODIFICADORES */ 

void DELETEstring(char* string); /* recebe um Link e elimina a mensagem do struct mensagem apontado pelo seu Item */ 

void DELETEitem(Item item); /* recebe um Link e elimina o seu Item */

void DELETElink(Link link); /* recebe um Link e elimina-o */

/* TESTES */

int LINKnull(Link link); /* recebe um Link e verifica se e igual a NULL */



