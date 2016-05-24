#ifndef FUNC_H
#define FUNC_H

void swap(int *a, int *b);
void filing(int n, int field[n][n]);
void mixing(int n, int field[n][n]);
void printf_line(int n);
void output_field(int n, int field[n][n], int course);
void search_of_zero(int n, int field[n][n], int *a, int *b);
void search_of_next(int n, int a, int b, int c, int *a_n, int *b_n);
void change(int n, int field[n][n]);
int win(int n, int field[n][n]);
void contin(int n, int field[n][n]);
int amount(int n, int field[n][n], int i, int j);
int solvable(int n, int field[n][n]);
void total(int n, int field[n][n]);

#endif