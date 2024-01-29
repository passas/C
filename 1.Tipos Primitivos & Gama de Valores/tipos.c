#include <stdio.h>
#include <limits.h>
#include <float.h>


main ()
{
	printf ("Tipo\t\tTamanho (bits)\t\t\tGama\n");

	putchar ('\n');
	//char
	printf ("char\t\t%ld\t\t\t[%d,%d]\n", sizeof(char), SCHAR_MIN, SCHAR_MAX);
	//short
	printf ("short\t\t%ld\t\t\t[%d,%d]\n", sizeof(short), SHRT_MIN, SHRT_MAX);
	//int
	printf ("int\t\t%ld\t\t\t[%d,%d]\n", sizeof(int), INT_MIN, INT_MAX);
	//long
	printf ("long\t\t%ld\t\t\t[%ld,%ld]\n", sizeof(long), LONG_MIN, LONG_MAX);
	//float
	printf ("float\t\t%ld\t\t\t[%e,%e]\n", sizeof(float), FLT_MIN, FLT_MAX);
	//double
	printf ("double\t\t%ld\t\t\t[%e,%e]\n", sizeof(double), DBL_MIN, DBL_MAX);
	//long double
	printf ("long double\t%ld\t\t\t[%Le,%Le]\n", sizeof(long double), LDBL_MIN, LDBL_MAX);
	
	
	putchar ('\n');
	//unsigned char
	printf ("unsigned char\t%ld\t\t\t[0,%d]\n", sizeof(unsigned char), UCHAR_MAX);
	//unsigned short
	printf ("unsigned short\t%ld\t\t\t[0,%d]\n", sizeof(unsigned short), USHRT_MAX);
	//unsigned long
	printf ("unsigned long\t%ld\t\t\t[0,%ld]\n", sizeof(unsigned long), ULONG_MAX);
	
	putchar ('\n');
	//apontador
	printf ("(void *)\t%ld\n", sizeof(void *));
}
