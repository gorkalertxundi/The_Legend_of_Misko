/*#include "orokorrak.h"
#include "sarrera.h"
#include "errealitateFisikoa.h"
#include "jokoa.h"
#include "bukaera.h"*/

//---------------------------------------------------------------------------------
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
//---------------------------------------------------------------------------------

#include <stdio.h>

#include "ourTypes.h"
#include "game02.h"
#include "hasieraEtaAmaiera.h"


int main(int argc, char * str[]) {
  int jarraitu = 0;
  EGOERA egoera;
 
  if (sgHasieratu() == -1) 
  {
    fprintf(stderr, "Unable to set 1240x480 video: %s\n", SDL_GetError());
    return 1;
  }
  textuaGaitu(); 
  do
  {
    egoera = jokoaAurkeztu();
	if (egoera == JOLASTEN) {
		egoera = jokatu();
	}
    //jarraitu = jokoAmaierakoa(egoera);
  } while (egoera == JOLASTEN);
  sgItxi();
  return 0;
}

