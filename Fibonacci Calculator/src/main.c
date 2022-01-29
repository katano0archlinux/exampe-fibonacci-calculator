#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct numbers
{
	unsigned long int *n;
};

void calculateFibonacci( struct numbers* number )
{
	unsigned long int a, b, index;
	a = 0;
	b = 1;
	index = 1;

	while ( a < *number->n )
	{
		b = a + b;
		a = b - a;

		if ( a <= *number->n )
			printf( "%ld.argument => %ld\n", index, a );
		
		++index;
	}
}

int main( void )
{
	// Structure(s)
	struct numbers *num = ( struct numbers* )malloc( sizeof( struct numbers ) );

	// Variable(s)
	unsigned long int limit;
	
	printf( "Type here limit: " );
	scanf( "%ld", &limit );
	
	num->n = &limit;

	calculateFibonacci( num );
	free( num );

	return ( EXIT_SUCCESS );
}
