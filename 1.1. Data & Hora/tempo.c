#include <time.h>
#include <stdio.h>

main ()
{
	//Variável que regista os segundos desde uma época -1970-
	time_t tempo;
	//Apontador para uma estrutura com os campos temporais
	struct tm *estrutura;
	//Variáveis de auxílio à expressão do tempo via campos estruturais -struct tm-
	int ano, mes, dia;
	int hora, minuto, segundo;

	/* time_t */
	//Resgatar segundos desde -1970-
	tempo = time (NULL);

	//-stdout-: Formatar os dados temporais via API
	printf ("%s\n", ctime(&tempo));
	

	/* struct tm */
	//Criar uma estrutura temporal através dos segundos resgatados desde -1970-
	tempo = time (NULL);
	estrutura = localtime ( &tempo );

	//Retirar ano -desde 1900-
	ano = estrutura->tm_year + 1900;
	//Retirar mês -[0,11]-
	mes = estrutura->tm_mon + 1;
	//Retirar dia
	dia = estrutura->tm_mday;

	//Retirar hora
	hora = estrutura->tm_hour;
	//Retirar minuto
	minuto = estrutura->tm_min;
	//Retirar segundo
	segundo = estrutura->tm_sec;

	//-stdout-: Formatar a gosto
	printf("%d-%02d-%02d %02d:%02d:%02d\n", ano, mes, dia, hora, minuto, segundo);
}
