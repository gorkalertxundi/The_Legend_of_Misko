#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <windows.h>
#include "defineak.h"
#include "hasieraEtaAmaiera.h"
#include "puzzleak.h"
#include "mugimendua.h"
#include "OurTypes.h"
#include "interkazioak.h"
#include "Mapak.h"
#include "etsaiak.h"

EGOERA jokatu(void)
{ 
	int atera = 9;// A DONDE ENTRAS
	int sartu = 0;// DE DONDE SALES
	EGOERA egoera = JOLASTEN;
	int ebentu = 0;
	JOKO_ELEMENTUA jokalaria, pico, menu, mapa, donde_ir, mapa_mina, helburua1, helburua2, helburua3, helburua4, vidas;
	
	jokalaria.id = JOKOA_spritearenIrudiaSortu(JOKOA_PLAYER_IMAGE);
	vidas.id = JOKOA_spritearenIrudiaSortu(CORAZONES);
	vidas.pos.x = 1080;
	vidas.pos.y = 160;
	spriteMugitu(vidas.id, vidas.pos.x, vidas.pos.y);

	int boss_vida = 4, misko_vida = 3;

	//SPRITEAREN POSIZIOA
	int move[6] = { 0, 0, 2, 2, 2, 1 };
	//POSIZIOA aux;
	int xSprite[100] = { 1, 0 }, ySprite[100] = { 0, 0 }, spriteKop = 2, spriteMove[5] = { 0 }, spriteKont[5] = { 0, 0 }, mirar[100], tamaño[30];

	mirar[0] = 1;
	tamaño[0] = 48;
	tamaño[1] = 96;

	//TODAS LAS CONDICIONES
	CONDICION taberneroHablar = NO;
	CONDICION piedraRota = NO;
	CONDICION pitonisaHablar = NO;
	CONDICION bossInteraccion = NO;
	CONDICION abrirCofre = NO;
	CONDICION piedraLargaRota = NO;
	CONDICION tenerPico = NO;
	CONDICION monstruosMuertos = NO;
	CONDICION mineroSalvado = NO;

	Mix_Music* musica_fondo;
	Mix_Chunk* puerta;
	puerta = Mix_LoadWAV(PUERTA_ABRIENDOSE);
	musica_fondo = Mix_LoadMUS(JOKOA_SOUND);

	jokalaria.pos.x = 300;
	jokalaria.pos.y = 200;

	textuaIdatzi(150, 200, "'La grandeza nace de pequeños comienzos'");
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	SDL_Delay(1000);

	//MUSICA DE CAMPO
	Mix_PlayMusic(musica_fondo, -1);
	Mix_VolumeMusic(50);//BAJAR EL VOLUMEN

	mapa.id = JOKOA_objetuarenIrudiaSortu(MAPA_DE_TODO);
	irudiaMugitu(mapa.id, 640, 0);
	menu.id = JOKOA_objetuarenIrudiaSortu(MENU);
	irudiaMugitu(menu.id, 640, 0);
	helburua1.id = JOKOA_objetuarenIrudiaSortu(HELBURUA_1);
	irudiaMugitu(helburua1.id, 1100, 300);
	donde_ir.id = JOKOA_objetuarenIrudiaSortu(DONDE_IR);
	irudiaMugitu(donde_ir.id, 895, 35);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	while (egoera == JOLASTEN || egoera == ERREPIKATZEN) {
		if (atera == 0) {
			atera = CASAMAPA(&jokalaria, egoera, atera, sartu, tenerPico, puerta, xSprite, ySprite, move, spriteKop, spriteMove, spriteKont, mirar, tamaño, &misko_vida);//MAPA DE LA CASA
			if (atera == 0) {//SI SALES DE LA FUNCION CON EL MISMO ATERA SIGNIFICA Q HAS MUERTO
				egoera = GALDU;
			}
		}
		if (atera == 1) {
			atera = CIUDADMAPA(jokalaria, egoera, sartu, &piedraRota, &tenerPico, &taberneroHablar, mapa, &donde_ir, bossInteraccion, puerta, xSprite, ySprite, move, spriteKop, spriteMove, spriteKont, mirar, tamaño, &helburua3, &helburua4, &misko_vida);//MAPA DEL EXTERIOR DE LA CASA
			if (atera == 1) {//SI SALES DE LA FUNCION CON EL MISMO ATERA SIGNIFICA Q HAS MUERTO
				egoera = GALDU;
			}
			else if (atera == 0) {
				sartu = 1;//si entra a la casa sartu = 1
			}
		}
		if (atera == 2) {
			atera = CASTILLOEXTERIOR(&misko_vida, jokalaria, egoera, sartu, tenerPico, xSprite, ySprite, move, spriteKop, spriteMove, spriteKont, mirar, tamaño);//MAPA DEL EXTERIOR DEL CASTILLO
			if (atera == 2) {//SI SALES DE LA FUNCION CON EL MISMO ATERA SIGNIFICA Q HAS MUERTO
				egoera = GALDU;
			}
			else if (atera == 1) {
				sartu = 2;//si entra al pueblo sartu = 2
			}
		}
		if (atera == 3) {
			atera = CASTILLOMAPA(&misko_vida, jokalaria, egoera, sartu, tenerPico, puerta, xSprite, ySprite, move, spriteKop, spriteMove, spriteKont, mirar, tamaño);//MAPA DEL CASTILLO
			if (atera == 3) {//SI SALES DE LA FUNCION CON EL MISMO ATERA SIGNIFICA Q HAS MUERTO
				egoera = GALDU;
			}
			else if (atera == 2) {
				sartu = 3;
			}
		}
		if (atera == 4) {
			atera = TABERNA(&misko_vida, jokalaria, egoera, &taberneroHablar, &donde_ir, puerta, xSprite, ySprite, move, spriteKop, spriteMove, spriteKont, mirar, tamaño, &helburua1, &helburua2);//MAPA DE LA TABERNA
			if (atera == 4) {//SI SALES DE LA FUNCION CON EL MISMO ATERA SIGNIFICA Q HAS MUERTO
				egoera = GALDU;
			}
			else if (atera == 3) {
				sartu = 4;
			}
		}
		if (atera == 5) {
			atera = PITONISA(&misko_vida, jokalaria, egoera, &pitonisaHablar, xSprite, ySprite, move, spriteKop, spriteMove, spriteKont, mirar, tamaño);
			if (atera == 5) {
				egoera = GALDU;
			}
			else if (atera == 3) {
				sartu = 5;
			}
		}
		if (atera == 6) {
			atera = CASAGRANDE(&misko_vida, jokalaria, egoera, puerta, xSprite, ySprite, move, spriteKop, spriteMove, spriteKont, mirar, tamaño);
			if (atera == 6) {
				egoera = GALDU;
			}
			else if (atera == 3) {
				sartu = 6;
			}
		}
		if (atera == 7) {
			atera = PLAYA(&misko_vida, jokalaria, egoera, &abrirCofre, &tenerPico, &donde_ir, &pico, xSprite, ySprite, move, spriteKop, spriteMove, spriteKont, mirar, tamaño, &helburua2, &helburua3);
			if (atera == 7) {
				egoera = GALDU;
			}
			else if (atera == 1) {
				sartu = 7;
			}
		}
		if (atera == 8) {
			atera = DUNGEON1(&misko_vida, jokalaria, egoera, sartu, &piedraLargaRota, &mineroSalvado, &donde_ir, &mapa_mina, bossInteraccion, xSprite, ySprite, move, spriteKop, spriteMove, spriteKont, mirar, tamaño);
			if (atera == 8) {
				egoera = GALDU;
			}
			else if (atera == 1) {
				sartu = 8;
			}
		}
		if (atera == 9) {
			atera = DUNGEON2(&misko_vida, jokalaria, egoera, sartu, &monstruosMuertos, xSprite, ySprite, move, spriteKop, spriteMove, spriteKont, mirar, tamaño);
			if (atera == 9) {
				egoera = GALDU;
			}
			else if (atera == 8) {
				sartu = 9;
			}
			if ((egoera == GALDU)) {
				egoera = jokoAmaierakoa(egoera);
			}
		}
		if (atera == 10) {
			atera = DUNGEON3(&vidas, jokalaria, &egoera, sartu, &bossInteraccion, &mapa_mina, &menu, &donde_ir, &pico, &boss_vida, &misko_vida, xSprite, ySprite, move, spriteKop, spriteMove, spriteKont, mirar, tamaño, &helburua4);

			if (atera == 9) {
				sartu = 10;
			}
			if ((egoera == IRABAZI || egoera == GALDU) && bossInteraccion == SI) {
				egoera = jokoAmaierakoa(egoera);
				if (egoera == ERREPIKATZEN) {
					atera = 0;
					sartu = 0;
					tenerPico = NO;
				}
			}
		}
	}

	toggleMusic();
	audioTerminate();
	pantailaGarbitu();
	pantailaBerriztu();
	return egoera;
}
EGOERA JOKOA_egoera(int boss, int vidas) {
	EGOERA  ret = JOLASTEN;
	if (boss == 0) {//AZKEN BURUZAGIAREN BIZITZAK 0-RA HELTZERAKOAN IRABAZTEN DUZU
		ret = IRABAZI;
	}
	else if (vidas == 0) {//ZURE BIZITZAK 0-RA HELTZEN BADIRA GALTZEN DUZU
		ret = GALDU;
	}
	return ret;
}


int JOKOA_objetuarenIrudiaSortu(char* irudia)
{
	//IRUDI BAT SORTZEKO ETA GERO ID BATEKIN ERLAZIONATZEKO
	int objetua = -1;
	objetua = irudiaKargatu(irudia);
	irudiaMugitu(objetua, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return objetua;
}
int JOKOA_spritearenIrudiaSortu(char* irudia)
{
	//SPRITE BAT SORTZEKO ETA GERO ID BATEKIN ERLAZIONATZEKO
	int objetua = -1;
	objetua = spriteKargatu(irudia);
	spriteMugitu(objetua, 0, 0);
	pantailaGarbitu();
	pantailaBerriztu();
	return objetua;
}

