#pragma once

#include "OurTypes.h"
#include "Mapak.h"
#include "defineak.h"
#include "mugimendua.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <windows.h>
#include "etsaiak.h"


//ENEMIGOS
int crearbarra(int x[], int y[], int tamaño[], int* spriteKop, int* barranum) {
	int barra2 = -1;
	barra2 = barraIrudiaSortu(BARRA);
	//barra.id = barraIrudiaSortu(barra);
	*spriteKop += 1;
	*barranum = *spriteKop - 1;
	x[*barranum] = 0;
	y[*barranum] = 0;
	tamaño[*barranum] = 48;
	return barra2;
}
int barraIrudiaSortu(char* barra) {
	int barraId = -1;
	barraId = spriteKargatu(barra);
	spriteMugitu(barraId, 450, 30);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return barraId;
}

void golpesonido(int jokalariaPosX, int jokalariaPosY, int mirar[], int enemigo1posx[], int enemigo1posy[], int kopuru, int DUNGEON_2[][17]) {
	int num = 0, i = 0;;
	Mix_Chunk* pico1, * pico2;
	pico1 = Mix_LoadWAV(PICO_OBJETO);
	pico2 = Mix_LoadWAV(PICO_AIRE);

	//EL PRIMER WHILE ES PARA VER SI HA GOLPEADO A UN ENEMIGO
	while (num < kopuru && i != 1) { //i TE DICE SI YA HA HABIDO UN SONIDO, PARA QUE NO HAYA MAS
		if (mirar[0] == 1 && (jokalariaPosY + 2) == enemigo1posy[num] && jokalariaPosX == enemigo1posx[num]) { 
			Mix_PlayChannel(-1, pico1, 0);
			i = 1;
		}
		else if (mirar[0] == 2 && jokalariaPosY == enemigo1posy[num] && (jokalariaPosX - 2) == enemigo1posx[num]) {
			Mix_PlayChannel(-1, pico1, 0);
			i = 1;
		}
		else if (mirar[0] == 3 && jokalariaPosY == enemigo1posy[num] && (jokalariaPosX + 2) == enemigo1posx[num]) {
			Mix_PlayChannel(-1, pico1, 0);
			i = 1;
		}
		else if (mirar[0] == 4 && (jokalariaPosY - 2) == enemigo1posy[num] && jokalariaPosX == enemigo1posx[num]) {
			Mix_PlayChannel(-1, pico1, 0);
			i = 1;
		}
		num++;
	}
	//EL IF ES PARA VER SI HA GOLPEADO UNA PARED O EL AIRE
	if (i == 0) {
		if (mirar[0] == 1 && DUNGEON_2[jokalariaPosY + 1][jokalariaPosX] == 1) {
			Mix_PlayChannel(-1, pico1, 0);
		}
		else if (mirar[0] == 3 && DUNGEON_2[jokalariaPosY][jokalariaPosX + 1] == 1) {
			Mix_PlayChannel(-1, pico1, 0);
		}
		else if (mirar[0] == 2 && DUNGEON_2[jokalariaPosY][jokalariaPosX - 1] == 1) {
			Mix_PlayChannel(-1, pico1, 0);
		}
		else if (mirar[0] == 4 && DUNGEON_2[jokalariaPosY - 1][jokalariaPosX] == 1) {
			Mix_PlayChannel(-1, pico1, 0);
		}
		else {
			Mix_PlayChannel(-1, pico2, 0);
		}
	}

}
int golpe(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa, int casilla, int mirar[]) {
	int golpe = 0;
	//SI LE ESTA MIRANDO Y ESTA EN SU RANGO DE DOS BLOQUES GOLPEA 
	if (jokalaria.pos.y >= oztopoa.pos.y - (2 * casilla) && jokalaria.pos.y < oztopoa.pos.y && jokalaria.pos.x == oztopoa.pos.x && mirar[0] == 1) golpe = 1;
	else if (jokalaria.pos.x <= oztopoa.pos.x + (2 * casilla) && jokalaria.pos.x > oztopoa.pos.x&& jokalaria.pos.y == oztopoa.pos.y && mirar[0] == 2) golpe = 2;
	else if (jokalaria.pos.x >= oztopoa.pos.x - (2 * casilla) && jokalaria.pos.x < oztopoa.pos.x && jokalaria.pos.y == oztopoa.pos.y && mirar[0] == 3) golpe = 3;
	else if (jokalaria.pos.y <= oztopoa.pos.y + (2 * casilla) && jokalaria.pos.y > oztopoa.pos.y&& jokalaria.pos.x == oztopoa.pos.x && mirar[0] == 4) golpe = 4;
	return golpe;
}
void golpenorabide(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA enemigo1[], int x[], int y[], int espera[], int enemigo1posx[], int enemigo1posy[], int ene1vidas[], int mirar[], int casilla, int kopuru, int ataque, int barranum, int DUNGEON_2[][17]) {
	int num;
	for (num = 0; num < kopuru; num++) {
		if (golpe(jokalaria, enemigo1[num], casilla, mirar) != 0) {//DEPENDIENDO DE DESDE DONDE LE HA GOLPEADO SE MUEVE HACIA UNA DIRECCION
			DUNGEON_2[enemigo1posy[num]][enemigo1posx[num]] = 0;
			if (golpe(jokalaria, enemigo1[num], casilla, mirar) == 1 && DUNGEON_2[enemigo1posy[num] + 1][enemigo1posx[num]] != 1) {
				enemigo1[num].pos.y += casilla;
				enemigo1posy[num] += 1;
			}
			else if (golpe(jokalaria, enemigo1[num], casilla, mirar) == 2 && DUNGEON_2[enemigo1posy[num]][enemigo1posx[num] - 1] != 1) {
				enemigo1[num].pos.x -= casilla;
				enemigo1posx[num] -= 1;
			}
			else if (golpe(jokalaria, enemigo1[num], casilla, mirar) == 3 && DUNGEON_2[enemigo1posy[num]][enemigo1posx[num] + 1] != 1) {
				enemigo1[num].pos.x += casilla;
				enemigo1posx[num] += 1;
			}
			else if (golpe(jokalaria, enemigo1[num], casilla, mirar) == 4 && DUNGEON_2[enemigo1posy[num] - 1][enemigo1posx[num]] != 1) {
				enemigo1[num].pos.y -= casilla;
				enemigo1posy[num] -= 1;
			}
			espera[num] = 1; //PARA QUE TARDE UN POCO EN VOLVER A MOVERSE
			DUNGEON_2[enemigo1posy[num]][enemigo1posx[num]] = 1;
			if (x[barranum] == 4 && y[barranum] == 4) ene1vidas[num] -= 3; //SI LE DA UN GOLPE CON LA BARRA CARGADA LE QUITA MAS
			else ene1vidas[num] -= 1;
		}
	}
}
void golpenorabide2(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA enemigo2[], int x[], int y[], int enemigo2posx[], int enemigo2posy[], int ene2vidas[], int mirar[], int casilla, int kopuru2, int ataque, int barranum, int DUNGEON_2[][17]) {
	int num;
	for (num = 0; num < kopuru2; num++) {
		if (golpe(jokalaria, enemigo2[num], casilla, mirar) != 0) { //DEPENDIENDO DE DESDE DONDE LE HA GOLPEADO SE MUEVE HACIA UNA DIRECCION
			DUNGEON_2[enemigo2posy[num]][enemigo2posx[num]] = 0;
			if (golpe(jokalaria, enemigo2[num], casilla, mirar) == 1 && DUNGEON_2[enemigo2posy[num] + 1][enemigo2posx[num]] != 1) {
				enemigo2[num].pos.y += casilla;
				enemigo2posy[num] += 1;
			}
			else if (golpe(jokalaria, enemigo2[num], casilla, mirar) == 2 && DUNGEON_2[enemigo2posy[num]][enemigo2posx[num] - 1] != 1) {
				enemigo2[num].pos.x -= casilla;
				enemigo2posx[num] -= 1;
			}
			else if (golpe(jokalaria, enemigo2[num], casilla, mirar) == 3 && DUNGEON_2[enemigo2posy[num]][enemigo2posx[num] + 1] != 1) {
				enemigo2[num].pos.x += casilla;
				enemigo2posx[num] += 1;
			}
			else if (golpe(jokalaria, enemigo2[num], casilla, mirar) == 4 && DUNGEON_2[enemigo2posy[num] - 1][enemigo2posx[num]] != 1) {
				enemigo2[num].pos.y -= casilla;
				enemigo2posy[num] -= 1;
			}
			DUNGEON_2[enemigo2posy[num]][enemigo2posx[num]] = 1;
			if (x[barranum] == 4 && y[barranum] == 4) ene2vidas[num] -= 3; //SI LE DA UN GOLPE CON LA BARRA CARGADA LE QUITA MAS
			else ene2vidas[num] -= 1;
		}
	}
}

