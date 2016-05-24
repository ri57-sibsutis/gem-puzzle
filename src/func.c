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


