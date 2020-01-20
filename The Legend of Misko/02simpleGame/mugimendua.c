#pragma once

#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <windows.h>
#include "defineak.h"
#include "mugimendua.h"
#include "OurTypes.h"
//Pertsonaiaren mugimendua

POSIZIOA ERREALITATE_FISIKOA_mugimendua(POSIZIOA posizioa, int pantailaMugimenduaTxikia) {
	posizioa.y = posizioa.y + pantailaMugimenduaTxikia;
	posizioa.x = posizioa.x + pantailaMugimenduaTxikia;
	return posizioa;
}
POSIZIOA ERREALITATE_FISIKOA_mugimendua_NEGATIVO(POSIZIOA posizioa, int pantailaMugimenduaTxikia) {
	posizioa.y = posizioa.y - pantailaMugimenduaTxikia;
	posizioa.x = posizioa.x - pantailaMugimenduaTxikia;
	return posizioa;
}
POSIZIOA mugimendua_PLAYER_POSITIVO(POSIZIOA posizioa) {
	//JOKALARIA MAPAN ZEHAR 6 PIXEL MUGITZEKO
	posizioa.y = posizioa.y + 6;
	posizioa.x = posizioa.x + 6;
	return posizioa;
}
POSIZIOA mugimendua_PLAYER_NEGATIVO(POSIZIOA posizioa) {
	//JOKALARIA MAPAN ZEHAR 6 PIXEL MUGITZEKO
	posizioa.y = posizioa.y - 6;
	posizioa.x = posizioa.x - 6;
	return posizioa;
}
void pertsonaiarenMugimendua(int mirar[], int spriteMove[], int xSprite[], int ySprite[], int ebentu, int spriteKont[], JOKO_ELEMENTUA* jokalaria, int* jokalariaPosX, int* jokalariaPosY, int num) {

	int move[6] = { 0, 0, 2, 2, 2, 1 };

	POSIZIOA aux;
	//MUGITU NAHI DUZUN LEKURA BEGIRATZEN BALDIN BAZAUDE MUGITZEN HASIKO ZARA
	if (mirar[num] == 5) {
		spriteMove[num]++;
		if (spriteMove[num] > 30) {
			aux = mugimendua_PLAYER_POSITIVO(jokalaria->pos);
			jokalaria->pos.y = aux.y;
			xSprite[num] = move[spriteKont[num]];
			spriteKont[num]++;
			spriteMove[num] = 0;
			if (spriteKont[num] == 3) jokalaria->pos.y += 1;
			if (spriteKont[num] == 6) {
				jokalaria->pos.y += 1;
				spriteKont[num] = 0;
				mirar[num] = 1;
				(*jokalariaPosY)++;
			}
		}
	}
	else if (mirar[num] == 6) {
		spriteMove[num]++;
		if (spriteMove[num] > 30) {
			aux = mugimendua_PLAYER_NEGATIVO(jokalaria->pos);
			jokalaria->pos.x = aux.x;
			xSprite[num] = move[spriteKont[num]];
			spriteKont[num]++;
			spriteMove[num] = 0;
			if (spriteKont[num] == 3) jokalaria->pos.x -= 1;
			if (spriteKont[num] == 6) {
				jokalaria->pos.x -= 1;
				spriteKont[num] = 0;
				mirar[num] = 2;
				(*jokalariaPosX)--;
			}
		}
	}
	else if (mirar[num] == 7) {
		spriteMove[num]++;
		if (spriteMove[num] > 30) {
			aux = mugimendua_PLAYER_POSITIVO(jokalaria->pos);
			jokalaria->pos.x = aux.x;
			xSprite[num] = move[spriteKont[num]];
			spriteKont[num]++;
			spriteMove[num] = 0;
			if (spriteKont[num] == 3) jokalaria->pos.x += 1;
			if (spriteKont[num] == 6) {
				jokalaria->pos.x += 1;
				spriteKont[num] = 0;
				mirar[num] = 3;
				(*jokalariaPosX)++;
			}
		}
	}
	else if (mirar[num] == 8) {//NUM ES EL NUMERO DEL SPRITE, EL PRIMERO Q DIBUJAMOS = 0
		spriteMove[num]++;
		if (spriteMove[num] > 30) {
			aux = mugimendua_PLAYER_NEGATIVO(jokalaria->pos);
			jokalaria->pos.y = aux.y;
			xSprite[num] = move[spriteKont[num]];
			spriteKont[num]++;
			spriteMove[num] = 0;
			if (spriteKont[num] == 3) jokalaria->pos.y -= 1;
			if (spriteKont[num] == 6) {
				jokalaria->pos.y -= 1;
				spriteKont[num] = 0;
				mirar[num] = 4;
				(*jokalariaPosY)--;
			}
		}
	}
	//MUGITU NAHI DUZUN LEKURA BEGIRATZEN EZ BALDIN BAZAUDE LEKU HORRETARA BEGIRATUKO DUZU
	if (mirar[num] <= 4 && mirar[num] >= 0) {
		if (ebentu == TECLA_s) {
			if (mirar[num] == 1) mirar[num] = 5;
			else {
				mirar[num] = 1;
				ySprite[num] = 0;
			}
		}
		if (ebentu == TECLA_a) {
			if (mirar[num] == 2) mirar[num] = 6;
			else {
				mirar[num] = 2;
				ySprite[num] = 1;
			}
		}
		if (ebentu == TECLA_d) {
			if (mirar[num] == 3) mirar[num] = 7;
			else {
				mirar[num] = 3;
				ySprite[num] = 2;
			}
		}
		if (ebentu == TECLA_w) {
			if (mirar[num] == 4) mirar[num] = 8;
			else {
				mirar[num] = 4;
				ySprite[num] = 3;
			}
		}
	}


}
POSIZIOA mugimendua_PLAYER_POSITIVO_txikia(POSIZIOA posizioa) {
	//JOKALARIA MAPAN ZEHAR 3 PIXEL MUGITZEKO
	posizioa.y = posizioa.y + 3;
	posizioa.x = posizioa.x + 3;
	return posizioa;
}
POSIZIOA mugimendua_PLAYER_NEGATIVO_txikia(POSIZIOA posizioa) {
	//JOKALARIA MAPAN ZEHAR 3 PIXEL MUGITZEKO
	posizioa.y = posizioa.y - 3;
	posizioa.x = posizioa.x - 3;
	return posizioa;
}
void pertsonaiarenMugimendua_txikia(int* mirar, int spriteMove[], int xSprite[], int ySprite[], int ebentu, int spriteKont[], JOKO_ELEMENTUA* jokalaria, int* jokalariaPosX, int* jokalariaPosY) {

	int move[6] = { 0, 0, 2, 2, 2, 1 };

	POSIZIOA aux;

	//MUGITU NAHI DUZUN LEKURA BEGIRATZEN BALDIN BAZAUDE MUGITZEN HASIKO ZARA
	if (*mirar == 5) {
		spriteMove[0]++;
		if (spriteMove[0] > 20) {
			aux = mugimendua_PLAYER_POSITIVO_txikia(jokalaria->pos);
			jokalaria->pos.y = aux.y;
			xSprite[0] = move[spriteKont[0]];
			spriteKont[0]++;
			spriteMove[0] = 0;
			if (spriteKont[0] == 6) {
				jokalaria->pos.y += 1;
				spriteKont[0] = 0;
				*mirar = 1;
				(*jokalariaPosY)++;
			}
		}
	}
	else if (*mirar == 6) {
		spriteMove[0]++;
		if (spriteMove[0] > 20) {
			aux = mugimendua_PLAYER_NEGATIVO_txikia(jokalaria->pos);
			jokalaria->pos.x = aux.x;
			xSprite[0] = move[spriteKont[0]];
			spriteKont[0]++;
			spriteMove[0] = 0;
			if (spriteKont[0] == 6) {
				jokalaria->pos.x -= 1;
				spriteKont[0] = 0;
				*mirar = 2;
				(*jokalariaPosX)--;
			}
		}
	}
	else if (*mirar == 7) {
		spriteMove[0]++;
		if (spriteMove[0] > 20) {
			aux = mugimendua_PLAYER_POSITIVO_txikia(jokalaria->pos);
			jokalaria->pos.x = aux.x;
			xSprite[0] = move[spriteKont[0]];
			spriteKont[0]++;
			spriteMove[0] = 0;
			if (spriteKont[0] == 6) {
				jokalaria->pos.x += 1;
				spriteKont[0] = 0;
				*mirar = 3;
				(*jokalariaPosX)++;
			}
		}
	}
	else if (*mirar == 8) {
		spriteMove[0]++;
		if (spriteMove[0] > 20) {
			aux = mugimendua_PLAYER_NEGATIVO_txikia(jokalaria->pos);
			jokalaria->pos.y = aux.y;
			xSprite[0] = move[spriteKont[0]];
			spriteKont[0]++;
			spriteMove[0] = 0;
			if (spriteKont[0] == 6) {
				jokalaria->pos.y -= 1;
				spriteKont[0] = 0;
				*mirar = 4;
				(*jokalariaPosY)--;
			}
		}
	}

	//MUGITU NAHI DUZUN LEKURA BEGIRATZEN EZ BALDIN BAZAUDE LEKU HORRETARA BEGIRATUKO DUZU
	if (*mirar <= 4 && *mirar >= 0) {//MUGITU NAHI DUZUN LEKURA BEGIRATZEN EZ BALDIN BAZAUDE LEKU HORRETARA BEGIRATUKO DUZU
		if (ebentu == TECLA_s) {
			if (*mirar == 1) *mirar = 5;
			else {
				*mirar = 1;
				ySprite[0] = 0;
			}
		}
		if (ebentu == TECLA_a) {
			if (*mirar == 2) *mirar = 6;
			else {
				*mirar = 2;
				ySprite[0] = 1;
			}
		}
		if (ebentu == TECLA_d) {
			if (*mirar == 3) *mirar = 7;
			else {
				*mirar = 3;
				ySprite[0] = 2;
			}
		}
		if (ebentu == TECLA_w) {
			if (*mirar == 4) *mirar = 8;
			else {
				*mirar = 4;
				ySprite[0] = 3;
			}
		}
	}


}

