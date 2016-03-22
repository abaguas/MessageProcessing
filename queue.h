/* Directivas de pre-compilador */

#include "link.h"

/* Definicao de tipos */

typedef struct queue{
  Link head, tail;
  int size;
}*Queue;


/* Prototipos */


/* CONSTRUTORES */

Queue QUEUEinit_all(int utilizadores); /* recebe 'utilizadores' e retorna uma Queue com 'utilizadores' posicoes */

void QUEUEinit(Queue pos); /* recebe uma posicao do vetor de utilizadores e inicia-a */


/* SELETORES */

int SIZE(Queue pos); /* recebe uma posicao do vetor de utilizadores e retorna o seu size */

Link HEAD(Queue pos); /* recebe uma posicao do vetor de utilizadores e retorna a sua head */


/* MODIFICADORES */

Link QUEUEcheck(Queue pos); /* recebe uma posicao do vetor de utilizadores, verifica se há algum elemento a remover e chama a funcao QUEUEget (caso exista) ou NULL (caso contrario) */

Link QUEUEget(Queue pos); /* recebe uma posicao do vetor de utilizadores, retira o primeiro struct node da fila de mensagens, atualiza a head e retorna-o para ser imprimido */

void QUEUEfree(Queue pos); /* recebe uma posicao do vetor de utilizadores, elimina o primeiro struct node da lista de mensagens de um utilizador e atualiza a head*/

void DELETEqueue(Queue controlo); /*recebe uma Queue e elimina-a*/


/* TESTES */

int QUEUEempty(Queue pos); /* recebe uma posicao do vetor de utilizadores e verifica se esse utilizador nao recebeu mensagens */

void QUEUEput(Queue pos, Link novo); /* recebe uma posicao do vetor de utilizadores e um Link e coloca o struct node apontado pelo Link na fila de mensagens do utilizador */




