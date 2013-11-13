/*Adressbuch*/
#include <stdio.h>
#include <stdlib.h>
#include "SudokuSolver.c"

/*Prototypen*/
void speichern ();
void laden ();
void sudokuMain (char pfad[200]);
void sudokuX ();

/*
Ein Programm das Personen und deren Adressen speichert , sie zurückgeben kann und bestimmte
Eintraege loeschen kann
@Author: Wolfgang Mair,Stefan Pitirut
@Version: 2013-05-11
*/
int main (int argc , char* argv[])
{
	
	int eingabe;
	char sud[82];
	char los[82];
	char pfad[200];
	do
	{
		/* Abfrage was das Programm als naechstes machen soll*/
		printf("Geben sie ein was sie tun wollen:\n0: EXIT\n1: Sudoku laden.\n2: Sudoku speichern.\n3: Normales Sudoku loesen.\n4: X-Sudoku loesen.\n");
		scanf("%d",&eingabe);
		switch(eingabe)
		{
			/*Falls der Benutzer 1 eingibt kann er eine Sudoku csv Datei laden*/
			case 1: 
				laden();
				break;
			
			/*Falls der Benutzer 2 eingibt kann er eine Sudoku csv Datei speichern*/
			case 2:
				if(los != null)
					speichern();
				else
					printf("Kein geloestes Sudoku im Zwischenspeicher!");
				break;
			
			/*Bei 3 loest das Programmm ein normales Sudoku aus einer geladenen csv Datei*/
			case 3: 
				
				SudokuMain();
				break;
			
			/*Bei 4 loest das Programmm ein X-Sudoku aus einer geladenen csv Datei*/
			case 4:
				sudokuX();
				break;
				
			/*Falls nichts oder etwas falsches eingegeben wird bricht er das Programm ab*/
			default:
			
				eingabe = 0;
				printf("Bye!");
				break;
		}
			
	}while(eingabe != 0);
	
	/*Erfolgreiches beenden des Programmes*/
	return EXIT_SUCCESS;
  
}

/*Erstellt ein csv-Datei mit einem gelösten sudoku*/
void speichern ()
{
	
}

/*Ladet einen csv Dateipfad in den speicher*/
void laden ()
{	
	printf("Bitte geben sie den Pfad zu dem Sudoku an:\n");
	scanf("%s", pfad);
}