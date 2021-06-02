#include "myenv.h"
#include <stdio.h>

void usage(void)
{
	printf("Usage: env [OPTION]... [-] [NAME=VALUE]... [COMMAND [ARG]...]\n"
		"Set each NAME to VALUE in the environment and run COMMAND.\n");
	return;
}

void printEnv(void)
{
	for (char** env = environ; *env; env++)
	{
		char* thisEnv = *env;
		printf("%s\n", thisEnv);
	}
	return;
}

bool isEnvVar ( const char argument[] )
{
	for (; *argument; ++argument)
	{
		if ( *argument == '=' )
			return true;
	}
	return false;
}
