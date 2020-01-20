#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include "defineak.h"
#include "hasieraEtaAmaiera.h"
#include "puzzleak.h"
#include "mugimendua.h"
#include "OurTypes.h"
#include "etsaiak.h"

//PUZLE 2
void puzle2() {

	JOKO_ELEMENTUA fondo, mapa, fondo_win;
	JOKO_ELEMENTUA PILOTAK[6];

	Mix_Chunk* irabazi_soinua;//SONIDOS CORTO = CHUNK
	irabazi_soinua = Mix_LoadWAV(IRABAZI_SOINUA);
	Mix_VolumeChunk(irabazi_soinua, 50);

	posicionesPELOTAS(PILOTAK);//las posiciones de todos los objetos

	int ebentu, i = 0, click = 0, j = 0;
	int irabazi = 0;
	POSIZIOA sagua;

	fondo.id = JOKOA_objetuarenIrudiaSortu(P2_HASIERA);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	do {
		ebentu = ebentuaJasoGertatuBada();
	} while (ebentu != TECLA_RETURN);//MIENTRAS NO LE DES A RETURN NO EMPIEZA EL PUZZLE
	irudiaKendu(fondo.id);
	mapa.id = JOKOA_objetuarenIrudiaSortu(P2_JOKOA);

	PILOTAK[0].id = JOKOA_objetuarenIrudiaSortu(NUMERO_2);
	irudiaMugitu(PILOTAK[0].id, PILOTAK[0].pos.x, PILOTAK[0].pos.y);
	PILOTAK[1].id = JOKOA_objetuarenIrudiaSortu(NUMERO_4);
	irudiaMugitu(PILOTAK[1].id, PILOTAK[1].pos.x, PILOTAK[1].pos.y);
	PILOTAK[2].id = JOKOA_objetuarenIrudiaSortu(NUMERO_7);
	irudiaMugitu(PILOTAK[2].id, PILOTAK[2].pos.x, PILOTAK[2].pos.y);
	PILOTAK[3].id = JOKOA_objetuarenIrudiaSortu(NUMERO_10);
	irudiaMugitu(PILOTAK[3].id, PILOTAK[3].pos.x, PILOTAK[3].pos.y);
	PILOTAK[4].id = JOKOA_objetuarenIrudiaSortu(NUMERO_11);
	irudiaMugitu(PILOTAK[4].id, PILOTAK[4].pos.x, PILOTAK[4].pos.y);
	PILOTAK[5].id = JOKOA_objetuarenIrudiaSortu(NUMERO_12);
	irudiaMugitu(PILOTAK[5].id, PILOTAK[5].pos.x, PILOTAK[5].pos.y);

	dialogoPuzzle(ebentu, AZALPENA_PUZZLE_2);

	do {
		ebentu = ebentuaJasoGertatuBada();
		if (ebentu == SAGU_BOTOIA_EZKERRA) {
			sagua = saguarenPosizioa();
			i = 0;
			click = nonKlickEgin(sagua, PILOTAK, &j, i);
			if (click == 1) {//SABER SI CLICKAS EN UNO DE LOS NUMEROS
				sagua = posBerria(sagua, ebentu);//NO SALE DE AQUI HASTA QUE VUELVES A HACER CLICK PARA DEJAR EL NUMERO
				sagua = konprobatuZirkBeltzBarruan(sagua);//MIRA SI CLICKAS DENTRO DE UN CIRCULO NEGRO Y SI LO HACES LO PONE EN UNA POSICION FINJA
				PILOTAK[j].pos.x = sagua.x;
				PILOTAK[j].pos.y = sagua.y;
				irudiaMugitu(PILOTAK[j].id, PILOTAK[j].pos.x, PILOTAK[j].pos.y);//MUEVE SOLO EL NUMERO QUE HAS MOVIDO
				click = 0;
			}
		}
		if (click == 3) {//PISTA
			PILOTAK[5].pos.x = 587;
			PILOTAK[5].pos.y = 350;
			irudiaMugitu(PILOTAK[5].id, PILOTAK[5].pos.x, PILOTAK[5].pos.y);//PONE EL NUMERO 12 EN SU POSICION
			click = 0;
		}
		else if (click == 4) {//REINICIA EL PUZZLE
			posicionesPELOTAS(PILOTAK);//PONE LAS POSICIONES DEL INICIO
			for (i = 0; i < 6; i++) {//LAS MUEVE A SU NUEVA POSICION
				irudiaMugitu(PILOTAK[i].id, PILOTAK[i].pos.x, PILOTAK[i].pos.y);
			}
			click = 0;
		}
		else if (click == 5) {//AZALPENA
			dialogoPuzzle(ebentu, AZALPENA_PUZZLE_2);//LE VUELVE A EXPLICAR EL PUZZLE
			click = 0;
		}
		if (konprobatuPuzlea2(PILOTAK) == 1 && click == 2) {//SI LE DA A KONPROBATU Y EL PUZZLE ESTA BIEN // EN konprobatuPuzlea2 estan todas las posiciones de los resultados
			irabazi = 1;
		}
		else if (click == 2) {//SI LE DA A KONPROBATU Y EL PUZZLE ESTA MAL
			dialogoPuzzle(ebentu, GAIZKI_PUZZLE_2);//LE DICE QUE ESTA MAL
			click = 0;
		}
		if (ebentu == GERTAERA_IRTEN) {
			sgItxi();
		}
		pantailaGarbitu();
		irudiakMarraztu();
		pantailaBerriztu();

	} while (irabazi == 0);

	for (i = 0; i < 6; i++) {
		irudiaKendu(PILOTAK[i].id);
	}
	irudiaKendu(mapa.id);
	pantailaBerriztu();

	fondo_win.id = JOKOA_objetuarenIrudiaSortu(P2_AMAIERA);
	Mix_PlayChannel(-1, irabazi_soinua, 0);
	irudiakMarraztu();
	pantailaBerriztu();

	do {
		ebentu = ebentuaJasoGertatuBada();
	} while (ebentu != TECLA_RETURN);

	irudiaKendu(fondo_win.id);
	pantailaGarbitu();
	pantailaBerriztu();

}
void posicionesPELOTAS(JOKO_ELEMENTUA PILOTAK[]) {
	PILOTAK[0].pos.x = 94;
	PILOTAK[0].pos.y = 50;
	PILOTAK[1].pos.x = 94;
	PILOTAK[1].pos.y = 170;
	PILOTAK[2].pos.x = 94;
	PILOTAK[2].pos.y = 290;
	PILOTAK[3].pos.x = 19;
	PILOTAK[3].pos.y = 50;
	PILOTAK[4].pos.x = 19;
	PILOTAK[4].pos.y = 170;
	PILOTAK[5].pos.x = 19;
	PILOTAK[5].pos.y = 290;

}
POSIZIOA posBerria(POSIZIOA sagua, int ebentu) {

	ebentu = 0;
	while (ebentu != SAGU_BOTOIA_EZKERRA) {
		ebentu = ebentuaJasoGertatuBada();
	}
	sagua = saguarenPosizioa();
	sagua.x -= 30;
	sagua.y -= 30;

	return sagua;
}
POSIZIOA konprobatuZirkBeltzBarruan(POSIZIOA sagua) {

	int aurkitu = 0;
	//61
	if (sagua.x > 290 && sagua.x < 351 && sagua.y > 134 && sagua.y < 195) {//izquierda del 9
		aurkitu = 1;
		sagua.x = 320;
		sagua.y = 164;
	}
	else if (sagua.x > 477 && sagua.x < 538 && sagua.y > 134 && sagua.y < 195) {//derecha del 9
		aurkitu = 1;
		sagua.x = 507;
		sagua.y = 164;
	}
	else if (sagua.x > 413 && sagua.x < 474 && sagua.y > 179 && sagua.y < 240) {//derecha del 8
		aurkitu = 1;
		sagua.x = 443;
		sagua.y = 209;
	}
	else if (sagua.x > 387 && sagua.x < 448 && sagua.y > 232 && sagua.y < 293) {//una vez a la izquierda del 5
		aurkitu = 1;
		sagua.x = 417;
		sagua.y = 262;
	}
	else if (sagua.x > 330 && sagua.x < 391 && sagua.y > 232 && sagua.y < 293) {//dos veces a la izquierda del 5
		aurkitu = 1;
		sagua.x = 360;
		sagua.y = 262;
	}
	else if (sagua.x > 557 && sagua.x < 618 && sagua.y > 320 && sagua.y < 381) {//derecha abajo del todo
		aurkitu = 1;
		sagua.x = 587;
		sagua.y = 350;
	}
	return sagua;
}
int konprobatuPuzlea2(JOKO_ELEMENTUA PILOTAK[]) {

	int irabazi = 0;
	if (PILOTAK[0].pos.x == 360 && PILOTAK[0].pos.y == 262) {//2
		if (PILOTAK[5].pos.x == 587 && PILOTAK[5].pos.y == 350) {//12
			if ((PILOTAK[1].pos.x == 443 && PILOTAK[1].pos.y == 209)) {//4 arriba del 5
				if ((PILOTAK[4].pos.x == 417 && PILOTAK[4].pos.y == 262)) {//11 izquieda el 5
					if ((PILOTAK[3].pos.x == 507 && PILOTAK[3].pos.y == 164)) {//10 derecha del 9
						if ((PILOTAK[2].pos.x == 320 && PILOTAK[2].pos.y == 164)) {//7 izquierda del 9
							irabazi = 1;
						}
					}
					else if ((PILOTAK[3].pos.x == 320 && PILOTAK[3].pos.y == 164)) {//10 izquierda del 9
						if ((PILOTAK[2].pos.x == 507 && PILOTAK[2].pos.y == 164)) {//7 derecha del 9
							irabazi = 1;
						}
					}
				}
			}
			else if ((PILOTAK[1].pos.x == 417 && PILOTAK[1].pos.y == 262)) {//4 izquierda del 5
				if ((PILOTAK[4].pos.x == 443 && PILOTAK[4].pos.y == 209)) {//11 arriba del 5
					if ((PILOTAK[3].pos.x == 507 && PILOTAK[3].pos.y == 164)) {//10 derecha del 9
						if ((PILOTAK[2].pos.x == 320 && PILOTAK[2].pos.y == 164)) {//7 izquierda del 9
							irabazi = 1;
						}
					}
					else if ((PILOTAK[3].pos.x == 320 && PILOTAK[3].pos.y == 164)) {//10 izquierda del 9
						if ((PILOTAK[2].pos.x == 507 && PILOTAK[2].pos.y == 164)) {//7 derecha del 9
							irabazi = 1;
						}
					}
				}
			}
		}
	}
	return irabazi;
}
int nonKlickEgin(POSIZIOA sagua, JOKO_ELEMENTUA PILOTAK[], int* j, int i) {

	int click = 0;
	while (i < 6 && click == 0) {
		if (sagua.x > PILOTAK[i].pos.x&& sagua.x < PILOTAK[i].pos.x + 61 && sagua.y > PILOTAK[i].pos.y&& sagua.y < PILOTAK[i].pos.y + 61) {
			click = 1;
			*j = i;
		}
		i++;
	}
	if (sagua.x > 439 && sagua.x < 619 && sagua.y > 412 && sagua.y < 466) {
		click = 2;//konprobatu
	}
	if (sagua.x > 10 && sagua.x < 190 && sagua.y > 412 && sagua.y < 466) {
		click = 3;//pista
	}
	if (sagua.x > 229 && sagua.x < 409 && sagua.y > 412 && sagua.y < 466) {
		click = 4;//berrabiatu
	}
	if (sagua.x > 534 && sagua.x < 612 && sagua.y > 20 && sagua.y < 90) {
		click = 5;
	}
	return click;
}

