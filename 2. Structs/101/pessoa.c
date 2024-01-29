#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct pessoa
{
	int id;
	char *nome;
};

typedef struct pessoa Pessoa;


main ()
{
	//Variável de apoio à estrutura pessoa -struct pessoa-
	Pessoa p1;
	//Apontador para a estrutura pessoa -struct pessoa *-
	Pessoa *p2, *p3;


	/* struct . */
	//Aceder e alterar o campo id -int-
	p1.id = 1;
	//Aceder e alocar -heap- espaço para a string -char *-
	p1.nome = strdup ("Miguel");
	//-stdout-: Conteúdo da estrutura pessoas p1
	printf ("%d %s\n", p1.id, p1.nome);
	//Libertar memória -heap- reservada para a string -char *-
	free (p1.nome);


	/* struct *(). */
	//Alocar estrutura pessoa -struct pessoa- em memória -heap-
	p2 = (struct pessoa *) malloc (sizeof (struct pessoa));
	//Aceder e alterar o campo id -int-
	(*p2).id = 2;
	//Aceder e alocar -heap- espaço para a string -char *-
	(*p2).nome = strdup ("Miguelito");
	//-stdout-: Conteúdo da estrutura pessoas p2
	printf ("%d %s\n", (*p2).id, (*p2).nome);
	//Libertar memória -heap- reservada para a string -char *-
	free ((*p2).nome);
	//Libertar memória -heap- reservada para a estrutura -struct pessoa-
	free (p2);


	/* struct -> */
	//Alocar estrutura pessoa -struct pessoa- em memória -heap-
	p3 = (Pessoa *) malloc (sizeof (struct pessoa));
	//Aceder e alterar o campo id -int-
	p3->id = 3;
	//Aceder e alocar -heap- espaço para a string -char *-
	p3->nome = strdup ("Miguelão");
	//-stdout-: Conteúdo da estrutura pessoas p3
	printf ("%d %s\n", p3->id, p3->nome);
	//Libertar memória -heap- reservada para a string -char *-
	free (p3->nome);
	//Libertar memória -heap- reservada para a estrutura -struct pessoa-
	free (p3);
}
