#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "Pessoa.h"


main ()
{
	//Apontador para a estrutura pessoa -struct pessoa-
	Pessoa p;

	//Alocar estrutura pessoa -struct pessoa- em memória -heap-
	p = (Pessoa) malloc (sizeof (struct pessoa));
	//Aceder e alterar o campo id -int-
	p->id = 1;
	//Aceder e alocar -heap- espaço para a string -char *-
	p->nome = strdup ("Miguel");
	//-stdout-: Conteúdo da estrutura pessoa p
	printf ("%d %s\n", p->id, p->nome);
	//Libertar memória -heap- reservada para a string -char *-
	free (p->nome);
	//Libertar memória -heap- reservada para a estrutura -struct pessoa-
	free (p);
}
