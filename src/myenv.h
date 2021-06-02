#ifndef MYENV_H
#define MYENV_H

#include <stdbool.h>

// required so that the program can access the environment
extern char **environ;

bool isEnvVar( const char argument[] );
void usage();
void printEnv();

#endif