//PUZLE 3
void puzle3(int xSprite[], int ySprite[], int spriteKop, int tamaño[], int move[], int spriteMove[], int spriteKont[], int mirar[], JOKO_ELEMENTUA* jokalaria) {

	int MAPA_PUZLE_3[13][17] = {
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	5,	0,	0,	12,	0,	0,	5,	1,	5,	0,	0,	12,	0,	0,	5,	1},
{1,	5,	0,	1,	0,	5,	0,	5,	1,	5,	5,	5,	0,	5,	5,	5,	1},
{1,	5,	0,	1,	0,	0,	0,	1,	1,	1,	0,	0,	0,	0,	0,	5,	1},
{1,	5,	0,	0,	5,	0,	0,	5,	1,	5,	0,	0,	5,	0,	0,	5,	1},
{1,	5,	1,	0,	0,	5,	0,	5,	1,	5,	0,	0,	0,	0,	0,	5,	1},
{1,	5,	0,	0,	0,	0,	0,	5,	1,	5,	0,	1,	0,	1,	0,	5,	1},
{1,	5,	0,	0,	5,	0,	0,	5,	1,	5,	0,	0,	5,	0,	0,	5,	1},
{1,	5,	0,	0,	0,	0,	0,	5,	1,	5,	0,	0,	1,	0,	0,	5,	1},
{1,	5,	0,	0,	0,	5,	0,	5,	1,	5,	0,	0,	0,	5,	0,	5,	1},
{1,	5,	5,	0,	0,	0,	1,	5,	1,	5,	5,	5,	0,	0,	0,	5,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
	};
	JOKO_ELEMENTUA jokalaria2, MAPA, fondo, fondo_win;
	spriteKop = 3;
	Mix_Chunk* irabazi_soinua;
	irabazi_soinua = Mix_LoadWAV(IRABAZI_SOINUA);
	Mix_VolumeChunk(irabazi_soinua, 50);

	int ebentu, irabazi = 0;

	int jokalaria1Posy;
	int jokalaria1PosX;
	int jokalaria2Posy;
	int jokalaria2PosX;
	tamaño[2] = 48;
	xSprite[0] = 0;
	ySprite[2] = 0;
	mirar[0] = 1;
	mirar[2] = 1;

	fondo.id = JOKOA_objetuarenIrudiaSortu(P3_HASIERA);

	do {
		ebentu = ebentuaJasoGertatuBada();
	} while (ebentu != TECLA_RETURN);
	irudiaKendu(fondo.id);

	MAPA.id = JOKOA_objetuarenIrudiaSortu(P3_JOKOA);
	posicionesJOKOA(*&jokalaria, &jokalaria2, &jokalaria1Posy, &jokalaria1PosX, &jokalaria2Posy, &jokalaria2PosX);

	jokalaria2.id = JOKOA_spritearenIrudiaSortu(TABER);
	spriteMugitu(jokalaria2.id, jokalaria2.pos.x, jokalaria2.pos.y);
	spriteMugitu(jokalaria->id, jokalaria->pos.x, jokalaria->pos.y);
	pantailaGarbitu();
	irudiakMarraztu();
	spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);
	pantailaBerriztu();

	do {
		ebentu = ebentuaJasoGertatuBada();

		pertsonaiarenMugimendua(mirar, spriteMove, xSprite, ySprite, ebentu, spriteKont, *&jokalaria, &jokalaria1PosX, &jokalaria1Posy, 0);
		pertsonaiarenMugimendua(mirar, spriteMove, xSprite, ySprite, ebentu, spriteKont, &jokalaria2, &jokalaria2PosX, &jokalaria2Posy, 2);

		if (MAPA_PUZLE_3[jokalaria1Posy + 1][jokalaria1PosX] == 1 && mirar[0] == 5) {
			mirar[0] = 1;
		}
		if (MAPA_PUZLE_3[jokalaria1Posy][jokalaria1PosX - 1] == 1 && mirar[0] == 6) {
			mirar[0] = 2;
		}
		if (MAPA_PUZLE_3[jokalaria1Posy][jokalaria1PosX + 1] == 1 && mirar[0] == 7) {
			mirar[0] = 3;
		}
		if (MAPA_PUZLE_3[jokalaria1Posy - 1][jokalaria1PosX] == 1 && mirar[0] == 8) {
			mirar[0] = 4;
		}
		if (MAPA_PUZLE_3[jokalaria2Posy + 1][jokalaria2PosX] == 1 && mirar[1] == 5) {
			mirar[2] = 1;
		}
		if (MAPA_PUZLE_3[jokalaria2Posy][jokalaria2PosX - 1] == 1 && mirar[1] == 6) {
			mirar[2] = 2;
		}
		if (MAPA_PUZLE_3[jokalaria2Posy][jokalaria2PosX + 1] == 1 && mirar[1] == 7) {
			mirar[2] = 3;
		}
		if (MAPA_PUZLE_3[jokalaria2Posy - 1][jokalaria2PosX] == 1 && mirar[1] == 8) {
			mirar[2] = 4;
		}

		if (MAPA_PUZLE_3[jokalaria1Posy][jokalaria1PosX] == 5 || MAPA_PUZLE_3[jokalaria2Posy][jokalaria2PosX] == 5) {
			SDL_Delay(20);
			posicionesJOKOA(*&jokalaria, &jokalaria2, &jokalaria1Posy, &jokalaria1PosX, &jokalaria2Posy, &jokalaria2PosX);
		}
		if (MAPA_PUZLE_3[jokalaria1Posy][jokalaria1PosX] == 12 && MAPA_PUZLE_3[jokalaria2Posy][jokalaria2PosX] == 12) {
			irabazi = 1;
		}
		if (ebentu == GERTAERA_IRTEN) {
			sgItxi();
		}
		spriteMugitu(jokalaria->id, jokalaria->pos.x, jokalaria->pos.y);
		spriteMugitu(jokalaria2.id, jokalaria2.pos.x, jokalaria2.pos.y);
		irudiakMarraztu();
		spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);
		pantailaBerriztu();
	} while (irabazi == 0);


	irudiaKendu(MAPA.id);
	spriteKendu(jokalaria2.id);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	fondo_win.id = JOKOA_objetuarenIrudiaSortu(P3_AMAIERA);
	Mix_PlayChannel(-1, irabazi_soinua, 0);
	irudiakMarraztu();
	pantailaBerriztu();

	do {
		ebentu = ebentuaJasoGertatuBada();
	} while (ebentu != TECLA_RETURN);

	irudiaKendu(fondo_win.id);
	pantailaGarbitu();
	pantailaBerriztu();

}
void posicionesJOKOA(JOKO_ELEMENTUA* jokalaria1, JOKO_ELEMENTUA* jokalaria2, int* jokalaria1Posy, int* jokalaria1PosX, int* jokalaria2Posy, int* jokalaria2PosX) {
	jokalaria1->pos.x = 104;
	jokalaria1->pos.y = 54;
	*jokalaria1Posy = 2;
	*jokalaria1PosX = 3;
	jokalaria2->pos.x = 484;
	jokalaria2->pos.y = 54;
	*jokalaria2Posy = 2;
	*jokalaria2PosX = 13;
}

