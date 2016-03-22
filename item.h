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

char* NEWmsg (); /* le a mensagem enviada e retorna uma cadeia de caracteres com a mesma */

Item NEWitem(int emissor, int recetor, char* msg); /* recebe um emissor, um recetor e uma mensagem, e retorna um Item preenchido */


/* SELETORES */

int RECETOR(struct mensagem item); /* recebe uma struct mensagem e retorna o seu recetor */

int EMISSOR(struct mensagem item); /* recebe uma struct mensagem e retorna o seu emissor */

char* MENSAGEM(struct mensagem item); /* recebe uma struct mensagem e retorna a sua mensagem */


/* TESTES */

int COMPARAmsg (const void * c, const void * d); /* recebe dois items e os compara retornando -1 caso d seja maior e 1 caso c seja maior */