int flechaIrudiaSortu(JOKO_ELEMENTUA flecha, int* spriteKop) {
	int flechaId = -1;
	flechaId = spriteKargatu(FLECHA);
	*spriteKop += 1;
	spriteMugitu(flechaId, flecha.pos.x, flecha.pos.y);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return flechaId;
}
int disparo(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa, int casilla) {
	int pos = 0;
	//SI ESTA EN POSICION DISPARA, DEPENDIENDO DE LA POSICION EN UNA DIRECCION
	if (oztopoa.pos.x == jokalaria.pos.x + (3 * casilla) && oztopoa.pos.y == jokalaria.pos.y) pos = 1;
	else if (oztopoa.pos.x == jokalaria.pos.x - (3 * casilla) && oztopoa.pos.y == jokalaria.pos.y)pos = 2;
	else if (oztopoa.pos.y == jokalaria.pos.y + (3 * casilla) && oztopoa.pos.x == jokalaria.pos.x)pos = 3;
	else if (oztopoa.pos.y == jokalaria.pos.y - (3 * casilla) && oztopoa.pos.x == jokalaria.pos.x)pos = 4;
	return pos;
}
int flechazo(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa, int casilla, int direccion) {
	int golpe = 0;
	//SI ESTA EN SU HITBOX Y LA DIRECCION DE LA FLECHA ES LA CORRECTA RECIBE UN GOLPE
	if (jokalaria.pos.x + casilla / 2 == oztopoa.pos.x && direccion == 1) golpe = 1;
	else if (jokalaria.pos.x - casilla / 2 == oztopoa.pos.x && direccion == 2) golpe = 1;
	else if (jokalaria.pos.y + casilla / 2 == oztopoa.pos.y && direccion == 3) golpe = 1;
	else if (jokalaria.pos.y - casilla / 2 == oztopoa.pos.y && direccion == 4) golpe = 1;
	return golpe;
}
void flechadireccion(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA enemigo2[], JOKO_ELEMENTUA flecha[], int direc[], int tamaño[], int kont[], int* spriteKop, int xSprite[], int ySprite[], int flechaposx[], int flechaposy[], int enemigo2posx[], int enemigo2posy[], int kopuru2, int* kopuru3, int shoot[], int denbora, int casilla) {
	int num;
	for (num = 0; num < kopuru2; num++) {
		if (shoot[num] == 1 && denbora % 250 == 0) { //DISPARA CADA VEZ QUE EL CONTADOR ES UN MULTIPLO DE 250
			if (disparo(jokalaria, enemigo2[num], casilla) == 1) { //LA DIRECCION QUE TENIA LA FLECHA
				flecha[*kopuru3].pos.x = enemigo2[num].pos.x - casilla;
				flecha[*kopuru3].pos.y = enemigo2[num].pos.y;
				flechaposx[*kopuru3] = enemigo2posx[num] - 1;
				flechaposy[*kopuru3] = enemigo2posy[num];
				direc[*kopuru3] = 1; //PARA QUE SEPA EN QUE DIRECCION AVANZA
			}
			if (disparo(jokalaria, enemigo2[num], casilla) == 2) {//LA DIRECCION QUE TENIA LA FLECHA
				flecha[*kopuru3].pos.x = enemigo2[num].pos.x + casilla;
				flecha[*kopuru3].pos.y = enemigo2[num].pos.y;
				flechaposx[*kopuru3] = enemigo2posx[num] + 1;
				flechaposy[*kopuru3] = enemigo2posy[num];
				direc[*kopuru3] = 2;//PARA QUE SEPA EN QUE DIRECCION AVANZA
			}
			if (disparo(jokalaria, enemigo2[num], casilla) == 3) {//LA DIRECCION QUE TENIA LA FLECHA
				flecha[*kopuru3].pos.y = enemigo2[num].pos.y - casilla;
				flecha[*kopuru3].pos.x = enemigo2[num].pos.x;
				flechaposy[*kopuru3] = enemigo2posy[num] - 1;
				flechaposx[*kopuru3] = enemigo2posx[num];
				direc[*kopuru3] = 3;//PARA QUE SEPA EN QUE DIRECCION AVANZA
			}
			if (disparo(jokalaria, enemigo2[num], casilla) == 4) {//LA DIRECCION QUE TENIA LA FLECHA
				flecha[*kopuru3].pos.y = enemigo2[num].pos.y + casilla;
				flecha[*kopuru3].pos.x = enemigo2[num].pos.x;
				flechaposy[*kopuru3] = enemigo2posy[num] + 1;
				flechaposx[*kopuru3] = enemigo2posx[num];
				direc[*kopuru3] = 4;//PARA QUE SEPA EN QUE DIRECCION AVANZA
			}
			flecha[*kopuru3].id = flechaIrudiaSortu(flecha[*kopuru3], &*spriteKop);
			xSprite[*spriteKop - 1] = 0;
			ySprite[*spriteKop - 1] = 0;
			tamaño[*spriteKop - 1] = 48;
			kont[*kopuru3] = 0;
			*kopuru3 += 1;
			shoot[num] = 0; //PARA QUE VUELVA A DISPARAR TENDRA QUE VOLVER A ENTRAR EN POSICION
		}

	}
}
void flechagolpeo(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA flecha[], int direc[], int xSprite[], int ySprite[], int kont[], int flechaposx[], int flechaposy[], int *spriteKop, int *misko_vida, int *kopuru3, int casilla, int DUNGEON_2[][17]) {
	int num;
	POSIZIOA aux;
	for (num = 0; num < *kopuru3; num++) {
		if (flechazo(jokalaria, flecha[num], casilla, direc[num]) != 0) { //SI RECIBE UN GOLPE
			(*misko_vida)--;
			spriteKendu(flecha[num].id);
			(*spriteKop)--;
			flecha[num] = flecha[*kopuru3 - 1];
			flechaposy[num] = flechaposy[*kopuru3 - 1];
			flechaposx[num] = flechaposx[*kopuru3 - 1];
			*kopuru3 -= 1;
		}
		else {
			if (direc[num] == 1) { //LA DIRECCION EN LA QUE AVANZA
				xSprite[*spriteKop - 1] = 2;
				if (kont[num] % 3 == 0) { //UN CONTADOR PARA QUE NO AVANCE DEMASIADO RAPIDO
					aux = mugimendua_FLECHA_NEGATIVO(flecha[num].pos);
					flecha[num].pos.x = aux.x;
				}
				kont[num] += 1; //EL CONTADOR
				if (kont[num] == 114) { //CADA 38 PIXELES (114 ES 38*3 PORQUE SOLO AVANZA CADA 3 TICKS DE KONT) SE MUEVE EN EL ARRAY
					flechaposx[num] -= 1;
					kont[num] = 0;
				}
			}
			if (direc[num] == 2) { //LA DIRECCION EN LA QUE AVANZA
				xSprite[*spriteKop - 1] = 0;
				if (kont[num] % 3 == 0) {//UN CONTADOR PARA QUE NO AVANCE DEMASIADO RAPIDO
					aux = mugimendua_FLECHA_POSITIVO(flecha[num].pos);
					flecha[num].pos.x = aux.x;
				}
				kont[num] += 1;//EL CONTADOR
				if (kont[num] == 114) { //CADA 38 PIXELES (114 ES 38*3 PORQUE SOLO AVANZA CADA 3 TICKS DE KONT) SE MUEVE EN EL ARRAY
					flechaposx[num] += 1;
					kont[num] = 0;
				}
			}
			if (direc[num] == 3) { //LA DIRECCION EN LA QUE AVANZA
				xSprite[*spriteKop - 1] = 1;
				if (kont[num] % 3 == 0) {//UN CONTADOR PARA QUE NO AVANCE DEMASIADO RAPIDO
					aux = mugimendua_FLECHA_NEGATIVO(flecha[num].pos);
					flecha[num].pos.y = aux.y;
				}
				kont[num] += 1;//EL CONTADOR
				if (kont[num] == 114) { //CADA 38 PIXELES (114 ES 38*3 PORQUE SOLO AVANZA CADA 3 TICKS DE KONT) SE MUEVE EN EL ARRAY
					flechaposy[num] -= 1;
					kont[num] = 0;
				}
			}
			if (direc[num] == 4) { //LA DIRECCION EN LA QUE AVANZA
				xSprite[*spriteKop - 1] = 3;
				if (kont[num] % 3 == 0) {//UN CONTADOR PARA QUE NO AVANCE DEMASIADO RAPIDO
					aux = mugimendua_FLECHA_POSITIVO(flecha[num].pos);
					flecha[num].pos.y = aux.y;
				}
				kont[num] += 1;//EL CONTADOR
				if (kont[num] == 114) { //CADA 38 PIXELES (114 ES 38*3 PORQUE SOLO AVANZA CADA 3 TICKS DE KONT) SE MUEVE EN EL ARRAY
					flechaposy[num] += 1;
					kont[num] = 0;
				}
			}
			if (DUNGEON_2[flechaposy[num]][flechaposx[num]] == 1) { //SI GOLPEA UNA PARED O UN ENEMIGO SE QUITA
				spriteKendu(flecha[num].id);
				(*spriteKop)--;
				flecha[num] = flecha[*kopuru3 - 1];
				flechaposy[num] = flechaposy[*kopuru3 - 1];
				flechaposx[num] = flechaposx[*kopuru3 - 1];
				*kopuru3 -= 1;
			}
		}
	}
}
POSIZIOA mugimendua_FLECHA_POSITIVO(POSIZIOA posizioa) {
	posizioa.y = posizioa.y + 1;
	posizioa.x = posizioa.x + 1;
	return posizioa;
}
POSIZIOA mugimendua_FLECHA_NEGATIVO(POSIZIOA posizioa) {
	posizioa.y = posizioa.y - 1;
	posizioa.x = posizioa.x - 1;
	return posizioa;
}

