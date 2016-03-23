/* Directivas de pre-compilador */

#define DIM 501

/* Definicao de tipos */

typedef struct mensagem{
  int emissor;
  int recetor;
  char* mensagem;
}*Item;


/* Prototipos */


/* CONSTRUTORES */

char* new_msg (); /* le a mensagem enviada e retorna uma cadeia de caracteres com a mesma */

Item new_item(int emissor, int recetor, char* msg); /* recebe um emissor, um recetor e uma mensagem, e retorna um Item preenchido */


/* SELETORES */

int recetor(struct mensagem item); /* recebe uma struct mensagem e retorna o seu recetor */

int emissor(struct mensagem item); /* recebe uma struct mensagem e retorna o seu emissor */

char* mensagem(struct mensagem item); /* recebe uma struct mensagem e retorna a sua mensagem */


/* MODIFICADORES */ 

void delete_string(char* string); /* recebe uma cadeia de carateres e elimina-a */ 

void delete_item(Item item); /* recebe um Item e elimina-o */


/* TESTES */

int compara_msg (const void * c, const void * d); /* recebe dois items e compara-os retornando -1 caso d seja maior e 1 caso c seja maior */


