#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <windows.h>
#include "defineak.h"
#include "hasieraEtaAmaiera.h"

EGOERA jokoaAurkeztu(void)
{
	int ebentu = 0, botoiak = 0;;

	Mix_Music* musica_fondo;

	JOKO_ELEMENTUA hasierako_pantaila, hasierako_pantaila2;/* , kreditua, hasi, kontrolak;*/
	EGOERA egoera = JOLASTEN;

	//HASIERAKO PANTAILAREN MUSICA JARRI
	audioInit();
	musica_fondo = Mix_LoadMUS(MUSICA_PANTALLA_INICIO);
	Mix_PlayMusic(musica_fondo, -1);
	Mix_VolumeMusic(50);//BAJAR EL VOLUMEN

	//HASIERAKO PANTAILA JARRI
	hasierako_pantaila.id = JOKOA_objetuarenIrudiaSortu(HASIERA_IMAGE);
	hasierako_pantaila2.id = JOKOA_objetuarenIrudiaSortu(HASIERA_IMAGE_2);
	irudiaMugitu(hasierako_pantaila2.id, 640, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	do
	{
		ebentu = ebentuaJasoGertatuBada();
		botoiak = hasiKlikatu(ebentu);//JAKITEKO NON KLIK EGIN
		if (ebentu == GERTAERA_IRTEN) {
			sgItxi();
			egoera = ITXI;
		}
		else if (botoiak == 2) {
			egoera = kontrolak();//KONTROLAK PANTAILA
			botoiak = 0;
		}
		else if (botoiak == 3) {
			egoera = kredituak();//KREDITUAK PANTAILA
			botoiak = 0;
		}

	} while (botoiak != 1 && egoera == JOLASTEN);//JOKATU KLIK EZ EGIN BITARTEAN

	//HASIERA PANTAILAKO IRUDIAK KENDU
	irudiaKendu(hasierako_pantaila2.id);
	pantailaGarbitu();
	pantailaBerriztu();

	istorioPantaila();

	irudiaKendu(hasierako_pantaila.id);
	pantailaGarbitu();
	pantailaBerriztu();
	toggleMusic();
	audioTerminate();

	return egoera;
}
int hasiKlikatu(int ebentu) {
	//JAKITEKO NON KLIK EGITEN DUZUN
	POSIZIOA pos;
	int click = 0;

	if (ebentu == SAGU_BOTOIA_EZKERRA) {
		pos = saguarenPosizioa();
		if ((pos.x > 822) && (pos.x < 1099) && (pos.y > 90) && (pos.y < 173)) {
			click = 1;//JOKOA HASI
		}
		else if ((pos.x > 822) && (pos.x < 1099) && (pos.y > 213) && (pos.y < 296)) {
			click = 2;//KONTROLAK
		}
		else if ((pos.x > 822) && (pos.x < 1099) && (pos.y > 332) && (pos.y < 414)) {
			click = 3;//KREDITUAK
		}
	}
	return click;
}
EGOERA kredituak() {
	//KREDITUEN PANTAILA AGERTZEKO
	int itzuli = 0, ebentu = 0;
	POSIZIOA sagua;
	EGOERA egoera = JOLASTEN;
	JOKO_ELEMENTUA kredituak_fondo;
	kredituak_fondo.id = JOKOA_objetuarenIrudiaSortu(KREDITUAK);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	while (itzuli == 0 && egoera == JOLASTEN) {//JAKITEKO NON KLIK EGITEN DUZUN
		sagua = saguarenPosizioa();
		ebentu = ebentuaJasoGertatuBada();
		if (ebentu == GERTAERA_IRTEN) {
			sgItxi();
			egoera = ITXI;
		}
		if (sagua.x > 422 && sagua.x < 584 && sagua.y > 376 && sagua.y < 423 && ebentu == SAGU_BOTOIA_EZKERRA) {
			//ITZULI BOTOIAN KLIK EGITERAKOAN IF HONETAN SARTZEN DA
			itzuli = 1;
		}
	}
	//KREDITUEN FONDO KENDU
	irudiaKendu(kredituak_fondo.id);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return egoera;
}
EGOERA kontrolak() {
	//KONTROLEN PANTAILA
	int itzuli = 0, ebentu = 0;
	POSIZIOA sagua;
	EGOERA egoera = JOLASTEN;
	JOKO_ELEMENTUA kontrolak_fondo;
	kontrolak_fondo.id = JOKOA_objetuarenIrudiaSortu(KONTROLAK);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	while (itzuli == 0 && egoera == JOLASTEN) {
		sagua = saguarenPosizioa();
		ebentu = ebentuaJasoGertatuBada();
		if (ebentu == GERTAERA_IRTEN) {
			sgItxi();
			egoera = ITXI;
		}
		if (sagua.x > 422 && sagua.x < 584 && sagua.y > 376 && sagua.y < 423 && ebentu == SAGU_BOTOIA_EZKERRA) {
			//ITZULI BOTOIAN KLIK EGITERAKOAN IF HONETAN SARTZEN DA
			itzuli = 1;
		}
	}
	//ATZEKO IRUDIA KENTZEKO
	irudiaKendu(kontrolak_fondo.id);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return egoera;
}
EGOERA istorioPantaila() {

	EGOERA egoera = JOLASTEN;
	JOKO_ELEMENTUA irudia;
	int ebentu = 0;

	irudia.id = JOKOA_objetuarenIrudiaSortu(AZALPENA);
	irudiaMugitu(irudia.id, 640, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	do {
		ebentu = ebentuaJasoGertatuBada();
	} while (ebentu != TECLA_RETURN && ebentu != TECLA_e && ebentu != GERTAERA_IRTEN && ebentu != SAGU_BOTOIA_EZKERRA);
	if (ebentu == GERTAERA_IRTEN) {
		egoera = ITXI;
	}
	irudiaKendu(irudia.id);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return egoera;

}


//BUKAERA
int jokoAmaierakoa(EGOERA egoera)
{
	int ebentu = 0, click = 0;
	JOKO_ELEMENTUA background, game_over;

	Mix_Music* musica_fondo;
	Mix_Chunk* irabazi, * galdu;
	musica_fondo = Mix_LoadMUS(BUKAERAKO_MUSIKA);
	Mix_PlayMusic(musica_fondo, -1);
	irabazi = Mix_LoadWAV(YOU_WIN);
	galdu = Mix_LoadWAV(YOU_LOSE);
	Mix_VolumeChunk(irabazi, 100);
	Mix_VolumeChunk(galdu, 100);

	background.id = JOKOA_objetuarenIrudiaSortu(HASIERA_IMAGE);
	irudiaMugitu(background.id, 0, 0);
	game_over.id = JOKOA_objetuarenIrudiaSortu(GAME_OVER_PANTAILA);
	irudiaMugitu(game_over.id, 640, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	if (egoera == IRABAZI) {
		Mix_PlayChannel(-1, irabazi, 0);
	}
	else if (egoera == GALDU) {
		Mix_PlayChannel(-1, galdu, 0);
	}

	do
	{
		ebentu = ebentuaJasoGertatuBada();
		if (ebentu == SAGU_BOTOIA_EZKERRA) {
			click = bukaeraKlikatu(ebentu, egoera);
		}
		if (ebentu == GERTAERA_IRTEN) {
			sgItxi();
		}
	} while ((ebentu != GERTAERA_IRTEN) && (click == 0));

	if (click == 1) {
		egoera = ERREPIKATZEN;
	}

	irudiaKendu(background.id);
	irudiaKendu(game_over.id);
	pantailaGarbitu();
	pantailaBerriztu();

	return egoera;
}
int bukaeraKlikatu(int ebentu, EGOERA egoera) {

	POSIZIOA pos;
	int click = 0;

	Mix_Chunk* error;
	error = Mix_LoadWAV(OKERRA);

	if (egoera == IRABAZI) {

		pos = saguarenPosizioa();
		if ((pos.x > 695) && (pos.x < 853) && (pos.y > 377) && (pos.y < 425)) {
			click = 1;
		}
		else if ((pos.x > 1063) && (pos.x < 1225) && (pos.y > 377) && (pos.y < 425)) {
			click = 2;
		}
	}

	else {
		pos = saguarenPosizioa();
		if ((pos.x > 695) && (pos.x < 853) && (pos.y > 377) && (pos.y < 425)) {
			Mix_PlayChannel(-1, error, 0);
		}
		if ((pos.x > 1063) && (pos.x < 1225) && (pos.y > 377) && (pos.y < 425)) {
			click = 2;
		}
	}

	return click;
}