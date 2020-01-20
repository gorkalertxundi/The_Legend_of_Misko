#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include "defineak.h"
#include "puzzleak.h"
#include "mugimendua.h"
#include "OurTypes.h"
#include "interkazioak.h"

//INTERACCIONES
void interaccionTABERNERO(JOKO_ELEMENTUA* tabernero, int mirar[], int spriteMove[], int xSprite[], int ySprite[], int spriteKont[], int tamaño[]) {

	int ebentu = 0;
	tamaño[2] = 48;
	xSprite[2] = 0;
	ySprite[2] = 0;
	int valoralazar1 = 0, valoralazar2 = 0; // HAY QUE PASARLE UNA VARIABLE QUE PUEDA CAMBIAR AUNQUE NO LA VAYAMOS A USAR

	tabernero->id = JOKOA_spritearenIrudiaSortu(TABERNERO_ANDANDO1);
	tabernero->pos.x = 562;
	tabernero->pos.y = 50;
	spriteMugitu(tabernero->id, tabernero->pos.x, tabernero->pos.y);
	pantailaGarbitu();
	irudiakMarraztu();
	spriteakMarraztu(xSprite, ySprite, 3, tamaño);
	pantailaBerriztu();
	while (tabernero->pos.y != 88) {
		Sleep(2);
		mirar[2] = 5;
		pertsonaiarenMugimendua(mirar, spriteMove, xSprite, ySprite, ebentu, spriteKont, tabernero, &valoralazar1, &valoralazar2, 2);
		spriteMugitu(tabernero->id, tabernero->pos.x, tabernero->pos.y);
		pantailaGarbitu();
		irudiakMarraztu();
		spriteakMarraztu(xSprite, ySprite, 3, tamaño);
		pantailaBerriztu();
	}
	ySprite[2] = 1;
	while (tabernero->pos.x != 296) {
		Sleep(2);
		mirar[2] = 6;
		pertsonaiarenMugimendua(mirar, spriteMove, xSprite, ySprite, ebentu, spriteKont, tabernero, &valoralazar1, &valoralazar2, 2);
		spriteMugitu(tabernero->id, tabernero->pos.x, tabernero->pos.y);
		pantailaGarbitu();
		irudiakMarraztu();
		spriteakMarraztu(xSprite, ySprite, 3, tamaño);
		pantailaBerriztu();
	}
	ySprite[2] = 0;

	dialogoConversacion(ebentu, TABERNARIA1, xSprite, ySprite, 3, tamaño);
	SDL_Delay(1000);//SUMAR LOS DOS DELAYS DE ARRIBA por si le das a la e como un enfermo mental mientras esa andando para que no se cierre la conver
	while (ebentu != TECLA_e) {
		ebentu = ebentuaJasoGertatuBada();
	}
}
void interaccionIrAntesDeTabernero(int xSprite[], int ySprite[], int spriteKop, int tamaño[]) {

	int ebentu = 0;
	dialogoConversacion(ebentu, HONDARTZA_EZIN, xSprite, ySprite, spriteKop, tamaño);
}
void interaccionPITONISA(int xSprite[], int ySprite[], int spriteKop, int tamaño[]) {

	int ebentu = 0;
	dialogoConversacion(ebentu, PITONISA_HITZ_EGIN, xSprite, ySprite, spriteKop, tamaño);
}
void interaccionCofre(int xSprite[], int ySprite[], int spriteKop, int tamaño[]) {

	JOKO_ELEMENTUA pico;
	int ebentu = 0;
	spriteKop = 3;
	dialogoConversacion(ebentu, COFRE_ENCONTRAR, xSprite, ySprite, spriteKop, tamaño);
	pico.id = JOKOA_objetuarenIrudiaSortu(OBTENER_PICO);
	irudiaMugitu(pico.id, 155, 10);
	pantailaGarbitu();
	irudiakMarraztu();
	spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);
	pantailaBerriztu();
	ebentu = 0;
	dialogoPuzzle(ebentu, PIKOTXA_LORTU);
	irudiaKendu(pico.id);
	pantailaGarbitu();
	irudiakMarraztu();
	spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);
	pantailaBerriztu();

}
void interaccionDUNGEON3(int xSprite[], int ySprite[], int spriteKop, int tamaño[], int jokalariaPosX, int jokalariaPosY, int mirar[], int spriteMove[], int ebentu, int spriteKont[], JOKO_ELEMENTUA jokalaria) {
	JOKO_ELEMENTUA sinboloa, runa, boss;

	spriteKop = 4;

	sinboloa.pos.x = 151;
	sinboloa.pos.y = 200;

	runa.pos.x = 151;
	runa.pos.y = 200;

	boss.pos.x = 250;
	boss.pos.y = 133;

	spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);
	pantailaGarbitu();
	irudiakMarraztu();
	spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);
	pantailaBerriztu();

	SDL_Delay(500);

	sinboloa.id = JOKOA_objetuarenIrudiaSortu(SINBOLOA);
	irudiaMugitu(sinboloa.id, 269, 155);
	runa.id = JOKOA_objetuarenIrudiaSortu(RUNA);
	irudiaMugitu(runa.id, 284, 77);
	pantailaGarbitu();
	irudiakMarraztu();
	spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);
	pantailaBerriztu();	

	SDL_Delay(500);

	boss.id = JOKOA_spritearenIrudiaSortu(BOSS_AGERTU);
	spriteMugitu(boss.id, boss.pos.x, boss.pos.y);
	xSprite[2] = 0;
	ySprite[2] = 0;
	tamaño[2] = 150;

	while (ySprite[2] <= 1) {//ZIRKULU BELTZAREN ANIMAZIOA
		pantailaGarbitu();
		irudiakMarraztu();
		spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);
		pantailaBerriztu();
		xSprite[2]++;
		if (xSprite[2] == 4) {
			ySprite[2]++;
			xSprite[2] = 0;
		}
		Sleep(200);
	}

	spriteKendu(boss.id);
	tamaño[2] = 100;
	boss.pos.x = 290;
	boss.pos.y = 140;
	xSprite[2] = 0;
	ySprite[2] = 0;
	boss.id = JOKOA_spritearenIrudiaSortu(BOSS);
	spriteMugitu(boss.id, boss.pos.x, boss.pos.y);

	while (jokalariaPosX != 8) {
		Sleep(2);
		mirar[0] = 7;
		pertsonaiarenMugimendua(mirar, spriteMove, xSprite, ySprite, ebentu, spriteKont, &jokalaria, &jokalariaPosX, &jokalariaPosY,0);
		spriteMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
		if (spriteKont[0] == 5) {
			if (xSprite[2] == 2) xSprite[2] = 0;
			else xSprite[2]++;

		}
		pantailaGarbitu();
		irudiakMarraztu();
		spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);
		pantailaBerriztu();
	}
	while (jokalariaPosY != 8) {
		Sleep(2);
		mirar[0] = 8;//para que empieze a moverse directamente
		ySprite[0] = 3;//Para que se ponga mirando hacia arriba
		pertsonaiarenMugimendua(mirar, spriteMove, xSprite, ySprite, ebentu, spriteKont, &jokalaria, &jokalariaPosX, &jokalariaPosY,0);
		spriteMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
		if (spriteKont[0] == 5) {
			if (xSprite[2] == 2) xSprite[2] = 0;
			else xSprite[2]++;

		}
		pantailaGarbitu();
		irudiakMarraztu();
		spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);
		pantailaBerriztu();
	}
	irudiaKendu(runa.id);
	irudiaKendu(sinboloa.id);
	spriteKendu(boss.id);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
}