void crearpersonajes(JOKO_ELEMENTUA enemigo1[], JOKO_ELEMENTUA enemigo2[], int tamaño[], int espera[], int enemigo1posx[], int enemigo1posy[], int enemigo2posx[], int enemigo2posy[], int avanzarx[], int avanzary[], int ene1vidas[], int ene2vidas[], int shoot[], int* spriteKop, int kopuru, int kopuru2) {
	int num;
	//SE CREAN LOS ENEMIGOS Y SE ESTABLECEN TODAS LAS VARIABLES QUE SE UTILIZARAN
	for (num = 0; num < kopuru; num++) {
		enemigo1[num].pos.x = 259;
		enemigo1[num].pos.y = 76 * num + 204;
		enemigo1posx[num] = 7;
		enemigo1posy[num] = 2 * num + 6;
		espera[num] = 0;
		ene1vidas[num] = 5;
		enemigo1[num].id = JOKOA_enemigo1IrudiaSortu(enemigo1[num]);
		*spriteKop += 1;
		avanzarx[num] = 0;
		avanzary[num] = 0;
		tamaño[num + 2] = 48;
	}
	for (num = 0; num < kopuru2; num++) {
		enemigo2[num].pos.x = 373;
		enemigo2[num].pos.y = 76 * num + 204;
		enemigo2posx[num] = 10;
		enemigo2posy[num] = 2 * num + 6;
		shoot[num] = 0;
		ene2vidas[num] = 2;
		enemigo2[num].id = JOKOA_enemigo2IrudiaSortu(enemigo2[num]);
		*spriteKop += 1;
		avanzarx[num + kopuru] = 0;
		avanzary[num + kopuru] = 0;
		tamaño[num + 2 + kopuru] = 48;
	}
}
int JOKOA_enemigo1IrudiaSortu(JOKO_ELEMENTUA oztopoa) {
	int enemigo1Id = -1;
	enemigo1Id = spriteKargatu(JOKOA_ENEMIGO1_IMAGE);
	spriteMugitu(enemigo1Id, oztopoa.pos.x, oztopoa.pos.y);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return enemigo1Id;
}
int JOKOA_enemigo2IrudiaSortu(JOKO_ELEMENTUA oztopoa) {
	int enemigo2Id = -1;
	enemigo2Id = spriteKargatu(JOKOA_ENEMIGO2_IMAGE);
	spriteMugitu(enemigo2Id, oztopoa.pos.x, oztopoa.pos.y);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return enemigo2Id;
}

