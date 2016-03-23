/* Directivas de pre-compilador*/

#include "queue.h"

/* Funcoes auxiliares */

void imprime(Link link); /* recebe um Link e retorna o recetor, o emissor e a mensagem nele contidos */

Item vetoriza (Link head, int size); /* funcao que coloca as struct mensagem de um utilizador num vetor e o retorna */

char* new_command (); /* retorna um vetor de caracteres com 11 posicoes */


/* Funcoes principais */

void nova_mensagem(Queue controlo); /* recebe uma Queue e le uma struct mensagem guardando-a na posicao correta */

void processa_mensagem(Queue controlo); /* recebe uma Queue, le o recetor e, imprime e elimina a primeira mensagem da fila desse recetor */

void lista(Queue controlo, int recetor); /* recebe uma Queue um 'recetor' e imprime as mensagens desse recetor por ordem de chegada */

void sort(Queue controlo); /* recebe uma Queue, le o recetor e imprime as mensagens desse recetor por ordem alfabetica */

void apaga(Queue controlo, int recetor); /* recebe uma Queue e um 'recetor' e elimina todas as mensagens da fila desse recetor */

void sai(Queue controlo, int utilizadores); /* recebe uma Queue e o numero de utilizadores, elimina as filas de mensagens de todos os utilizadores e elimina a Queue */


