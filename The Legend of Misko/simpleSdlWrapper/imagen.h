#ifndef IMAGEN_H
#define IMAGEN_H

#define MAX_IMG 100

int irudiaKargatu(char *fileName);
int  spriteKargatu(char* fileName);
void irudiaMugitu(int numImg, int x, int y);
void  spriteMugitu(int numImg, int x, int y);
void irudiakMarraztu(void);
void spriteakMarraztu(int x[], int y[], int num, int tamaño[]);
void spriteakMarraztu_txikia(int x[], int y[], int num, int tamaño[]);
void irudiaKendu(int id);
void spriteKendu(int id);

#endif
