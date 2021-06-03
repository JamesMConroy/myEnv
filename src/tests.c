#include "minunit.h"
#include "myenv.h"

#include <string.h>
#include <stdio.h>

int tests_run = 0;

static char* test_isEnvVar_true(void)
{
	bool got = isEnvVar( "foo=bar" );
	mu_assert( "Error isEnvVar returned false for 'foo=bar'",\
			got == true );
	return 0;
}

static char* test_isEnvVar_false(void)
{
	bool got = isEnvVar( "bash" );
	mu_assert( "Error isEnvVar returned true for 'bash'",\
			got == false );
	got = isEnvVar( "" );
	mu_assert( "Error isEnvVar returned true for ''",\
			got == false );
	return 0;
}


static char* all_tests()
{
	mu_run_test(test_isEnvVar_true);
	mu_run_test(test_isEnvVar_false);
	return 0;
}

int main()
{
	char* result = all_tests();
	if (result != 0)
	{
		printf("%s\n", result);
	} else {
		printf("ALL TESTS PASSED\n");
	}
	printf("Tests run: %d\n", tests_run);

	return result != 0;
}
