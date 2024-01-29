#include <stdio.h>
#include <stdlib.h>

//Headers relativos à entidade pessoa
#include "Pessoa.h"


main ()
{
	//Apontador para a struct pessoa
	Pessoa p;
	//Variável de suporte à construção da string relativa ao conteúdo da Pessoa
	char *str;

	//pessoas.h: Criar estrutura pessoa -p- e preencher os campos
	p = criar_Pessoa (1, "Miguel");

	//pessoas.h: Criar string com o conteúdo da estrutura pessoa -p-
	str = str_Pessoa (p);
	//-stdout-: Conteúdo da estrutura pessoa -p-
	printf ("%s\n", str);
	//Libertar string com o conteúdo da estrutura pessoa -p-
	free (str);

	//pessoas.h: Libertar memória -heap- reservada para a estrutura pessoa -p-
	free_Pessoa (p);
}
