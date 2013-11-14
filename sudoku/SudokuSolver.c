#include <stdio.h>

#define G 9 /* Groesse des Sudokus */
static int feld[G][G];
static int loesungen = 0;

/*
* Prueft ob Zahl schon vorhanden (ruft fuer jede Bedingung eine Unterfunktion auf
* Rueckgabe: 0 fuer nicht gefunden
* 1 fuer gefunden
*/
int check(int x, int y, int wert) {
	if(checkHorizontal(y, wert))
		return 1;
	if(checkVertical(x, wert))
		return 1;
	if(checkBox(x, y, wert))
		return 1;
	return 0;
}

/*
* Prueft ob Zahl in der horizontalen Zeile schon vorhanden ist
* Rueckgabe: 0 fuer nicht gefunden
* 1 fuer gefunden
*/
int checkHorizontal(int y, int wert) {
	int i;
	for(i = 0; i < G; i++)
		if(feld[y][i] == wert)
			return 1;
	return 0;
}

/*
* Prueft ob Zahl in einer vertikalen Spalte schon vorhanden ist
* Rueckgabe: 0 fuer nicht gefunden
* 1 fuer gefunden
*/
int checkVertical(int x, int wert) {
	int i;
	for(i = 0; i < G; i++)
		if(feld[i][x] == wert)
			return 1;
	return 0;
}

/*
* Prueft ob Zahl schon in der Box vorhanden ist
* Rueckgabe: 0 fuer nicht gefunden
* 1 fuer gefunden
*/
int checkBox(int x, int y, int wert) {
	int x_box, y_box, i, j;
	/* Passende Ecke der Box herausfinden */
	x_box = (int)(x / 3) * 3;
	y_box = (int)(y / 3) * 3;
	for(i = y_box; i < y_box + 3; i++)
		for(j = x_box; j < x_box + 3; j++)
			if(feld[i][j] == wert)
				return 1;
	return 0;
}

/*
* Gibt alle Lösungen für ein Sudoku an
* x,y Startwert (0,0)
* Rueckgabe: 0 Versuch hat nicht funktioniert
* 1 Versuch hat funktioniert
*/
int solve(int x, int y) {
	int i;
	if(x == G) { /* Zeilenende erreicht */
		y++;
		x = 0;
		if(y == G) /* Ende erreicht */
			return 1;
	}
	
	if(feld[y][x] > 0) /* Feld schon gesetzt */
		return solve(x+1, y); /* Naechstes Feld */
		
	for(i = 1; i <= G; i++) { /* Keine Zahl vorhanden */
		if(!check(x, y, i)) { /* Alle Zahlen durchgehen */
			feld[y][x] = i; /* Wenn Zahl passt, setzen */
				 if(solve(x+1, y)) { /* Naechstes Feld pruefen */
				loesungen++; /* Loesung gefunden, ausgeben */
				printf("Loesung %d:\n", loesungen);
					 printSudoku();
					 printf("\n");
				/*return 1;*/ /*<-- Nur eine Loesung ausgeben */
				 }
		}
	}
	
	feld[y][x] = 0; /* Keine Zahl hat gepasst, wieder 0 setzen */
	return 0;
}

/*
* Gibt ein Sudoku am Bildschirm aus
*/
void printSudoku() {
	int i, j;
	for(i = 0; i < G; i++) {
		for(j = 0; j < G; j++) {
			printf("%d", feld[i][j]);
		}
		printf("\n");
	}
}

/*
* Liest ein Sudoku aus einer Datei ein und speichert es in einem lokalen 2D-Array
* Rueckgabe: 0 Datei erfplgreich eingelesen
* 1 Fehler
*/
int createSudoku(char *dateiname) {
	FILE *fp;
	int i, j;
	char temp[G+3] = {0};

	if((fp = fopen(dateiname, "r")) == NULL) {
		printf("Datei %s nicht gefunden!\n", dateiname);
		return -1;
	}

	for(i = 0; i < G; i++) {
		if(fgets(temp, G + 3, fp) == NULL) {
			printf("Daten nicht vollstaendig!\n");
			fclose(fp);
			return -1;
		}
		for(j = 0; j < G; j++) {
			feld[i][j] = temp[j] - '0';
		}
	}

	fclose(fp);

	return 0;
}

int** sudokuMain(char* pfad) {
	
	int** feldP;
	feldP = NULL;

	if(createSudoku(pfad) < 0)
		return NULL;
	else
	{
		printf("### Eingelesenes Sudoku: ###\n");
	printSudoku();

	printf("\n###################\n");
	solve(0, 0);
	printf("Loesungen: %d\n", loesungen);
	
	**feldP = feld[0][0];

	return feldP;
	}
	
}