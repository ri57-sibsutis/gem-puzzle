#include <ctest.h>

#include <func.h>

CTEST(gem_suite, search_of_zero_test)
{
	//Given
	const int n = 4;
	const int field[n][n] = {{12, 5, 8, 7}, {11, 2, 4, 14}, {13, 6, 1, 0}, {10, 9, 15, 3}};

	//When
	int a = 0,  b = 0;
	search_of_zero(n, field, &a, &b);

	//Then
	const int expected_a = 2;
	const int expected_b = 3;

	ASSERT_EQUAL(expected_a, a);
	ASSERT_EQUAL(expected_b, b);
}