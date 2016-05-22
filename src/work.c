#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ncurses.h>

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int filling(int n, int field[n][n])
{
	int i, j, k = 1;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++, k++)
		{
			if (k == n * n)
			{
				k = 0;
			}
			field[i][j] = k;
		}
	}
	return 0;
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

int output_field(int n, int field[n][n])
{
	int i, j;
	clear();
	printw("\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printw("%d\t", field[i][j]);
		}
		printw("\n");
	}

	return 0;
}

int search_of_zero(int n, int field[n][n], int *a, int*b)
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
	printw("\na = %d, b = %d", *a, *b);
	return 0;
}

void search_of_next(int n, int a, int b, int c, int *a_n, int *b_n)
{
	if (c == 'w' && (a - 1) >= 0)
	{
		*a_n = a - 1;
		*b_n = b;
	}

	else if (c == 's' && (a + 1) < n)
	{
		*a_n = a + 1;
		*b_n = b;
	}

	else if (c == 'a' && (b - 1) >= 0)
	{
		*a_n = a;
		*b_n = b - 1;
	}

	else if (c == 'd' && (b + 1) < n)
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

int change(int n, int field[n][n])
{
	int a, b, c, a_n, b_n;
	c = getch();

	search_of_zero(n, field, &a, &b);
	search_of_next(n, a, b, c, &a_n, &b_n);
	printw("\ni_next = %d, j_next = %d", a_n, b_n);
	swap(&field[a][b], &field[a_n][b_n]);
	return 0;
}

int win(int n, int field[n][n])
{
	return 0;
}

void contin(int n, int field[n][n])
{
	int x;
	x = win(n, field);
	while (x == 0)
	{
		change(n, field);
		output_field(n, field);
	}
}

int main()
{
	int n;
	printf("Enter n: ");
	scanf("%d", &n);
	int field[n][n];

	mixing(n, field);

	initscr();
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(1));

	output_field(n, field);
	contin(n, field);
	attroff(COLOR_PAIR(1));
	refresh();

	endwin();
	return 0;
}