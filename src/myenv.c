#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void usage()
{
	printf("Usage: env [OPTION]... [-] [NAME=VALUE]... [COMMAND [ARG]...]\n"
		"Set each NAME to VALUE in the environment and run COMMAND.\n");
	return;
}

void printEnv()
{
	for (char** env = environ; *env; env++)
	{
		char* thisEnv = *env;
		printf("%s\n", thisEnv);
	}
	return;
}

// required so that the program can access the environment
extern char **environ;

void main(int argc, char* argv[])
{
	int optc;
	int flags = 1;
	while ((optc = getopt(argc, argv, ":ha")) != -1) {
		switch (optc) {
			case 'h':
				usage();
				return;
			case 'a':
				printf("Do something\n");
				break;
		}
		flags++;
	}
	while ( flags < argc )
	{
		// if the string contains an '=' set as an env var
		putenv(argv[flags]);
		flags++;
	}

	// if no arguments passed print out the environment
	if (argc == 1) {
		printEnv();
	}
}
