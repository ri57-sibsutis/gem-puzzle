#include <ctest.h>

#include <func.h>

CTEST(gem_suite, search_of_zero_test)
{
	//Given
	const int n = 4;
	int field[4][4] = {{12, 5, 8, 7}, {11, 2, 4, 14}, {13, 6, 1, 0}, {10, 9, 15, 3}};

	//When
	int a = 0, b = 0;
	search_of_zero(n, field, &a, &b);

	//Then
	const int expected_a = 2;
	const int expected_b = 3;

	ASSERT_EQUAL(expected_a, a);
	ASSERT_EQUAL(expected_b, b);
}

CTEST(gem_suite, search_of_next_test)
{
	//Given
	const int n = 4;
	const int a = 2;
	const int b = 3;
	const int c = 'w';

	//When
	int a_n = 0, b_n = 0;
	search_of_next(n, a, b, c, &a_n, &b_n);

	//Then
	const int expected_a_n = 3;
	const int expected_b_n = 3;

	ASSERT_EQUAL(expected_a_n, a_n);
	ASSERT_EQUAL(expected_b_n, b_n);
}

CTEST(gem_suite, search_of_next_test2)
{
	//Given
	const int n = 4;
	const int a = 3;
	const int b = 3;
	const int c = 'w';

	//When
	int a_n = 0, b_n = 0;
	search_of_next(n, a, b, c, &a_n, &b_n);

	//Then
	const int expected_a_n = 3;
	const int expected_b_n = 3;

	ASSERT_EQUAL(expected_a_n, a_n);
	ASSERT_EQUAL(expected_b_n, b_n);
}

CTEST(gem_suite, win_test)
{
	//Given
	const int n = 4;
	int field[4][4] = {{12, 5, 8, 7}, {11, 2, 4, 14}, {13, 6, 1, 0}, {10, 9, 15, 3}};

	//When
	const int ret_val = win(n, field);

	//Then
	const int expected_val = 0;

	ASSERT_EQUAL(expected_val, ret_val);
}

CTEST(gem_suite, win_test2)
{
	//Given
	const int n = 4;
	int field[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}};

	//When
	const int ret_val = win(n, field);

	//Then
	const int expected_val = 1;

	ASSERT_EQUAL(expected_val, ret_val);
}

CTEST(gem_suite, amount_test)
{
	//Given
	const int n = 4;
	int field[4][4] = {{12, 5, 8, 7}, {11, 2, 4, 14}, {13, 6, 1, 0}, {10, 9, 15, 3}};
	const int i = 1;
	const int j = 0;

	//When
	const int am = amount(n, field, i, j);

	//Then
	const int expected_amount = 8;

	ASSERT_EQUAL(expected_amount, am);
}

CTEST(gem_suite, amount_test2)
{
	//Given
	const int n = 4;
	int field[4][4] = {{12, 5, 8, 7}, {11, 2, 4, 14}, {13, 6, 1, 0}, {10, 9, 15, 3}};
	const int i = 2;
	const int j = 3;

	//When
	const int am = amount(n, field, i, j);

	//Then
	const int expected_amount = 0;

	ASSERT_EQUAL(expected_amount, am);
}

CTEST(gem_suite, solvable_test)
{
	//Given
	const int n = 4;
	int field[4][4] = {{12, 5, 8, 7}, {11, 2, 4, 14}, {13, 6, 1, 0}, {10, 9, 15, 3}};

	//When
	const int ret_val = solvable(n, field);

	//Then
	const int ex_val = 1;

	ASSERT_EQUAL(ex_val, ret_val);
}

CTEST(gem_suite, solvable_test2)
{
	//Given
	const int n = 4;
	int field[4][4] = {{1,2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 15, 14, 0}};

	//When
	const int ret_val = solvable(n, field);

	//Then
	const int ex_val = 0;

	ASSERT_EQUAL(ex_val, ret_val);
}