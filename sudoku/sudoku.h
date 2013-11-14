#ifndef __SUDOKU_H__
#define __SUDOKU_H__


void speichern (int*[9]);
char* laden ();
int** sudokuMain (char[]);
void sudokuX ();

#define G 9 /* Groesse des Sudokus */
static int feld[G][G];
static int loesungen = 0;

int createSudoku(char*);
void printSudoku();
int solve(int, int);
int checkBox(int, int, int);
int checkVertical(int, int);
int checkHorizontal(int, int);
int check(int , int , int );

#endif