#ifndef PESSOA_H
#define PESSOA_H


//Estrutura que define a entidade computacional -pessoa-
typedef struct pessoa *Pessoa;


//Função que desstrói a entidade computacional -pessoa- em memória -heap-
void free_Pessoa (Pessoa p);


//Função que constrói a entidade computacional -pessoa- em memória -heap-
Pessoa criar_Pessoa (int id, char *nome);


//Função que constrói em memória -heap- a string relativa ao conteúdo da entidade computacional -pessoa-
char *str_Pessoa (Pessoa p);


#endif
