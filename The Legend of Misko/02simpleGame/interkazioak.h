#ifndef INTERAKZIOAK_H
#define INTERAKZIOAK_H

#include "OurTypes.h"


//INTERACCION
void interaccionTABERNERO(JOKO_ELEMENTUA* tabernero, int mirar[], int spriteMove[], int xSprite[], int ySprite[], int spriteKont[], int tamaño[]);
void interaccionIrAntesDeTabernero(int xSprite[], int ySprite[], int spriteKop, int tamaño[]);
void interaccionPITONISA(int xSprite[], int ySprite[], int spriteKop, int tamaño[]);
void interaccionCofre(int xSprite[], int ySprite[], int spriteKop,  int tamaño[]);
void interaccionDUNGEON3(int xSprite[], int ySprite[], int spriteKop, int tamaño[], int jokalariaPosX, int jokalariaPosY, int mirar[], int spriteMove[], int ebentu, int spriteKont[], JOKO_ELEMENTUA jokalaria);

#endif