#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ncurses.h>
#include "func.h"

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void filling(int n, int field[n][n])
{
	int i, j, k = 1;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++, k++)
		{
			field[i][j] = k;
		}
	}
	field[n - 1][n - 1] = 0;
}

void mixing(int n, int field[n][n])
{
	filling(n, field);
	int a, b, i, j, k;

	srand(time(0));
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			k = rand()% (n * n);
			a = k / n;
			b = k % n;
			swap(&field[a][b], &field[i][j]);
		}
	}
}

void print_line(int n)
{
	int i;
	printw("\n+");
	for (i = 0; i < n; i++)
	{
		printw("----");
		printw("+");
	}
}

void output_field(int n, int field[n][n], int course)
{
	int i, j;
	clear();
	printw("Amount of turns: %d", course);
	printw("\n");
	for (i = 0; i < n; i++)
	{
		print_line(n);
		printw("\n");
		for (j = 0; j < n; j++)
		{
			if (field[i][j] == 0)
			{
				printw("     ");
			}
			else
			{
				printw("|%3d ", field[i][j]);
			}
		}
		printw("|");
	}
	print_line(n);
}

void search_of_zero(int n, int field[n][n], int *a, int*b)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (field[i][j] == 0)
			{
				*a = i;
				*b = j;
			}
		}
	}
}

void search_of_next(int n, int a, int b, int c, int *a_n, int *b_n)
{
	if (c == 's' && (a - 1) >= 0)
	{
		*a_n = a - 1;
		*b_n = b;
	}

	else if (c == 'w' && (a + 1) < n)
	{
		*a_n = a + 1;
		*b_n = b;
	}

	else if (c == 'd' && (b - 1) >= 0)
	{
		*a_n = a;
		*b_n = b - 1;
	}

	else if (c == 'a' && (b + 1) < n)
	{
		*a_n = a;
		*b_n = b + 1;
	}

	else
	{
		*a_n = a;
		*b_n = b;
	}
}

void change(int n, int field[n][n])
{
	int a, b, c, a_n, b_n;
	c = getch();

	search_of_zero(n, field, &a, &b);
	search_of_next(n, a, b, c, &a_n, &b_n);
	swap(&field[a][b], &field[a_n][b_n]);
}

