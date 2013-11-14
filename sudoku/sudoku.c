/*Adressbuch*/
#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"



/*
Ein Programm das Personen und deren Adressen speichert , sie zurückgeben kann und bestimmte
Eintraege loeschen kann
@Author: Wolfgang Mair,Stefan Pitirut
@Version: 2013-05-11
*/
int main (int argc , char* argv[])
{
	int eingabe;
	int** los;
	los = NULL;
	char* pfad;
	pfad = NULL;

	do
	{
		/* Abfrage was das Programm als naechstes machen soll*/
		printf("Geben sie ein was sie tun wollen:\n0: EXIT\n1: Sudoku laden.\n2: Sudoku speichern.\n3: Normales Sudoku loesen.\n4: X-Sudoku loesen.\n");
		scanf("%d",&eingabe);
		switch(eingabe)
		{
			/*Falls der Benutzer 1 eingibt kann er eine Sudoku csv Datei laden*/
			case 1:
				pfad = laden();
				break;

			/*Falls der Benutzer 2 eingibt kann er eine Sudoku csv Datei speichern*/
			case 2:
				if(los != NULL)
					speichern(los);
				else
					printf("Kein geloestes Sudoku im Zwischenspeicher!");
				break;

			/*Bei 3 loest das Programmm ein normales Sudoku aus einer geladenen csv Datei*/
			case 3:

				los = sudokuMain(pfad);
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
void speichern (int los[9][9])
{
	int i,z;
	FILE *fp;


	char pfadT[200];

	printf("Bitte geben sie den Pfad fuer das Sudoku an:\n");
	scanf("%s", pfadT);


	if(los != NULL){
		if((fp = fopen(pfadT, "w+")) == NULL) {
			printf("Datei %s nicht gefunden!\n", pfadT);
		}
		else{
			for(i = 0; i<9;i++){
				for(i = 0; i<9;i++){
					fprintf (fp, "%d",los[i][z]);
				}
				fprintf(fp,"\n");
			}

		}
	}
}

/*Ladet einen csv Dateipfad in den speicher*/
char* laden ()
{
	char pfadT[200];
	char* pfadP;
	pfadP = NULL;
	printf("Bitte geben sie den Pfad zu dem Sudoku an:\n");
	scanf("%s", pfadT);

	pfadP = pfadT;

	return pfadP;
}

void sudokuX()
{

}