void dialogoConversacion(int ebentu, char* irudia, int xSprite[], int ySprite[], int spriteKop, int tamaño[]) {

	JOKO_ELEMENTUA conversacion;

	conversacion.pos.x = 10;
	conversacion.pos.y = 290;

	conversacion.id = JOKOA_objetuarenIrudiaSortu(irudia);
	irudiaMugitu(conversacion.id, conversacion.pos.x, conversacion.pos.y);
	pantailaGarbitu();
	irudiakMarraztu();
	spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);
	pantailaBerriztu();

	do {
		ebentu = ebentuaJasoGertatuBada();
	} while (ebentu != TECLA_e);
	irudiaKendu(conversacion.id);
}
void dialogoPuzzle(int ebentu, char* irudia) {

	JOKO_ELEMENTUA conversacion;

	conversacion.pos.x = 10;
	conversacion.pos.y = 290;

	conversacion.id = JOKOA_objetuarenIrudiaSortu(irudia);
	irudiaMugitu(conversacion.id, conversacion.pos.x, conversacion.pos.y);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	do {
		ebentu = ebentuaJasoGertatuBada();
	} while (ebentu != TECLA_e);
	irudiaKendu(conversacion.id);
}

//PUZLE 1
void puzle1_hasieraAmaieraPantaila() {//FUNTZIO HAU PUZZLE 1 HASIERATZEKO ETA AMAITZEKO BALIO DU
	JOKO_ELEMENTUA hasiera, amaiera;

	Mix_Chunk* irabazi;
	irabazi = Mix_LoadWAV(IRABAZI_SOINUA);
	Mix_VolumeChunk(irabazi, 50);

	int ebentu = 0;
	//HASIERAKO PANTAILA JARRI
	hasiera.id = JOKOA_objetuarenIrudiaSortu(P1_HASIERA);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	do {
		ebentu = ebentuaJasoGertatuBada();
	} while (ebentu != TECLA_RETURN);//RETURN TECLA SAKATZEN EZ DUZUN BITARTEAN HASIERAKO PANTAILA EZ DA KENDUKO

	irudiaKendu(hasiera.id);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	puzle1();//PUZZLE 1 HASI
	//AMAIERAKO PANTAILA JARRI
	amaiera.id = JOKOA_objetuarenIrudiaSortu(P1_AMAIERA);
	Mix_PlayChannel(-1, irabazi, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	do {
		ebentu = ebentuaJasoGertatuBada();
	} while (ebentu != TECLA_RETURN);//RETURN TECLA SAKATZEN EZ DUZUN BITARTEAN AMAIERAKO PANTAILA EZ DA KENDUKO

	irudiaKendu(amaiera.id);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
}
void puzle1_objetuakMarraztu(PUZZLE1 daga[], PUZZLE1* vino, DAGA orientacion[], int* vinoPosY, int* vinoPosX) {//JOKOAREN ZEHAR ALDATZEN DIREN OBJEKTUAK MARRAZTEKO
	int i;
	//DAGA BAKOITZAREN POSIZIOA
	daga[0].pos.x = 301;
	daga[0].pos.y = 110;
	daga[1].pos.x = 301;
	daga[1].pos.y = 143;
	daga[2].pos.x = 189;
	daga[2].pos.y = 175;
	daga[3].pos.x = 414;
	daga[3].pos.y = 175;
	daga[4].pos.x = 414;
	daga[4].pos.y = 208;
	daga[5].pos.x = 151;
	daga[5].pos.y = 273;
	daga[6].pos.x = 339;
	daga[6].pos.y = 273;
	daga[7].pos.x = 265;
	daga[7].pos.y = 306;
	daga[8].pos.x = 377;
	daga[8].pos.y = 373;

	for (i = 0; i <= 8; i++) {//DAGA GUZTIAK MARRAZTEKO
		if (daga[i].orientacion != orientacion[i]) {
			daga[i].orientacion = orientacion[i];
			if (orientacion[i] == IZQ) {
				daga[i].id = JOKOA_objetuarenIrudiaSortu(DAGAI);
			}
			else if (orientacion[i] == DER) {
				daga[i].id = JOKOA_objetuarenIrudiaSortu(DAGAD);
			}
			irudiaMugitu(daga[i].id, daga[i].pos.x, daga[i].pos.y);
			pantailaGarbitu();
			irudiakMarraztu();
			pantailaBerriztu();
		}
	}

	//ARDOA MARRAZTEKO
	*vinoPosX = 1;
	*vinoPosY = 1;
	vino->norantza = MENDE;
	vino->pos.x = 151;
	vino->pos.y = 108;
	vino->id = JOKOA_objetuarenIrudiaSortu(VINO);
	irudiaMugitu(vino->id, vino->pos.x, vino->pos.y);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
}
void puzle1_objetuakEzabatu(PUZZLE1 daga[], PUZZLE1* vino) {//JOKOAREN ZEHAR ALDATZEN DIREN OBJEKTU GUZTIAK EZABATZEKO
	int i;
	for (i = 0; i <= 8; i++) {
		irudiaKendu(daga[i].id);
		pantailaGarbitu();
		pantailaBerriztu();
	}
	irudiaKendu(vino->id);
}
void puzle1_aldatutakoObjetuakEzabatu(PUZZLE1 daga[], PUZZLE1* vino, DAGA orientacion[]) {//JOKOAREN ZEHAR ALDATZEN DIREN BAKARRIK ALDATUTAKO OBJEKTUAK  EZABATZEKO
	int i;
	for (i = 0; i <= 8; i++) {
		if (daga[i].orientacion != orientacion[i]) {//Si la orientacion actual de la daga es diferente a la orientacion predeterminada, la borra
			irudiaKendu(daga[i].id);
		}
		pantailaGarbitu();
		pantailaBerriztu();
	}
	irudiaKendu(vino->id);
}
void puzle1() {//PUZZLEAREN MAIN-A
	PUZZLE1 conversacion, fondo, cerveza, daga[9], vino;
	DAGA orientacion[9] = { DER,IZQ,DER,DER,DER,IZQ,IZQ,DER,IZQ };//DAGEN HASIERAKO ORIENTAZIOA

	int ebentu = 0, irabazi = 0;
	//OBJEKTUAK MARRAZTU ETA HASIERATU
	int cervezaPosX = 6, cervezaPosY = 4;
	cerveza.pos.x = 339;
	cerveza.pos.y = 206;
	int vinoPosX = 1, vinoPosY = 1;

	fondo.id = JOKOA_objetuarenIrudiaSortu(P1_JOKOA);
	puzle1_objetuakMarraztu(daga, &vino, orientacion, &vinoPosY, &vinoPosX);
	cerveza.id = JOKOA_objetuarenIrudiaSortu(CERVEZA);
	irudiaMugitu(cerveza.id, cerveza.pos.x, cerveza.pos.y);
	conversacion.id = JOKOA_objetuarenIrudiaSortu(TABERNARIA_AZALPENA1);
	irudiaMugitu(conversacion.id, 10, 290);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	do {
		ebentu = ebentuaJasoGertatuBada();
	} while (ebentu != TECLA_e && ebentu != SAGU_BOTOIA_EZKERRA);//TECLA E EDO SAGUA_BOTOIA_EZKERRA SAKATU EZ BITARTEAN TABERNARIAREN PUZZLEAREN AZALPENAREN LEHENENGO ZATIA IKUSI

	irudiaKendu(conversacion.id);
	conversacion.id = JOKOA_objetuarenIrudiaSortu(TABERNARIA_AZALPENA2);
	irudiaMugitu(conversacion.id, 10, 290);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	do {
		ebentu = ebentuaJasoGertatuBada();
	} while (ebentu != TECLA_e && ebentu != SAGU_BOTOIA_EZKERRA);//TECLA E EDO SAGUA_BOTOIA_EZKERRA SAKATU EZ BITARTEAN TABERNARIAREN PUZZLEAREN AZALPENAREN BIGARREN ZATIA IKUSI

	irudiaKendu(conversacion.id);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	do {
		SDL_Delay(2);
		pantailaGarbitu();

		ebentu = ebentuaJasoGertatuBada();//BEGIRATU ZER TEKLA KLIKATZEN DUEN
		//BOTOIAK
		if (puzle1_Klikatu(ebentu) == 1) {//PISTA
			conversacion.id = JOKOA_objetuarenIrudiaSortu(TABERNARIA_PISTA);
			irudiaMugitu(conversacion.id, 10, 290);

			do {
				pantailaGarbitu();
				irudiakMarraztu();
				pantailaBerriztu();

				ebentu = ebentuaJasoGertatuBada();
			} while (ebentu != TECLA_e && ebentu != SAGU_BOTOIA_EZKERRA);

			irudiaKendu(conversacion.id);
			pantailaGarbitu();
			irudiakMarraztu();
			pantailaBerriztu();
		}
		else if (puzle1_Klikatu(ebentu) == 2) {//BERRABIARATU
			puzle1_aldatutakoObjetuakEzabatu(daga, &vino, orientacion);//ALDATUTAKO OBJEKTUAK EZABATU
			puzle1_objetuakMarraztu(daga, &vino, orientacion, &vinoPosY, &vinoPosX);//OBJEKTUAK HASIERAKO ZEGOEN BEZALA MARRAZTEN DIRA
		}
		else if (puzle1_Klikatu(ebentu) == 3) {//KONPROBATU
			irabazi = puzle1_Konprobatu(daga, &vino, &vinoPosX, &vinoPosY, orientacion);//PUZZLEA ONDO DAGOEN KONPROBATU
		}
		else if (puzle1_Klikatu(ebentu) == 4) {//GALDERA IKURRA
			conversacion.id = JOKOA_objetuarenIrudiaSortu(TABERNARIA_AZALPENA1);
			irudiaMugitu(conversacion.id, 10, 290);

			do {
				irudiakMarraztu();
				pantailaBerriztu();
				ebentu = ebentuaJasoGertatuBada();
			} while (ebentu != TECLA_e && ebentu != SAGU_BOTOIA_EZKERRA);

			irudiaKendu(conversacion.id);
			conversacion.id = JOKOA_objetuarenIrudiaSortu(TABERNARIA_AZALPENA2);
			irudiaMugitu(conversacion.id, 10, 290);

			do {
				pantailaGarbitu();
				irudiakMarraztu();
				pantailaBerriztu();

				ebentu = ebentuaJasoGertatuBada();
			} while (ebentu != TECLA_e && ebentu != SAGU_BOTOIA_EZKERRA);

			irudiaKendu(conversacion.id);
			pantailaGarbitu();
			irudiakMarraztu();
			pantailaBerriztu();
		}
		//DAGAS: DAGA BAKOITZA KLIKATZEN DUZUNEAN BERE ORIENTAZIOA ALDATZEKO
		else if (puzle1_Klikatu(ebentu) == 5) {
			daga[0] = puzle1_dagaIrudiaAldatu(daga[0]);
		}
		else if (puzle1_Klikatu(ebentu) == 6) {
			daga[1] = puzle1_dagaIrudiaAldatu(daga[1]);
		}
		else if (puzle1_Klikatu(ebentu) == 7) {
			daga[2] = puzle1_dagaIrudiaAldatu(daga[2]);
		}
		else if (puzle1_Klikatu(ebentu) == 8) {
			daga[3] = puzle1_dagaIrudiaAldatu(daga[3]);
		}
		else if (puzle1_Klikatu(ebentu) == 9) {
			daga[4] = puzle1_dagaIrudiaAldatu(daga[4]);
		}
		else if (puzle1_Klikatu(ebentu) == 10) {
			daga[5] = puzle1_dagaIrudiaAldatu(daga[5]);
		}
		else if (puzle1_Klikatu(ebentu) == 11) {
			daga[6] = puzle1_dagaIrudiaAldatu(daga[6]);
		}
		else if (puzle1_Klikatu(ebentu) == 12) {
			daga[7] = puzle1_dagaIrudiaAldatu(daga[7]);
		}

	} while (irabazi == 0);//MAIN WHILE-A
	//OBJEKTU GUZTIAK EZABATU
	irudiaKendu(fondo.id);
	irudiaKendu(cerveza.id);
	puzle1_objetuakEzabatu(daga, &vino);
}
int puzle1_Konprobatu(PUZZLE1 daga[], PUZZLE1* vino, int* vinoPosX, int* vinoPosY, DAGA orientacion[]) {//PUZZLE 1 ONDO DAGOEN JAKITEKO

	int irabazi = 0, berrabiarazi = 0, dx = 38, dy = 32;//DX ETA DY ARDOAREN MUGIMENDUAREN ABIADURA
	//TABLEROAREN MATRIZ MAPA
	int tablero[10][10] = {//Primera fila posX segunda fila posY de cada daga. Ejemplo: tablero[0][4] == 1 == daga1
	{11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
	{11, 0, 0, 0, 0, 1, 0, 0, 0, 11},
	{11, 0, 0, 0, 0, 2, 0, 0, 0, 11},
	{11, 0, 3, 0, 0, 0, 0, 0, 4, 11},
	{11, 0, 0, 0, 0, 0, 12, 0, 5, 11},
	{11, 0, 0, 0, 0, 0, 0, 0, 0, 11},
	{11, 6, 0, 0, 0, 0, 7, 0, 0, 11},
	{11, 0, 0, 0, 8, 0, 0, 0, 0, 11},
	{11, 0, 0, 0, 0, 0, 0, 0, 10, 10},
	{11, 11, 11, 11, 11, 11, 11, 9, 11, 11},
	};

	do {
		while (tablero[(*vinoPosY)][(*vinoPosX) + 1] != 10 && berrabiarazi == 0) {
			//ARDOAK ERAMATEN DUEN NORANTZAREN ARABERA, DAGAREKIN TALKA EGITEN DUENEAN HONEN ORIENTAZIOA KONTUAN HARTUTA ARDOAK IBILBIDE BAT H0ARTUKO EDO BESTE BAT
			if (vino->norantza == IPAR) {
				while (tablero[(*vinoPosY) + 1][(*vinoPosX)] == 0) {//ARDOAREN NORANTZAN MUGITU
					vino->pos.y += dy;
					(*vinoPosY)++;
					irudiaMugitu(vino->id, vino->pos.x, vino->pos.y);
					pantailaGarbitu();
					irudiakMarraztu();
					pantailaBerriztu();
					SDL_Delay(350);
				}
				if (tablero[(*vinoPosY) + 1][(*vinoPosX)] != 0 && tablero[(*vinoPosY) + 1][(*vinoPosX)] != 11 && tablero[(*vinoPosY)][(*vinoPosX)] != 10 && tablero[(*vinoPosY)][(*vinoPosX) + 1] != 12) {
					//DAGAREN KONTRA TALKA EGITEN DUENEAN ARDOAREN NORANTZA BERRIA KALKULATU
					vino->norantza = puzle1_vinoNorantza(daga[(tablero[(*vinoPosY) + 1][(*vinoPosX)]) - 1].orientacion, vino->norantza);
				}
				else if (tablero[(*vinoPosY) + 1][(*vinoPosX)] == 11 || tablero[(*vinoPosY)][(*vinoPosX) + 1] == 12) {
					//GARAGARDOAREKIN TALKA EDO TAULATIK KANPO JOATEN
					berrabiarazi = 1;
				}
			}
			else if (vino->norantza == HEGO) {
				while (tablero[(*vinoPosY) - 1][(*vinoPosX)] == 0) {
					vino->pos.y -= dy;
					(*vinoPosY)--;
					irudiaMugitu(vino->id, vino->pos.x, vino->pos.y);
					pantailaGarbitu();
					irudiakMarraztu();
					pantailaBerriztu();
					SDL_Delay(350);
				}
				if (tablero[(*vinoPosY) - 1][(*vinoPosX)] != 0 && tablero[(*vinoPosY) - 1][(*vinoPosX)] != 11 && tablero[(*vinoPosY)][(*vinoPosX)] != 10 && tablero[(*vinoPosY)][(*vinoPosX) + 1] != 12) {
					vino->norantza = puzle1_vinoNorantza(daga[(tablero[(*vinoPosY) - 1][(*vinoPosX)]) - 1].orientacion, vino->norantza);
				}
				else if (tablero[(*vinoPosY) - 1][(*vinoPosX)] == 11 || tablero[(*vinoPosY)][(*vinoPosX) + 1] == 12) {
					berrabiarazi = 1;
				}
			}
			else if (vino->norantza == EKI) {
				while (tablero[(*vinoPosY)][(*vinoPosX) - 1] == 0) {
					vino->pos.x -= dx;
					(*vinoPosX)--;
					irudiaMugitu(vino->id, vino->pos.x, vino->pos.y);
					pantailaGarbitu();
					irudiakMarraztu();
					pantailaBerriztu();
					SDL_Delay(350);
				}
				if (tablero[(*vinoPosY)][(*vinoPosX) - 1] != 0 && tablero[(*vinoPosY)][(*vinoPosX) - 1] != 11 && tablero[(*vinoPosY)][(*vinoPosX)] != 10 && tablero[(*vinoPosY)][(*vinoPosX) + 1] != 12) {
					vino->norantza = puzle1_vinoNorantza(daga[(tablero[(*vinoPosY)][(*vinoPosX) - 1]) - 1].orientacion, vino->norantza);
				}
				else if (tablero[(*vinoPosY)][(*vinoPosX) - 1] == 11 || tablero[(*vinoPosY)][(*vinoPosX) + 1] == 12) {
					berrabiarazi = 1;
				}
			}
			else if (vino->norantza == MENDE) {
				while (tablero[(*vinoPosY)][(*vinoPosX) + 1] == 0 || tablero[(*vinoPosY)][(*vinoPosX) + 1] == 10) {
					vino->pos.x += dx;
					(*vinoPosX)++;
					irudiaMugitu(vino->id, vino->pos.x, vino->pos.y);
					pantailaGarbitu();
					irudiakMarraztu();
					pantailaBerriztu();
					SDL_Delay(350);
				}
				if (tablero[(*vinoPosY)][(*vinoPosX) + 1] != 0 && tablero[(*vinoPosY)][(*vinoPosX) + 1] != 11 && tablero[(*vinoPosY)][(*vinoPosX)] != 10 && tablero[(*vinoPosY)][(*vinoPosX) + 1] != 12) {
					vino->norantza = puzle1_vinoNorantza(daga[(tablero[(*vinoPosY)][(*vinoPosX) + 1]) - 1].orientacion, vino->norantza);
				}
				else if (tablero[(*vinoPosY)][(*vinoPosX) + 1] == 11 || tablero[(*vinoPosY)][(*vinoPosX) + 1] == 12) {
					berrabiarazi = 1;
				}
			}
		}

		if ((tablero[(*vinoPosY)][(*vinoPosX) + 1]) == 10) {//ARDOA TAULATEN AZKEN POSIZIOAREN AURREKOA POSIZIOAN BALDIN BADAGO IRABAZTEN DUZU
			irabazi = 1;
		}
		else if (berrabiarazi == 1) {//GARAGARDOAREKIN TALKA EDO TAULATIK KANPO JOATEN BADA --> BERRABIATU BOTOIAREN BEZALA
			puzle1_aldatutakoObjetuakEzabatu(daga, *&vino, orientacion);
			puzle1_objetuakMarraztu(daga, *&vino, orientacion, *&vinoPosY, *&vinoPosX);
		}

	} while (irabazi == 0 && berrabiarazi == 0);//PUZZLEA ONDO EDO GAIZKI EGIN ARTE

	return irabazi;
}
int puzle1_Klikatu(int ebentu) {

	POSIZIOA pos;
	int click = 0;
	//JAKITEKO ZER BOTOI EDO ZER DAGA KLIKATZEN DUZUN
	if (ebentu == SAGU_BOTOIA_EZKERRA) {
		pos = saguarenPosizioa();
		//BOTONES
		if ((pos.x > 16) && (pos.x < 178) && (pos.y > 416) && (pos.y < 464)) {
			click = 1;//PISTA
		}
		if ((pos.x > 235) && (pos.x < 399) && (pos.y > 415) && (pos.y < 466)) {
			click = 2;//BERRABIATU
		}
		if ((pos.x > 455) && (pos.x < 618) && (pos.y > 416) && (pos.y < 464)) {
			click = 3;//KONPROBATU
		}
		if ((pos.x > 573) && (pos.x < 632) && (pos.y > 10) && (pos.y < 60)) {
			click = 4;//GALDERA IKURRA
		}

		//DAGAS
		if ((pos.x > 301) && (pos.x < 338) && (pos.y > 112) && (pos.y < 143)) {
			click = 5;//DAGA 1
		}
		if ((pos.x > 305) && (pos.x < 337) && (pos.y > 145) && (pos.y < 174)) {
			click = 6;//DAGA 2
		}
		if ((pos.x > 191) && (pos.x < 224) && (pos.y > 178) && (pos.y < 206)) {
			click = 7;//DAGA 3
		}
		if ((pos.x > 417) && (pos.x < 451) && (pos.y > 178) && (pos.y < 206)) {
			click = 8;//DAGA 4
		}
		if ((pos.x > 416) && (pos.x < 451) && (pos.y > 210) && (pos.y < 240)) {
			click = 9;//DAGA 5
		}
		if ((pos.x > 153) && (pos.x < 187) && (pos.y > 275) && (pos.y < 304)) {
			click = 10;//DAGA 6
		}
		if ((pos.x > 341) && (pos.x < 376) && (pos.y > 275) && (pos.y < 305)) {
			click = 11;//DAGA 7
		}
		if ((pos.x > 267) && (pos.x < 300) && (pos.y > 308) && (pos.y < 337)) {
			click = 12;//DAGA 8
		}
	}
	return click;
}
PUZZLE1 puzle1_dagaIrudiaAldatu(PUZZLE1 daga) {//DAGA BAT KLIKATZERAKOAN IRUDI HORI BORRATZEN DA ETA NORANTZA BERRIAREKIN MARRAZTEN DA

	PUZZLE1 s;

	s.id = daga.id;
	s.orientacion = daga.orientacion;
	s.pos.x = daga.pos.x;
	s.pos.y = daga.pos.y;

	irudiaKendu(s.id);

	if (s.orientacion == DER) {
		s.orientacion = IZQ;
		s.id = JOKOA_objetuarenIrudiaSortu(DAGAI);

	}
	else if (s.orientacion == IZQ) {
		s.orientacion = DER;
		s.id = JOKOA_objetuarenIrudiaSortu(DAGAD);
	}

	irudiaMugitu(s.id, s.pos.x, s.pos.y);

	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return s;
}
NORANTZA puzle1_vinoNorantza(DAGA orientacion, NORANTZA norantza) {
	if (orientacion == IZQ) {//DAGAREN ORIENTAZIOAREN(IZQ EDO DER) ARABERA ARDOAREN NORANTZA BERRIA EMAN
		if (norantza == IPAR) {
			norantza = MENDE;
		}
		else if (norantza == HEGO) {
			norantza = EKI;
		}
		else if (norantza == EKI) {
			norantza = HEGO;
		}
		else if (norantza == MENDE) {
			norantza = IPAR;
		}
	}
	else {
		if (norantza == IPAR) {
			norantza = EKI;
		}
		else if (norantza == HEGO) {
			norantza = MENDE;
		}
		else if (norantza == EKI) {
			norantza = IPAR;
		}
		else if (norantza == MENDE) {
			norantza = HEGO;
		}
	}
	return norantza;
}

//BOSS
EGOERA puzleBoss(JOKO_ELEMENTUA* vidas, CONDICION* bossInteraccion, EGOERA egoera, int* boss_vida, int* misko_vida, int spriteKop, int tamaño[], int xSprite[], int ySprite[], int spriteKont[]) {
	JOKO_ELEMENTUA fondo_batalla, galdera1, galdera2, galdera3, galdera4, boss, jokalaria;
	spriteKop = 4;

	int galdera = 1;

	fondo_batalla.id = JOKOA_objetuarenIrudiaSortu(FONDO_BATALLA);
	irudiaMugitu(fondo_batalla.id, 0, 0);
	galdera1.id = JOKOA_objetuarenIrudiaSortu(GALDERA_1);
	irudiaMugitu(galdera1.id, 640, 0);
	boss.id = JOKOA_spritearenIrudiaSortu(BOSS);
	tamaño[1] = 150;
	boss.pos.x = 290;
	boss.pos.y = 140;
	tamaño[0] = 60;
	if (*misko_vida == 3) {
		xSprite[0] = 0;
		ySprite[0] = 0;
	}
	else if (*misko_vida == 2) {
		xSprite[0] = 1;
		ySprite[0] = 0;
	}
	else {
		xSprite[0] = 2;
		ySprite[0] = 0;
	}
	vidas->pos.x = 730;
	vidas->pos.y = 30;
	spriteMugitu(vidas->id, vidas->pos.x, vidas->pos.y);
	jokalaria.id = JOKOA_spritearenIrudiaSortu(MISKO_BOSS);
	tamaño[2] = 128;
	jokalaria.pos.x = 130;
	jokalaria.pos.y = 320;
	xSprite[2] = 0;
	ySprite[2] = 0;
	spriteMugitu(boss.id, boss.pos.x,boss.pos.y);
	spriteMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
	pantailaGarbitu();
	irudiakMarraztu();
	spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);
	pantailaBerriztu();

	do {

		if (galdera == 1 && egoera == JOLASTEN) {
			egoera = puzleBoss_Emaitzak(galdera, egoera, *&boss_vida, *&misko_vida, tamaño, xSprite, ySprite);
			galdera++;
			irudiaKendu(galdera1.id);
			pantailaGarbitu();
			pantailaBerriztu();
		}
		else if (galdera == 2 && egoera == JOLASTEN) {
			galdera2.id = JOKOA_objetuarenIrudiaSortu(GALDERA_2);
			irudiaMugitu(galdera2.id, 640, 0);
			pantailaGarbitu();
			irudiakMarraztu();
			spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);
			pantailaBerriztu();
			egoera = puzleBoss_Emaitzak(galdera, egoera, *&boss_vida, *&misko_vida, tamaño, xSprite, ySprite);
			galdera++;
			irudiaKendu(galdera2.id);
			pantailaGarbitu();
			pantailaBerriztu();

		}
		else if (galdera == 3 && egoera == JOLASTEN) {
			galdera3.id = JOKOA_objetuarenIrudiaSortu(GALDERA_3);
			irudiaMugitu(galdera3.id, 640, 0);
			pantailaGarbitu();
			irudiakMarraztu();
			spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);
			pantailaBerriztu();
			egoera = puzleBoss_Emaitzak(galdera, egoera, *&boss_vida, *&misko_vida, tamaño, xSprite, ySprite);
			galdera++;
			irudiaKendu(galdera3.id);
			irudiakMarraztu();
			pantailaGarbitu();
			spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);
			pantailaBerriztu();
		}
		else if (galdera == 4 && egoera == JOLASTEN) {
			galdera4.id = JOKOA_objetuarenIrudiaSortu(GALDERA_4);
			irudiaMugitu(galdera4.id, 640, 0);
			pantailaGarbitu();
			irudiakMarraztu();
			spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);
			pantailaBerriztu();
			egoera = puzleBoss_Emaitzak(galdera, egoera, *&boss_vida, *&misko_vida, tamaño, xSprite, ySprite);
			irudiaKendu(galdera4.id);
			pantailaGarbitu();
			irudiakMarraztu();
			spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);
			pantailaBerriztu();
		}

	} while (egoera == JOLASTEN);
	spriteKendu(jokalaria.id);
	spriteKendu(boss.id);
	irudiaKendu(fondo_batalla.id);
	spriteKendu(vidas->id);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();


	return egoera;
}
EGOERA puzleBoss_Emaitzak(int galdera, EGOERA egoera, int* boss_vida, int* misko_vida , int tamaño[], int xSprite[], int ySprite[]) {

	int ebentu = 0, emaitza = 0;
	
	Mix_Chunk* zuzena, * okerra;

	zuzena = Mix_LoadWAV(ZUZENA);
	okerra = Mix_LoadWAV(OKERRA);
	Mix_VolumeChunk(okerra, 30);
	Mix_VolumeChunk(zuzena, 30);


	while (galdera == 1 && emaitza == 0 && *boss_vida > 0 && *misko_vida > 0) {
		ebentu = ebentuaJasoGertatuBada();

		if (puzleBoss_Klikatu(ebentu) == 1) {//GORRIA
			emaitza = 0;
			(*misko_vida)--;
			Mix_PlayChannel(-1, okerra, 0);
			vidasprite(*misko_vida, tamaño, xSprite, ySprite, 0);
		}
		else if (puzleBoss_Klikatu(ebentu) == 2) {//URDINA
			emaitza = 0;
			(*misko_vida)--;
			Mix_PlayChannel(-1, okerra, 0);
			vidasprite(*misko_vida, tamaño, xSprite, ySprite, 0);
		}
		else if (puzleBoss_Klikatu(ebentu) == 3) {//MOREA
			emaitza = 0;
			(*misko_vida)--;
			Mix_PlayChannel(-1, okerra, 0);
			vidasprite(*misko_vida, tamaño, xSprite, ySprite, 0);
		}
		else if (puzleBoss_Klikatu(ebentu) == 4) {//BERDEA
			emaitza = 1;
			(*boss_vida)--;
			Mix_PlayChannel(-1, zuzena, 0);
		}
		pantailaGarbitu();
		irudiakMarraztu();
		spriteakMarraztu(xSprite, ySprite, 3, tamaño);
		pantailaBerriztu();
	}
	while (galdera == 2 && emaitza == 0 && *boss_vida > 0 && *misko_vida > 0) {
		ebentu = ebentuaJasoGertatuBada();

		if (puzleBoss_Klikatu(ebentu) == 1) {//GORRIA
			emaitza = 0;
			(*misko_vida)--;
			Mix_PlayChannel(-1, okerra, 0);
			vidasprite(*misko_vida, tamaño, xSprite, ySprite, 0);
		}
		else if (puzleBoss_Klikatu(ebentu) == 2) {//URDINA
			emaitza = 1;
			(*boss_vida)--;
			Mix_PlayChannel(-1, zuzena, 0);
		}
		else if (puzleBoss_Klikatu(ebentu) == 3) {//MOREA
			emaitza = 0;
			(*misko_vida)--;
			Mix_PlayChannel(-1, okerra, 0);
			vidasprite(*misko_vida, tamaño, xSprite, ySprite, 0);
		}
		else if (puzleBoss_Klikatu(ebentu) == 4) {//BERDEA
			emaitza = 0;
			(*misko_vida)--;
			Mix_PlayChannel(-1, okerra, 0);
			vidasprite(*misko_vida, tamaño, xSprite, ySprite, 0);
		}
		pantailaGarbitu();
		irudiakMarraztu();
		spriteakMarraztu(xSprite, ySprite, 3, tamaño);
		pantailaBerriztu();
	}
	while (galdera == 3 && emaitza == 0 && *boss_vida > 0 && *misko_vida > 0) {
		ebentu = ebentuaJasoGertatuBada();

		if (puzleBoss_Klikatu(ebentu) == 1) {//GORRIA
			emaitza = 0;
			(*misko_vida)--;
			Mix_PlayChannel(-1, okerra, 0);
			vidasprite(*misko_vida, tamaño, xSprite, ySprite, 0);
		}
		else if (puzleBoss_Klikatu(ebentu) == 2) {//URDINA
			emaitza = 1;
			(*boss_vida)--;
			Mix_PlayChannel(-1, zuzena, 0);
		}
		else if (puzleBoss_Klikatu(ebentu) == 3) {//MOREA
			emaitza = 0;
			(*misko_vida)--;
			Mix_PlayChannel(-1, okerra, 0);
			vidasprite(*misko_vida, tamaño, xSprite, ySprite, 0);
		}
		else if (puzleBoss_Klikatu(ebentu) == 4) {//BERDEA
			emaitza = 0;
			(*misko_vida)--;
			Mix_PlayChannel(-1, okerra, 0);
			vidasprite(*misko_vida, tamaño, xSprite, ySprite, 0);
		}
		pantailaGarbitu();
		irudiakMarraztu();
		spriteakMarraztu(xSprite, ySprite, 3, tamaño);
		pantailaBerriztu();
	}
	while (galdera == 4 && emaitza == 0 && *boss_vida > 0 && *misko_vida > 0) {
		ebentu = ebentuaJasoGertatuBada();

		if (puzleBoss_Klikatu(ebentu) == 1) {//GORRIA
			emaitza = 0;
			(*misko_vida)--;
			Mix_PlayChannel(-1, okerra, 0);
			vidasprite(*misko_vida, tamaño, xSprite, ySprite, 0);
		}
		else if (puzleBoss_Klikatu(ebentu) == 2) {//URDINA
			emaitza = 0;
			(*misko_vida)--;
			Mix_PlayChannel(-1, okerra, 0);
			vidasprite(*misko_vida, tamaño, xSprite, ySprite, 0);
		}
		else if (puzleBoss_Klikatu(ebentu) == 3) {//MOREA
			emaitza = 1;
			(*boss_vida)--;
			Mix_PlayChannel(-1, zuzena, 0);
		}
		else if (puzleBoss_Klikatu(ebentu) == 4) {//BERDEA
			emaitza = 0;
			(*misko_vida)--;
			Mix_PlayChannel(-1, okerra, 0);
			vidasprite(*misko_vida, tamaño, xSprite, ySprite, 0);
		}
		pantailaGarbitu();
		irudiakMarraztu();
		spriteakMarraztu(xSprite, ySprite, 3, tamaño);
		pantailaBerriztu();
	}

	return JOKOA_egoera(*boss_vida, *misko_vida);
}
int puzleBoss_Klikatu(int ebentu) {

	POSIZIOA pos;
	int click = 0;

	if (ebentu == SAGU_BOTOIA_EZKERRA) {
		pos = saguarenPosizioa();
		//BOTONES
		if ((pos.x > 689) && (pos.x < 927) && (pos.y > 259) && (pos.y < 347)) {
			click = 1;//GORRIA
		}
		else if ((pos.x > 992) && (pos.x < 1230) && (pos.y > 259) && (pos.y < 347)) {
			click = 2;//URDINA
		}
		else if ((pos.x > 689) && (pos.x < 927) && (pos.y > 372) && (pos.y < 460)) {
			click = 3;//MOREA
		}
		else if ((pos.x > 992) && (pos.x < 1230) && (pos.y > 372) && (pos.y < 460)) {
			click = 4;//BERDEA
		}

	}
	return click;
}