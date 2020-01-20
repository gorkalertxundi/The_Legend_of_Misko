#pragma once
#ifndef MAPAK_H
#define MAPAK_H

#include "soinua.h"
#include "OurTypes.h"

//MAPAK
int CIUDADMAPA(JOKO_ELEMENTUA jokalaria, EGOERA egoera, int sartu, CONDICION* piedraRota, CONDICION* tenerPico, CONDICION* taberneroHablar, JOKO_ELEMENTUA mapa, JOKO_ELEMENTUA* donde_ir, CONDICION bossInteraccion, Mix_Chunk* puerta, int xSprite[], int ySprite[], int move[], int spriteKop, int spriteMove[], int spriteKont[], int mirar[], int tamaño[], JOKO_ELEMENTUA* helburua3, JOKO_ELEMENTUA* helburua4, int* misko_vida);
int CASAMAPA(JOKO_ELEMENTUA* jokalaria, EGOERA egoera, int atera, int sartu, CONDICION tenerPico, Mix_Chunk* puerta, int xSprite[], int ySprite[], int move[], int spriteKop, int spriteMove[], int spriteKont[], int mirar[], int tamaño[], int* misko_vida);
int CASTILLOEXTERIOR(int* misko_vida, JOKO_ELEMENTUA jokalaria, EGOERA egoera, int sartu, CONDICION tenerPico, int xSprite[], int ySprite[], int move[], int spriteKop, int spriteMove[], int spriteKont[], int mirar[], int tamaño[]);
int CASTILLOMAPA(int* misko_vida, JOKO_ELEMENTUA jokalaria, EGOERA egoera, int sartu, CONDICION tenerPico, Mix_Chunk* puerta, int xSprite[], int ySprite[], int move[], int spriteKop, int spriteMove[], int spriteKont[], int mirar[], int tamaño[]);
int TABERNA(int* misko_vida, JOKO_ELEMENTUA jokalaria, EGOERA egoera, CONDICION* taberneroHablar, JOKO_ELEMENTUA* donde_ir, Mix_Chunk* puerta, int xSprite[], int ySprite[], int move[], int spriteKop, int spriteMove[], int spriteKont[], int mirar[], int tamaño[], JOKO_ELEMENTUA* helburua1, JOKO_ELEMENTUA* helburua2);
int PITONISA(int* misko_vida, JOKO_ELEMENTUA jokalaria, EGOERA egoera, CONDICION* pitonisaHablar, int xSprite[], int ySprite[], int move[], int spriteKop, int spriteMove[], int spriteKont[], int mirar[], int tamaño[]);
int PLAYA(int* misko_vida, JOKO_ELEMENTUA jokalaria, EGOERA egoera, CONDICION* abrirCofre, CONDICION* tenerPico, JOKO_ELEMENTUA* donde_ir, JOKO_ELEMENTUA* pico, int xSprite[], int ySprite[], int move[], int spriteKop, int spriteMove[], int spriteKont[], int mirar[], int tamaño[], JOKO_ELEMENTUA* helburua2, JOKO_ELEMENTUA* helburua3);
int DUNGEON1(int* misko_vida, JOKO_ELEMENTUA jokalaria, EGOERA egoera, int sartu, CONDICION* piedraLargaRota, CONDICION* mineroSalvado, JOKO_ELEMENTUA* donde_ir, JOKO_ELEMENTUA* mapa_mina, CONDICION bossInteraccion, int xSprite[], int ySprite[], int move[], int spriteKop, int spriteMove[], int spriteKont[], int mirar[], int tamaño[]);
int DUNGEON2(int* misko_vida, JOKO_ELEMENTUA jokalaria, EGOERA egoera, int sartu, CONDICION* monstruosMuertos, int xSprite[], int ySprite[], int move[], int spriteKop, int spriteMove[], int spriteKont[], int mirar[], int tamaño[]);
int DUNGEON3(JOKO_ELEMENTUA *vidas, JOKO_ELEMENTUA jokalaria, EGOERA* egoera, int sartu, CONDICION* bossInteraccion, JOKO_ELEMENTUA* mapa_mina, JOKO_ELEMENTUA* menu, JOKO_ELEMENTUA* donde_ir, JOKO_ELEMENTUA* pico, int* boss_vida, int* misko_vida, int xSprite[], int ySprite[], int move[], int spriteKop, int spriteMove[], int spriteKont[], int mirar[], int tamaño[], JOKO_ELEMENTUA* helburua4);
int CASAGRANDE(int* misko_vida, JOKO_ELEMENTUA jokalaria, EGOERA egoera, Mix_Chunk* puerta, int xSprite[], int ySprite[], int move[], int spriteKop, int spriteMove[], int spriteKont[], int mirar[], int tamaño[]);
#endif