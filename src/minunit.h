#ifndef MINUNIT_H
#define MINUNIT_H

#define mu_assert(message, test) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; \
				if (message) { tests_failed++ ; printf("%s\tFailed\t%s\n", #test, message); \
				} else { \
					printf("%s\tPassed\n", #test); \
				} } while (0)

extern int tests_run, tests_failed;

#endif
