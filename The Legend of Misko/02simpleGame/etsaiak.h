#pragma once

#ifndef ETSAIAK_H
#define ETSAIAK_H

#include "OurTypes.h"

//ENEMIGOS
int crearbarra(int x[], int y[], int tamaño[], int* spriteKop, int* barranum);
int barraIrudiaSortu(char* barra);

void golpesonido(int jokalariaPosX, int jokalariaPosY, int mirar[], int enemigo1posx[], int enemigo1posy[], int kopuru, int DUNGEON_2[][17]);
int golpe(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa, int casilla, int mirar[]);
void golpenorabide(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA enemigo1[], int x[], int y[], int espera[], int enemigo1posx[], int enemigo1posy[], int ene1vidas[], int mirar[], int casilla, int kopuru, int ataque, int barranum, int DUNGEON_2[][17]);
void golpenorabide2(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA enemigo2[], int x[], int y[], int enemigo2posx[], int enemigo2posy[], int ene2vidas[], int mirar[], int casilla, int kopuru2, int ataque, int barranum, int DUNGEON_2[][17]);

void crearpersonajes(JOKO_ELEMENTUA enemigo1[], JOKO_ELEMENTUA enemigo2[], int tamaño[], int espera[], int enemigo1posx[], int enemigo1posy[], int enemigo2posx[], int enemigo2posy[], int avanzarx[], int avanzary[], int ene1vidas[], int ene2vidas[], int shoot[], int* spriteKop, int kopuru, int kopuru2);
int JOKOA_enemigo1IrudiaSortu(JOKO_ELEMENTUA oztopoa);
int JOKOA_enemigo2IrudiaSortu(JOKO_ELEMENTUA oztopoa);

void movimiento1(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA enemigo1[], int espera[], int enemigo1posx[], int enemigo1posy[], int avanzarx[], int avanzary[], int casilla, int kopuru, int DUNGEON_2[][17]);
void movimiento2(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA enemigo2[], int shoot[], int enemigo2posx[], int enemigo2posy[], int avanzarx[], int avanzary[], int casilla, int kopuru, int kopuru2, int DUNGEON_2[][17]);
void enemigosprite(JOKO_ELEMENTUA enemigo1[], JOKO_ELEMENTUA enemigo2[], int x[], int y[], int avanzarx[], int avanzary[], int move[], int sprkont[], int spritemove[], int kopuru, int kopuru2, int* t);

int hostias(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa, int casilla);
JOKO_ELEMENTUA hostiaerantzun(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA enemigo1[], int espera[], int kopuru, int casilla, int* ataque, int* vidas, int* jokalariaPosX, int* jokalariaPosY, int DUNGEON_2[][17]);

int flechaIrudiaSortu(JOKO_ELEMENTUA flecha, int* spriteKop);
POSIZIOA mugimendua_FLECHA_POSITIVO(POSIZIOA posizioa);
POSIZIOA mugimendua_FLECHA_NEGATIVO(POSIZIOA posizioa);
int disparo(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa, int casilla);
int flechazo(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa, int casilla, int direccion);
void flechadireccion(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA enemigo2[], JOKO_ELEMENTUA flecha[], int direc[], int tamaño[], int kont[], int* spriteKop, int xSprite[], int ySprite[], int flechaposx[], int flechaposy[], int enemigo2posx[], int enemigo2posy[], int kopuru2, int* kopuru3, int shoot[], int denbora, int casilla);
void flechagolpeo(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA flecha[], int direc[], int xSprite[], int ySprite[], int kont[], int flechaposx[], int flechaposy[], int* spriteKop, int* misko_vida, int* kopuru3, int casilla, int DUNGEON_2[][17]);
void vidasprite(int vidas, int tamaño[], int xSprite[], int ySprite[], int num);


#endif
