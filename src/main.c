#define _DEFAULT_SOURCE

#include "myenv.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	int optc;
	while ((optc = getopt(argc, argv, ":ih")) != -1) {
		switch (optc) {
			case 'h':
				usage();
				return 0;
			case 'i':
				printf("New ENV\n");
				environ = NULL;
				break;
		}
	}
	
	argv += optind;
	for (; *argv; argv++ )
	{
		// if the string contains an '=' set as an env var
		if (isEnvVar(*argv))
		{
			putenv(*argv);
		} else {
			break;
		}
	}
	
	execvp(*argv, argv);

	// if no arguments passed print out the environment
	if (argc == 1) {
		printEnv();
	}

	return 0;
}
