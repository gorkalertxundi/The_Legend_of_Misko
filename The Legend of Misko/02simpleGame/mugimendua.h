#pragma once
#ifndef MUGIMENDUA_H
#define MUGIMENDUA_H

#include "OurTypes.h"



//Pertsonaiaren Mugimendua
POSIZIOA ERREALITATE_FISIKOA_mugimendua(POSIZIOA posizioa, int pantailaMugimenduaTxikia);
POSIZIOA ERREALITATE_FISIKOA_mugimendua_NEGATIVO(POSIZIOA posizioa, int pantailaMugimenduaTxikia);
POSIZIOA mugimendua_PLAYER_POSITIVO(POSIZIOA posizioa);
POSIZIOA mugimendua_PLAYER_NEGATIVO(POSIZIOA posizioa);
POSIZIOA mugimendua_PLAYER_POSITIVO_txikia(POSIZIOA posizioa);
POSIZIOA mugimendua_PLAYER_NEGATIVO_txikia(POSIZIOA posizioa);
void pertsonaiarenMugimendua(int mirar[], int spriteMove[], int xSprite[], int ySprite[], int ebentu, int spriteKont[], JOKO_ELEMENTUA* jokalaria, int* jokalariaPosX, int* jokalariaPosY, int num);
void pertsonaiarenMugimendua_txikia(int* mirar, int spriteMove[], int xSprite[], int ySprite[], int ebentu, int spriteKont[], JOKO_ELEMENTUA* jokalaria, int* jokalariaPosX, int* jokalariaPosY);

#endif
