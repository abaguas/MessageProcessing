/* Directivas de pre-compilador*/

#include "queue.h"

/* Funcoes auxiliares */

Item vetoriza (Link head, int size); /* funcao que coloca as struct mensagem de um utilizador num vetor e o retorna */

Queue POScontrolo(Queue controlo, int recetor); /* recebe uma Queue e um inteiro e retorna uma Queue para a posicao 'recetor' de 'controlo' */

char* NEWcommand (); /* retorna um vetor de caracteres com 11 posicoes */


/* Funcoes principais */

void imprime(Link link); /* recebe um Link e retorna o recetor, o emissor e a mensagem nele contidos */

void novaMensagem(Queue controlo); /* recebe uma Queue e le uma nova mensagem guardando-a na posicao correta */

void sort(Queue controlo); /* recebe uma Queue, le o recetor e imprime as mensagens desse recetor por ordem alfabetica */

void lista(Queue controlo, int recetor); /* recebe uma Queue um 'recetor' e imprime as mensagens desse recetor por ordem de chegada */

void processaMensagem(Queue controlo); /* recebe uma Queue, le o recetor e, imprime e elimina a primeira mensagem da fila desse recetor */

void apaga(Queue controlo, int recetor); /* recebe uma Queue e um 'recetor' e elimina todas as mensagens da fila desse recetor */

void sai(Queue controlo, int utilizadores); /* recebe uma Queue e um inteiro (numero de utilizadores), elimina as filas de mensagens de todos os utilizadores e elimina a Queue */


