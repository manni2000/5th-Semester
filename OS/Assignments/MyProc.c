#include<stdio.h>
#include<string.h>

int main( void )
{
	FILE *fp;
	char buffer[1000];
	int number;
	
	memset( buffer, '\0', sizeof(buffer) );
	 	
	fp = popen( "cat MyProc.c", "r" );
	if( fp == NULL )
	{
		printf("ERROR in POPEN !!!\n");
	}
	else
	{
		number = fread( buffer, sizeof(char), sizeof(buffer), fp );
		printf("TEST OUTPUT = %s\n",buffer);
	}
	return 0;
}