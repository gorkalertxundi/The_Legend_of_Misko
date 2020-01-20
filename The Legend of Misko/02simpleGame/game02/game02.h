#ifndef GAME10_H
#define GAME10_H

#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>
#include "SDL_image.h"
#include <SDL.h>
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "SDL.h"
#include "defineak.h"
#include "OurTypes.h"

int JOKOA_objetuarenIrudiaSortu(char* irudia);
int JOKOA_spritearenIrudiaSortu(char* irudia);

EGOERA jokatu(void);//MAIN
EGOERA JOKOA_egoera(int boss, int vidas);//Jokoaren egoera konprobatzeko (Irabazi, galdu, jolasten

#endif