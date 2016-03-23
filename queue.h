/* Directivas de pre-compilador */

#include "link.h"

/* Definicao de tipos */

typedef struct queue{
  Link head, tail;
  int size;
}*Queue;


/* Prototipos */


/* CONSTRUTORES */

Queue queue_init_all(int utilizadores); /* recebe 'utilizadores' e retorna uma Queue com 'utilizadores' posicoes inicializadas */

void queue_init(Queue pos); /* recebe uma posicao do vetor de utilizadores e inicializa-a */


/* SELETORES */

Queue pos_controlo(Queue controlo, int recetor); /* recebe uma Queue e um inteiro e retorna uma Queue para a posicao 'recetor' de 'controlo' */

int size(Queue pos); /* recebe uma posicao do vetor de utilizadores e retorna o seu size */

Link head(Queue pos); /* recebe uma posicao do vetor de utilizadores e retorna a sua head */


/* MODIFICADORES */

void queue_put(Queue pos, Link novo); /* recebe uma posicao do vetor de utilizadores e um Link e coloca o struct node apontado pelo Link na fila de mensagens do utilizador */

Link queue_get(Queue pos); /* recebe uma posicao do vetor de utilizadores, retira o primeiro struct node da fila de mensagens, atualiza a head e retorna-o para ser imprimido */

void queue_free(Queue pos); /* recebe uma posicao do vetor de utilizadores, elimina o primeiro struct node da lista de mensagens de um utilizador e atualiza a head */

void delete_queue(Queue controlo); /* recebe uma Queue e elimina-a */


/* TESTES */

int queue_empty(Queue pos); /* recebe uma posicao do vetor de utilizadores e verifica se esse utilizador nao recebeu mensagens */


