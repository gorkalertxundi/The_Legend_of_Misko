#ifndef PUZZLEAK_H
#define PUZZLEAK_H

#include "OurTypes.h"

//PUZLE2
void puzle2();
void posicionesPELOTAS(JOKO_ELEMENTUA PILOTAK[]);
POSIZIOA posBerria(POSIZIOA sagua, int ebentu);
POSIZIOA konprobatuZirkBeltzBarruan(POSIZIOA sagua);
int konprobatuPuzlea2(JOKO_ELEMENTUA PILOTAK[]);
int nonKlickEgin(POSIZIOA sagua, JOKO_ELEMENTUA PILOTAK[], int* j, int i);
void dialogoConversacion(int ebentu, char* irudia, int xSprite[], int ySprite[], int spriteKop, int tamaño[]);
void dialogoPuzzle(int ebentu, char* irudia);

//PUZLE3
void puzle3(int xSprite[], int ySprite[], int spriteKop, int tamaño[], int move[], int spriteMove[], int spriteKont[], int mirar[], JOKO_ELEMENTUA* jokalaria);
void posicionesJOKOA(JOKO_ELEMENTUA* jokalaria1, JOKO_ELEMENTUA* jokalaria2, int* jokalaria1Posy, int* jokalaria1PosX, int* jokalaria2Posy, int* jokalaria2PosX);

//PUZLE 1
void puzle1_hasieraAmaieraPantaila();
void puzle1_objetuakMarraztu(PUZZLE1 daga[], PUZZLE1* vino, DAGA orientacion[], int* vinoPosY, int* vinoPosX);
void puzle1_aldatutakoObjetuakEzabatu(PUZZLE1 daga[], PUZZLE1* vino, DAGA orientacion[]);
void puzle1_objetuakEzabatu(PUZZLE1 daga[], PUZZLE1* vino);
void puzle1();
int puzle1_Konprobatu(PUZZLE1 daga[], PUZZLE1* vino, int* vinoPosX, int* vinoPosY, DAGA orientacion[]);
int puzle1_Klikatu(int ebentu);
PUZZLE1 puzle1_dagaIrudiaAldatu(PUZZLE1 daga);
NORANTZA puzle1_vinoNorantza(DAGA orientacion, NORANTZA norantza);

//PUZLE BOSS
EGOERA puzleBoss(JOKO_ELEMENTUA* vidas, CONDICION* bossInteraccion, EGOERA egoera, int* boss_vida, int* misko_vida, int spriteKop, int tamaño[], int xSprite[], int ySprite[], int spriteKont[]);
EGOERA puzleBoss_Emaitzak(int galdera, EGOERA egoera, int* boss_vida, int* misko_vida, int tamaño[], int xSprite[], int ySprite[]);
int puzleBoss_Klikatu(int ebentu);
#endif