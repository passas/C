#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "pessoa.h"


//Estrutura que define a entidade computacional -pessoa-
struct pessoa
{
	int id;
	char *nome;
};


//Função que desstrói a entidade computacional -pessoa- em memória -heap-
void free_Pessoa (Pessoa p)
{
	//Libertar memória -heap- reservada para a string -char *-
	free (p->nome);
	//Libertar memória -heap- reservada para a estrutura -struct pessoa-
	free (p);
}


//Função que constrói a entidade computacional -pessoa- em memória -heap-
Pessoa criar_Pessoa (int id, char *nome)
{
	//Apontador para a estrutura pessoa -struct pessoa-
	Pessoa p;

	//Alocar estrutura pessoa -struct pessoa- em memória -heap-
	p = (Pessoa) malloc (sizeof (struct pessoa));
	//Aceder e alterar o campo id -int-
	p->id = id;
	//Aceder e alocar -heap- espaço para a string -char *-
	p->nome = strdup (nome);

	//Devolver apontador
	return p;
}


//Função que constrói em memória -heap- a string relativa ao conteúdo da entidade computacional -pessoa-
char *str_Pessoa (Pessoa p)
{
	//Apontador para uma string em memória -heap-
	char *str;

	//Alocar em memória -heap- espaço para computar os caractéres da struct pessoa
	str = malloc (sizeof (char) * (strlen(p->nome) + 64) + 1); //comprimento da string + digitos (fator cagaço) + '\0'
	//Imprimir caractéres na string
	sprintf (str, "%d %s", p->id, p->nome);

	//Devovler apontador
	return str;
}
