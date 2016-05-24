#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ncurses.h>
#include "func.h"

int main()
{
	int n;
	printf("Input size of field: ");
	scanf("%d", &n);
	int field[n][n];

	mixing(n, field);
	total(n, field);
	initscr();
	curs_set(0);
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_YELLOW);
	attron(COLOR_PAIR(1));

	output_field(n, field, 0);
	contin(n, field);
	attroff(COLOR_PAIR(1));
	refresh();

	endwin();
	return 0;
}