void movimiento1(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA enemigo1[], int espera[], int enemigo1posx[], int enemigo1posy[], int avanzarx[], int avanzary[], int casilla, int kopuru, int DUNGEON_2[][17]) {
	int num;

	for (num = 0; num < kopuru; num++) {
		if (espera[num] == 0) {
			DUNGEON_2[enemigo1posy[num]][enemigo1posx[num]] = 0;
			if ((jokalaria.pos.x > enemigo1[num].pos.x&& DUNGEON_2[enemigo1posy[num]][enemigo1posx[num] + 1] != 1) || (jokalaria.pos.y > enemigo1[num].pos.y&& DUNGEON_2[enemigo1posy[num] + 1][enemigo1posx[num]] != 1) || (jokalaria.pos.x < enemigo1[num].pos.x && DUNGEON_2[enemigo1posy[num]][enemigo1posx[num] - 1] != 1) || (jokalaria.pos.y < enemigo1[num].pos.y && DUNGEON_2[enemigo1posy[num] - 1][enemigo1posx[num]] != 1)) {
				if (jokalaria.pos.x > enemigo1[num].pos.x&& DUNGEON_2[enemigo1posy[num]][enemigo1posx[num] + 1] != 1) {
					avanzarx[num] = 1;
					enemigo1posx[num] += 1;
				}
				if (jokalaria.pos.y > enemigo1[num].pos.y&& DUNGEON_2[enemigo1posy[num] + 1][enemigo1posx[num]] != 1) {
					avanzary[num] = 1;
					enemigo1posy[num] += 1;
				}
				if (jokalaria.pos.x < enemigo1[num].pos.x && DUNGEON_2[enemigo1posy[num]][enemigo1posx[num] - 1] != 1) {
					avanzarx[num] = 2;
					enemigo1posx[num] -= 1;
				}
				if (jokalaria.pos.y < enemigo1[num].pos.y && DUNGEON_2[enemigo1posy[num] - 1][enemigo1posx[num]] != 1) {
					avanzary[num] = 2;
					enemigo1posy[num] -= 1;
				}
			}
			else {
				if (jokalaria.pos.x > enemigo1[num].pos.x&& jokalaria.pos.y == enemigo1[num].pos.y && DUNGEON_2[enemigo1posy[num]][enemigo1posx[num] + 1] == 1) {
					if (DUNGEON_2[enemigo1posy[num] - 1][enemigo1posx[num] + 1] != 1) {
						avanzarx[num] = 1;
						avanzary[num] = 2;
						enemigo1posx[num] += 1;
						enemigo1posy[num] -= 1;
					}
					else if (DUNGEON_2[enemigo1posy[num] + 1][enemigo1posx[num] + 1] != 1) {
						avanzarx[num] = 1;
						avanzary[num] = 1;
						enemigo1posx[num] += 1;
						enemigo1posy[num] += 1;
					}
				}
				else if (jokalaria.pos.x < enemigo1[num].pos.x && jokalaria.pos.y == enemigo1[num].pos.y && DUNGEON_2[enemigo1posy[num]][enemigo1posx[num] - 1] == 1) {
					if (DUNGEON_2[enemigo1posy[num] - 1][enemigo1posx[num] - 1] != 1) {
						avanzarx[num] = 2;
						avanzary[num] = 2;
						enemigo1posx[num] -= 1;
						enemigo1posy[num] -= 1;
					}
					else if (DUNGEON_2[enemigo1posy[num] + 1][enemigo1posx[num] - 1] != 1) {
						avanzarx[num] = 2;
						avanzary[num] = 1;
						enemigo1posx[num] -= 1;
						enemigo1posy[num] += 1;
					}
				}
				else if (jokalaria.pos.y > enemigo1[num].pos.y&& jokalaria.pos.x == enemigo1[num].pos.x && DUNGEON_2[enemigo1posy[num] + 1][enemigo1posx[num]] == 1) {
					if (DUNGEON_2[enemigo1posy[num] + 1][enemigo1posx[num] - 1] != 1) {
						avanzarx[num] = 2;
						avanzary[num] = 1;
						enemigo1posx[num] -= 1;
						enemigo1posy[num] += 1;
					}
					else if (DUNGEON_2[enemigo1posy[num] + 1][enemigo1posx[num] + 1] != 1) {
						avanzarx[num] = 1;
						avanzary[num] = 1;
						enemigo1posx[num] += 1;
						enemigo1posy[num] += 1;
					}
				}
				else if (jokalaria.pos.y < enemigo1[num].pos.y && jokalaria.pos.x == enemigo1[num].pos.x && DUNGEON_2[enemigo1posy[num] - 1][enemigo1posx[num]] == 1) {
					if (DUNGEON_2[enemigo1posy[num] - 1][enemigo1posx[num] - 1] != 1) {
						avanzarx[num] = 2;
						avanzary[num] = 2;
						enemigo1posx[num] -= 1;
						enemigo1posy[num] -= 1;
					}
					else if (DUNGEON_2[enemigo1posy[num] - 1][enemigo1posx[num] + 1] != 1) {
						avanzarx[num] = 1;
						avanzary[num] = 2;
						enemigo1posx[num] += 1;
						enemigo1posy[num] -= 1;
					}
				}
			}
			DUNGEON_2[enemigo1posy[num]][enemigo1posx[num]] = 1;
		}
		else {
			espera[num] -= 1;
		}
	}
}
void movimiento2(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA enemigo2[], int shoot[], int enemigo2posx[], int enemigo2posy[], int avanzarx[], int avanzary[], int casilla, int kopuru, int kopuru2, int DUNGEON_2[][17]) {
	int num;
	for (num = 0; num < kopuru2; num++) {
		DUNGEON_2[enemigo2posy[num]][enemigo2posx[num]] = 0;
		if ((enemigo2[num].pos.x == jokalaria.pos.x + (3 * casilla) && enemigo2[num].pos.y == jokalaria.pos.y) || (enemigo2[num].pos.x == jokalaria.pos.x - (3 * casilla) && enemigo2[num].pos.y == jokalaria.pos.y) || (enemigo2[num].pos.y == jokalaria.pos.y + (3 * casilla) && enemigo2[num].pos.x == jokalaria.pos.x) || (enemigo2[num].pos.y == jokalaria.pos.y - (3 * casilla) && enemigo2[num].pos.x == jokalaria.pos.x)) shoot[num] = 1;
		else if (enemigo2[num].pos.x < jokalaria.pos.x + (3 * casilla) && enemigo2[num].pos.x > jokalaria.pos.x - (3 * casilla) && enemigo2[num].pos.y < jokalaria.pos.y + (3 * casilla) && enemigo2[num].pos.y > jokalaria.pos.y - (3 * casilla)) {
			if ((jokalaria.pos.x < enemigo2[num].pos.x && DUNGEON_2[enemigo2posy[num]][enemigo2posx[num] + 1] != 1) || (jokalaria.pos.x > enemigo2[num].pos.x&& DUNGEON_2[enemigo2posy[num]][enemigo2posx[num] - 1] != 1) || (jokalaria.pos.y < enemigo2[num].pos.y && DUNGEON_2[enemigo2posy[num] + 1][enemigo2posx[num]] != 1) || (jokalaria.pos.y > enemigo2[num].pos.y&& DUNGEON_2[enemigo2posy[num] - 1][enemigo2posx[num]] != 1)) {
				if (jokalaria.pos.x < enemigo2[num].pos.x && DUNGEON_2[enemigo2posy[num]][enemigo2posx[num] + 1] != 1) {
					avanzarx[num + kopuru] = 1;
					enemigo2posx[num] += 1;
				}
				if (jokalaria.pos.x > enemigo2[num].pos.x&& DUNGEON_2[enemigo2posy[num]][enemigo2posx[num] - 1] != 1) {
					avanzarx[num + kopuru] = 2;
					enemigo2posx[num] -= 1;
				}
				if (jokalaria.pos.y < enemigo2[num].pos.y && DUNGEON_2[enemigo2posy[num] + 1][enemigo2posx[num]] != 1) {
					avanzary[num + kopuru] = 1;
					enemigo2posy[num] += 1;
				}
				if (jokalaria.pos.y > enemigo2[num].pos.y&& DUNGEON_2[enemigo2posy[num] - 1][enemigo2posx[num]] != 1) {
					avanzary[num + kopuru] = 2;
					enemigo2posy[num] -= 1;
				}
			}
			else {
				if (jokalaria.pos.x < enemigo2[num].pos.x) {
					if (jokalaria.pos.y < enemigo2[num].pos.y && DUNGEON_2[enemigo2posy[num] + 1][enemigo2posx[num] + 1] != 1) {
						avanzarx[num + kopuru] = 1;
						avanzary[num + kopuru] = 1;
						enemigo2posx[num] += 1;
						enemigo2posy[num] += 1;
					}
					else if (jokalaria.pos.y > enemigo2[num].pos.y&& DUNGEON_2[enemigo2posy[num] - 1][enemigo2posx[num] + 1] != 1) {
						avanzarx[num + kopuru] = 1;
						avanzary[num + kopuru] = 2;
						enemigo2posx[num] += 1;
						enemigo2posy[num] -= 1;
					}

				}
				else if (jokalaria.pos.x > enemigo2[num].pos.x) {
					if (jokalaria.pos.y < enemigo2[num].pos.y && DUNGEON_2[enemigo2posy[num] + 1][enemigo2posx[num] - 1] != 1) {
						avanzarx[num + kopuru] = 2;
						avanzary[num + kopuru] = 1;
						enemigo2posx[num] -= 1;
						enemigo2posy[num] += 1;
					}
					else if (jokalaria.pos.y > enemigo2[num].pos.y&& DUNGEON_2[enemigo2posy[num] - 1][enemigo2posx[num] - 1] != 1) {
						avanzarx[num + kopuru] = 2;
						avanzary[num + kopuru] = 2;
						enemigo2posx[num] -= 1;
						enemigo2posy[num] -= 1;
					}
				}
			}
		}
		else {
			if (abs(enemigo2[num].pos.x - jokalaria.pos.x) > abs(enemigo2[num].pos.y - jokalaria.pos.y)) {
				if (DUNGEON_2[enemigo2posy[num] - 1][enemigo2posx[num]] != 1 || DUNGEON_2[enemigo2posy[num] + 1][enemigo2posx[num]] != 1 || DUNGEON_2[enemigo2posy[num]][enemigo2posx[num] + 1] != 1 || DUNGEON_2[enemigo2posy[num]][enemigo2posx[num] - 1] != 1) {
					if (jokalaria.pos.y < enemigo2[num].pos.y && DUNGEON_2[enemigo2posy[num] - 1][enemigo2posx[num]] != 1) {
						avanzary[num + kopuru] = 2;
						enemigo2posy[num] -= 1;
					}
					if (jokalaria.pos.y > enemigo2[num].pos.y&& DUNGEON_2[enemigo2posy[num] + 1][enemigo2posx[num]] != 1) {
						avanzary[num + kopuru] = 1;
						enemigo2posy[num] += 1;
					}
					if (jokalaria.pos.x != enemigo2[num].pos.x + (3 * casilla) || jokalaria.pos.x != enemigo2[num].pos.x - (3 * casilla)) {
						if (jokalaria.pos.x > enemigo2[num].pos.x + (3 * casilla) && DUNGEON_2[enemigo2posy[num]][enemigo2posx[num] + 1] != 1) {
							avanzarx[num + kopuru] = 1;
							enemigo2posx[num] += 1;
						}
						if (jokalaria.pos.x < enemigo2[num].pos.x - (3 * casilla) && DUNGEON_2[enemigo2posy[num]][enemigo2posx[num] - 1] != 1) {
							avanzarx[num + kopuru] = 2;
							enemigo2posx[num] -= 1;
						}
					}
				}
				else {
					if (DUNGEON_2[enemigo2posy[num]][enemigo2posx[num] - 1] == 1 && jokalaria.pos.x != enemigo2[num].pos.x - (3 * casilla)) {
						if (DUNGEON_2[enemigo2posy[num] - 1][enemigo2posx[num] - 1] != 1) {
							avanzarx[num + kopuru] = 2;
							avanzary[num + kopuru] = 2;
							enemigo2posx[num] -= 1;
							enemigo2posy[num] -= 1;
						}
						else if (DUNGEON_2[enemigo2posy[num] + 1][enemigo2posx[num] - 1] != 1) {
							avanzarx[num + kopuru] = 2;
							avanzary[num + kopuru] = 1;
							enemigo2posx[num] -= 1;
							enemigo2posy[num] += 1;
						}
					}
					else if (DUNGEON_2[enemigo2posy[num]][enemigo2posx[num] + 1] == 1 && jokalaria.pos.x != enemigo2[num].pos.x + (3 * casilla)) {
						if (DUNGEON_2[enemigo2posy[num] - 1][enemigo2posx[num] + 1] != 1) {
							avanzarx[num + kopuru] = 1;
							avanzary[num + kopuru] = 2;
							enemigo2posx[num] += 1;
							enemigo2posy[num] -= 1;
						}
						else if (DUNGEON_2[enemigo2posy[num] + 1][enemigo2posx[num] + 1] != 1) {
							avanzarx[num + kopuru] = 1;
							avanzary[num + kopuru] = 1;
							enemigo2posx[num] += 1;
							enemigo2posy[num] += 1;
						}
					}
				}
			}
			else {
				if (DUNGEON_2[enemigo2posy[num] - 1][enemigo2posx[num]] != 1 || DUNGEON_2[enemigo2posy[num] + 1][enemigo2posx[num]] != 1 || DUNGEON_2[enemigo2posy[num]][enemigo2posx[num] + 1] != 1 || DUNGEON_2[enemigo2posy[num]][enemigo2posx[num] - 1] != 1) {
					if (jokalaria.pos.x < enemigo2[num].pos.x && DUNGEON_2[enemigo2posy[num]][enemigo2posx[num] - 1] != 1) {
						avanzarx[num + kopuru] = 2;
						enemigo2posx[num] -= 1;
					}
					if (jokalaria.pos.x > enemigo2[num].pos.x&& DUNGEON_2[enemigo2posy[num]][enemigo2posx[num] + 1] != 1) {
						avanzarx[num + kopuru] = 1;
						enemigo2posx[num] += 1;
					}
					if (jokalaria.pos.y != enemigo2[num].pos.y + (3 * casilla) || jokalaria.pos.y != enemigo2[num].pos.y - (3 * casilla)) {
						if (jokalaria.pos.y > enemigo2[num].pos.y + (3 * casilla) && DUNGEON_2[enemigo2posy[num] + 1][enemigo2posx[num]] != 1) {
							avanzary[num + kopuru] = 1;
							enemigo2posy[num] += 1;
						}
						if (jokalaria.pos.y < enemigo2[num].pos.y - (3 * casilla) && DUNGEON_2[enemigo2posy[num] - 1][enemigo2posx[num]] != 1) {
							avanzary[num + kopuru] = 2;
							enemigo2posy[num] -= 1;
						}
					}
				}
				else {
					if (DUNGEON_2[enemigo2posy[num] - 1][enemigo2posx[num]] == 1 && jokalaria.pos.y != enemigo2[num].pos.y - (3 * casilla)) {
						if (DUNGEON_2[enemigo2posy[num] - 1][enemigo2posx[num] - 1] != 1) {
							avanzarx[num + kopuru] = 2;
							avanzary[num + kopuru] = 2;
							enemigo2posx[num] -= 1;
							enemigo2posy[num] -= 1;
						}
						else if (DUNGEON_2[enemigo2posy[num] - 1][enemigo2posx[num] + 1] != 1) {
							avanzarx[num + kopuru] = 1;
							avanzary[num + kopuru] = 2;
							enemigo2posx[num] += 1;
							enemigo2posy[num] -= 1;
						}
					}
					else if (DUNGEON_2[enemigo2posy[num] + 1][enemigo2posx[num]] == 1 && jokalaria.pos.y != enemigo2[num].pos.y + (3 * casilla)) {
						if (DUNGEON_2[enemigo2posy[num] + 1][enemigo2posx[num] - 1] != 1) {
							avanzarx[num + kopuru] = 2;
							avanzary[num + kopuru] = 1;
							enemigo2posx[num] -= 1;
							enemigo2posy[num] += 1;
						}
						else if (DUNGEON_2[enemigo2posy[num] + 1][enemigo2posx[num] + 1] != 1) {
							avanzarx[num + kopuru] = 1;
							avanzary[num + kopuru] = 1;
							enemigo2posx[num] += 1;
							enemigo2posy[num] += 1;
						}
					}
				}
			}
		}
		DUNGEON_2[enemigo2posy[num]][enemigo2posx[num]] = 1;
	}
}
void enemigosprite(JOKO_ELEMENTUA enemigo1[], JOKO_ELEMENTUA enemigo2[], int x[], int y[], int avanzarx[], int avanzary[], int move[], int sprkont[], int spritemove[], int kopuru, int kopuru2, int* t) {
	POSIZIOA aux;
	int num;

	if (*t == 1) { //SI YA SE HAN MOVIDO
		spritemove[1]++;//CONTADOR PARA QUE NO AVANCEN DEMASIADO RAPIDO
		if (spritemove[1] > 70) {
			for (num = 0; num < kopuru; num++) {
				if (avanzary[num] == 1) {//HACIA DONDE HAN AVANZADO
					aux = mugimendua_PLAYER_POSITIVO(enemigo1[num].pos);
					enemigo1[num].pos.y = aux.y;
					if (avanzarx[num] == 0) { //EL SPRITE SE MOVERA EN Y SI NO HA AVANZADO EN X, PARA QUE NO LO HAGA 2 VECES
						x[num + 2] = move[sprkont[1]];
						y[num + 2] = 0;
					}
					if (sprkont[1] == 2) enemigo1[num].pos.y += 1;
					if (sprkont[1] == 5) {
						enemigo1[num].pos.y += 1;
						avanzary[num] = 0;
					}
				}
				if (avanzary[num] == 2) {//HACIA DONDE HAN AVANZADO
					aux = mugimendua_PLAYER_NEGATIVO(enemigo1[num].pos);
					enemigo1[num].pos.y = aux.y;
					if (avanzarx[num] == 0) { //EL SPRITE SE MOVERA EN Y SI NO HA AVANZADO EN X, PARA QUE NO LO HAGA 2 VECES
						y[num + 2] = 3;
						x[num + 2] = move[sprkont[1]];
					}
					if (sprkont[1] == 2) enemigo1[num].pos.y -= 1; //COMO 38 DIVIDIDO ENTRE 6 SE DESFASAN 2 PIXELES, LOS AVANZAMOS EN EL TERCER Y EL ULTIMO MOVIMIENTO
					if (sprkont[1] == 5) {
						enemigo1[num].pos.y -= 1;
						avanzary[num] = 0;
					}
				}
				if (avanzarx[num] == 2) {//HACIA DONDE HAN AVANZADO
					aux = mugimendua_PLAYER_NEGATIVO(enemigo1[num].pos);
					enemigo1[num].pos.x = aux.x;
					x[num + 2] = move[sprkont[1]];
					y[num + 2] = 1;
					if (sprkont[1] == 2) enemigo1[num].pos.x -= 1;//COMO 38 DIVIDIDO ENTRE 6 SE DESFASAN 2 PIXELES, LOS AVANZAMOS EN EL TERCER Y EL ULTIMO MOVIMIENTO
					if (sprkont[1] == 5) {
						enemigo1[num].pos.x -= 1;
						avanzarx[num] = 0;
					}
				}
				if (avanzarx[num] == 1) {//HACIA DONDE HAN AVANZADO
					aux = mugimendua_PLAYER_POSITIVO(enemigo1[num].pos);
					enemigo1[num].pos.x = aux.x;
					x[num + 2] = move[sprkont[1]];
					y[num + 2] = 2;
					if (sprkont[1] == 2) enemigo1[num].pos.x += 1;//COMO 38 DIVIDIDO ENTRE 6 SE DESFASAN 2 PIXELES, LOS AVANZAMOS EN EL TERCER Y EL ULTIMO MOVIMIENTO
					if (sprkont[1] == 5) {
						enemigo1[num].pos.x += 1;
						avanzarx[num] = 0;
					}
				}
			}
			for (num = 0; num < kopuru2; num++) {
				if (avanzary[num + kopuru] == 1) {//HACIA DONDE HAN AVANZADO
					aux = mugimendua_PLAYER_POSITIVO(enemigo2[num].pos);
					enemigo2[num].pos.y = aux.y;
					if (avanzarx[num + kopuru] == 0) { //EL SPRITE SE MOVERA EN Y SI NO HA AVANZADO EN X, PARA QUE NO LO HAGA 2 VECES
						x[num + 2 + kopuru] = move[sprkont[1]];
						y[num + 2 + kopuru] = 0;
					}
					if (sprkont[1] == 2) enemigo2[num].pos.y += 1;//COMO 38 DIVIDIDO ENTRE 6 SE DESFASAN 2 PIXELES, LOS AVANZAMOS EN EL TERCER Y EL ULTIMO MOVIMIENTO
					if (sprkont[1] == 5) {
						enemigo2[num].pos.y += 1;
						avanzary[num + kopuru] = 0;
					}
				}
				if (avanzary[num + kopuru] == 2) {//HACIA DONDE HAN AVANZADO
					aux = mugimendua_PLAYER_NEGATIVO(enemigo2[num].pos);
					enemigo2[num].pos.y = aux.y;
					if (avanzarx[num] == 0) { //EL SPRITE SE MOVERA EN Y SI NO HA AVANZADO EN X, PARA QUE NO LO HAGA 2 VECES
						x[num + 2 + kopuru] = move[sprkont[1]];
						y[num + 2 + kopuru] = 3;
					}
					if (sprkont[1] == 2) enemigo2[num].pos.y -= 1;//COMO 38 DIVIDIDO ENTRE 6 SE DESFASAN 2 PIXELES, LOS AVANZAMOS EN EL TERCER Y EL ULTIMO MOVIMIENTO
					if (sprkont[1] == 5) {
						enemigo2[num].pos.y -= 1;
						avanzary[num + kopuru] = 0;
					}
				}
				if (avanzarx[num + kopuru] == 2) {//HACIA DONDE HAN AVANZADO
					aux = mugimendua_PLAYER_NEGATIVO(enemigo2[num].pos);
					enemigo2[num].pos.x = aux.x;
					x[num + 2 + kopuru] = move[sprkont[1]];
					y[num + 2 + kopuru] = 1;
					if (sprkont[1] == 2) enemigo2[num].pos.x -= 1;//COMO 38 DIVIDIDO ENTRE 6 SE DESFASAN 2 PIXELES, LOS AVANZAMOS EN EL TERCER Y EL ULTIMO MOVIMIENTO
					if (sprkont[1] == 5) {
						enemigo2[num].pos.x -= 1;
						avanzarx[num + kopuru] = 0;
					}
				}
				if (avanzarx[num + kopuru] == 1) {//HACIA DONDE HAN AVANZADO
					aux = mugimendua_PLAYER_POSITIVO(enemigo2[num].pos);
					enemigo2[num].pos.x = aux.x;
					x[num + 2 + kopuru] = move[sprkont[1]];
					y[num + 2 + kopuru] = 2;
					if (sprkont[1] == 2) enemigo2[num].pos.x += 1;//COMO 38 DIVIDIDO ENTRE 6 SE DESFASAN 2 PIXELES, LOS AVANZAMOS EN EL TERCER Y EL ULTIMO MOVIMIENTO
					if (sprkont[1] == 5) {
						enemigo2[num].pos.x += 1;
						avanzarx[num + kopuru] = 0;
					}
				}
			}
			spritemove[1] = 0; //CONTADOR A 0
			sprkont[1]++;//CONTADOR DE CUANTOS MOVIMIENTOS HA HECHO +1
			if (sprkont[1] == 6) { //SI YA HAN HECHO LOS 6 MOVIMIENTOS PARAN DE AVANZAR
				sprkont[1] = 0;
				*t = 0;
			}

		}
	}

}
JOKO_ELEMENTUA hostiaerantzun(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA enemigo1[], int espera[], int kopuru, int casilla, int* ataque, int* vidas, int* jokalariaPosX, int* jokalariaPosY, int DUNGEON_2[][17]) {
	int num;

	for (num = 0; num < kopuru; num++) {
		if (hostias(jokalaria, enemigo1[num], casilla) != 0) { //SI LE HAN GOLPEADO, DEPENDIENDO DE LA DIRECCION SE MOVERA EN LA CONTRARIA
			Sleep(500);
			if (hostias(jokalaria, enemigo1[num], casilla) == 1 && DUNGEON_2[*jokalariaPosY][*jokalariaPosX + 1] != 1) {
				jokalaria.pos.x += casilla;
				(*jokalariaPosX)++;
			}
			else if (hostias(jokalaria, enemigo1[num], casilla) == 2 && DUNGEON_2[*jokalariaPosY][*jokalariaPosX - 1] != 1) {
				jokalaria.pos.x -= casilla;
				(*jokalariaPosX)--;
			}
			else if (hostias(jokalaria, enemigo1[num], casilla) == 3 && DUNGEON_2[*jokalariaPosY + 1][*jokalariaPosX] != 1) {
				jokalaria.pos.y += casilla;
				(*jokalariaPosY)++;
			}
			else if (hostias(jokalaria, enemigo1[num], casilla) == 4 && DUNGEON_2[*jokalariaPosY - 1][*jokalariaPosX] != 1) {
				jokalaria.pos.y -= casilla;
				(*jokalariaPosY)--;
			}
			espera[num] = 2; //EL ENEMIGO QUE LE HA GOLPEADO NO AVANZARA EN LAS PROXIMAS 2 VUELTAS
			*vidas -= 1;
			*ataque = 0; //PIERDE EL ATAQUE
		}
	}
	return jokalaria;
}
int hostias(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa, int casilla) {
	int talka = 0;
	//SI UN ENEMIGO ENTRA EN SU HITBOX RECIBE UN GOLPE
	if (jokalaria.pos.x == oztopoa.pos.x + casilla && jokalaria.pos.y == oztopoa.pos.y) talka = 1;
	else if (jokalaria.pos.x == oztopoa.pos.x - casilla && jokalaria.pos.y == oztopoa.pos.y) talka = 2;
	else if (jokalaria.pos.y == oztopoa.pos.y + casilla && jokalaria.pos.x == oztopoa.pos.x) talka = 3;
	else if (jokalaria.pos.y == oztopoa.pos.y - casilla && jokalaria.pos.x == oztopoa.pos.x) talka = 4;
	return talka;
}

void vidasprite(int vidas, int tamaño[], int xSprite[], int ySprite[], int num) {
	//DEPENDIENDO DE LAS VIDAS EL SPRITE SE MUEVE
	if (vidas == 3) {
		xSprite[num] = 0;
	}
	if (vidas == 2) {
		xSprite[num] = 1;
	}
	if (vidas == 1) {
		xSprite[num] = 2;
	}
}

