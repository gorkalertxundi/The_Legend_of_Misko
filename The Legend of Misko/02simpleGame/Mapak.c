#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <windows.h>
#include "defineak.h"
#include "OurTypes.h"
#include "mugimendua.h"
#include "game02.h"
#include "interkazioak.h"
#include "puzzleak.h"
#include "mugimendua.h"
#include "Mapak.h"
#include "etsaiak.h"


int CASA[14][19] = {
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1},
{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	1,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	2,	2,	2,	2,	2,	2,	2,	2,	2,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
};
int CASA_EXTERIOR[15][19] = {
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	0,	1,	1,	1,	1,	1,	1,	3,	3,	3,	1,	0,	0,	0,	1,	1,	0,	1},
{1,	0,	1,	1,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	0,	1},
{1,	0,	1,	1,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	9,	1,	1,	0,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	1,	1,	1,	0,	1,	0,	0,	0,	0,	0,	0,	1,	1,	1,	1,	1,	0,	1},
{1,	1,	1,	1,	1,	0,	0,	0,	0,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	1,	1,	1,	2,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	8,	8,	8,	1,	1,	1,	1,	1,	1,	1,	1},
};
int CASTILLO_EXTERIOR[15][19] = {
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	4,	4,	4,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	1,	0,	0,	1,	1,	0,	0,	1},
{1,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	0,	0,	1},
{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	1,	0,	1},
{1,	0,	1,	1,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0,	1,	1,	1,	0,	1},
{1,	0,	1,	1,	1,	1,	1,	0,	0,	0,	0,	0,	0,	1,	0,	1,	1,	0,	1},
{1,	0,	1,	1,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	3,	3,	3,	1,	1,	1,	1,	1,	1,	1,	1},
};
int CASTILLO[25][34] = {
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1 },
{1,	1,	1,	1,	1,	0,	0,	0,	0,	0,	0,	1,	1,	1,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1 },
{1,	1,	1,	1,	1,	0,	0,	0,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	0,	1,	1,	0,	0,	0,	0,	0,	1,	1,	0,	1,	1 },
{1,	1,	7,	1,	1,	0,	0,	0,	1,	1,	1,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	0,	0,	1,	1,	0,	1,	1 },
{1,	0,	0,	0,	0,	0,	1,	1,	0,	1,	0,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	0,	0,	0,	0,	0,	1,	1 },
{1,	0,	0,	0,	1,	0,	1,	1,	0,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	0,	1,	1 },
{1,	0,	0,	0,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	1,	1,	1,	1,	1,	1,	1,	0,	1,	0,	0,	1,	1 },
{1,	1,	0,	1,	1,	1,	0,	0,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	1,	1 },
{1,	1,	0,	1,	1,	1,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	1,	1 },
{1,	0,	0,	1, 0,	0,	0,	1,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	1,	1 },
{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	1,	1 },
{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1 },
{1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1 },
{1,	1,	0,	0,	0,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	0,	1,	1,	1,	1,	1,	6,	1,	1,	1,	1,	1,	0,	0,	1,	1 },
{1,	1,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	0,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	0,	0,	1,	1 },
{1,	1,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	0,	1,	1,	1,	0,	0,	0,	0,	0,	1,	1,	1,	0,	0,	1,	1 },
{1,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1 },
{1,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1 },
{1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	1,	0,	1,	1,	1,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	1,	1,	0,	0,	0,	0,	1,	1 },
{1,	1,	1,	1,	1,	1,	1,	0,	1,	0,	1,	1,	1,	5,	1,	1,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	1,	1,	0,	0,	0,	0,	1,	1 },
{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1 },
{1,	1,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1 },
{1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1 },
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	4,	4,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1 },
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1 },
};
int TABERNA_MAPA[15][19] = {
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	0,	0,	0,	0,	0,	0,	0,	0,	40,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	1},
{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	1},
{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	5,	1,	1,	1,	1,	1,	1,	1,	1,	1},
};
int PITONISA_MAPA[15][19] = {
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	0,	0,	0,	0,	0,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	0,	0,	1},
{1,	0,	0,	0,	0,	0,	1,	1,	0,	21,	0,	1,	1,	0,	0,	0,	0,	0,	1},
{1,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	1},
{1,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	1},
{1,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	1},
{1,	1,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	7,	7,	7,	1,	1,	1,	1,	1,	1,	1,	1},
};
int PLAYA_MAPA[15][19] = {
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	0,	1,	0,	0,	0,	0,	0,	8,	8,	8,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	1,	1,	0,	0,	0,	0,	0,	0,	1,	1,	0,	0,	0,	0,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	0,	0,	0,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
};
int DUNGEON_1[13][17] = {
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	9,	1,	1},
{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	1,	1,	0,	0,	1},
{1,	0,	0,	1,	0,	0,	0,	0,	0,	0,	1,	1,	0,	0,	0,	0,	1},
{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	1},
{1,	0,	0,	1,	1,	1,	1,	1,	1,	1,	0,	1,	0,	1,	1,	1,	1},
{1,	0,	0,	1,	1,	1,	1,	1,	1,	1,	0,	1,	0,	1,	1,	1,	1},
{1,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1},
{1,	0,	0,	0,	0,	0,	10,	1,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	1,	0,	0,	0,	0,	0,	1,	0,	0,	0,	1,	0,	0,	1,	1,	1},
{1,	1,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
};
int DUNGEON_2[13][17] = {
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	10,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	1},
{1,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	1},
{1,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	1},
{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
};
int DUNGEON_3[13][17] = {
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	0,	0,	0,	1,	0,	1,	1,	1,	0,	1,	0,	0,	1,	1,	1},
{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	1},
{1,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	1},
{1,	0,	1,	0,	0,	1,	0,	0,	59,	0,	0,	1,	0,	0,	0,	1,	1},
{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1},
{1,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	1,	0,	0,	0,	1},
{1,	11,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
};
int CASA_GRANDE[13][19] = {
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	0,	0,	0,	0,	0,	0,	1,	1,	0,	1,	1,	0,	0,	1,	0,	0,	0,	1},
{1,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	1},
{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	1},
{1,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	1},
{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	1,	1,	1,	1,	1,	1,	1,	1},
{1,	1,	1,	1,	1,	1,	1,	1,	6,	6,	6,	1,	1,	1,	1,	1,	1,	1,	1},
};

//MAPAK
int CASAMAPA(JOKO_ELEMENTUA* jokalaria, EGOERA egoera, int atera, int sartu, CONDICION tenerPico, Mix_Chunk* puerta, int xSprite[], int ySprite[], int move[], int spriteKop, int spriteMove[], int spriteKont[], int mirar[], int tamaño[], int* misko_vida) {

	int ebentu = 0;

	JOKO_ELEMENTUA fondo, posicion, mapa, menu, helburua5;

	Mix_Music* musica_fondo;//AUDIOS LARGOS = MUSIC
	Mix_Chunk* pico1, * pico2;//AUDIOS CORTOS = CHUNK


	musica_fondo = Mix_LoadMUS(JOKOA_SOUND);//AUDIOAK IZEN BATEKIN ERLAZIONATU
	pico1 = Mix_LoadWAV(PICO_OBJETO);
	pico2 = Mix_LoadWAV(PICO_AIRE);

	int jokalariaPosX;
	int jokalariaPosY;

	if (sartu == 1) {//SI ENTRA A LA CASA DESDE FUERA LE DA AL PROTA ESTAS POSICIONES
		jokalariaPosX = 9;
		jokalariaPosY = 11;
		jokalaria->pos.x = 298;
		jokalaria->pos.y = 391;
	}
	else if (egoera == ERREPIKATZEN) {//SI DESPUES DEL BOSS DE LAS A SEGUIR JUGANDO LA POSICION QUE VAS A TENER
		jokalaria->id = JOKOA_spritearenIrudiaSortu(JOKOA_PLAYER_IMAGE);
		mirar[0] = 1;
		tamaño[0] = 48;
		jokalariaPosX = 17;
		jokalariaPosY = 1;
		jokalaria->pos.x = 598;
		jokalaria->pos.y = 16;
		mapa.id = JOKOA_objetuarenIrudiaSortu(MAPA_DE_TODO);
		irudiaMugitu(mapa.id, 640, 0);
		menu.id = JOKOA_objetuarenIrudiaSortu(MENU);
		irudiaMugitu(menu.id, 640, 0);
		helburua5.id = JOKOA_objetuarenIrudiaSortu(HELBURUA_5);
		irudiaMugitu(helburua5.id, 1100, 300);
		toggleMusic();
		Mix_PlayMusic(musica_fondo, -1);
		Mix_VolumeMusic(50);//BAJAR EL VOLUMEN
	}
	else {//LA POSICION QUE TENDRA CUANDO INICIA EL JEUGO
		jokalariaPosX = 4;
		jokalariaPosY = 4;
		jokalaria->pos.x = 108;
		jokalaria->pos.y = 125;
	}

	atera = 0;

	fondo.id = JOKOA_objetuarenIrudiaSortu(MAPA002);
	posicion.id = JOKOA_objetuarenIrudiaSortu(POSICION);
	irudiaMugitu(posicion.id, 877, 270);

	do {
		pantailaBerriztu();
		ebentu = ebentuaJasoGertatuBada();

		pertsonaiarenMugimendua(mirar, spriteMove, xSprite, ySprite, ebentu, spriteKont, *&jokalaria, &jokalariaPosX, &jokalariaPosY,0);

		if (CASA[jokalariaPosY + 1][jokalariaPosX] == 1 && mirar[0] == 5) {
			mirar[0] = 1;//JOKALARIAK NORA BEGIRATZEN DUEN
		}
		if (CASA[jokalariaPosY][jokalariaPosX - 1] == 1 && mirar[0] == 6) {
			mirar[0] = 2;
		}
		if (CASA[jokalariaPosY][jokalariaPosX + 1] == 1 && mirar[0] == 7) {
			mirar[0] = 3;
		}
		if (CASA[jokalariaPosY - 1][jokalariaPosX] == 1 && mirar[0] == 8) {
			mirar[0] = 4;
		}
		if (CASA[jokalariaPosY][jokalariaPosX] == 2) {
			atera = 1;
			Mix_PlayChannel(-1, puerta, 0);//ATEAREN SOINUTA
		}
		if (ebentu == TECLA_SPACE && tenerPico == SI) {//SI TIENE EL PICO Y LE DA AL SPACE MIRA SI HAY TALKAK CERCA, SI HAY TALKAK HACE UN SONIDO, SI NO HAY OTRO
			if (mirar[0] == 1 && CASA[jokalariaPosY + 1][jokalariaPosX] == 1) {
				Mix_PlayChannel(-1, pico1, 0);
			}
			else if (mirar[0] == 3 && CASA[jokalariaPosY][jokalariaPosX + 1] == 1) {
				Mix_PlayChannel(-1, pico1, 0);
			}
			else if (mirar[0] == 2 && CASA[jokalariaPosY][jokalariaPosX - 1] == 1) {
				Mix_PlayChannel(-1, pico1, 0);
			}
			else if (mirar[0] == 4 && CASA[jokalariaPosY - 1][jokalariaPosX] == 1) {
				Mix_PlayChannel(-1, pico1, 0);
			}
			else {
				Mix_PlayChannel(-1, pico2, 0);
			}
		}
		if (ebentu == GERTAERA_IRTEN) {//JOKOA ITXI
			sgItxi();//PANTAILA ITXI
			egoera = ITXI;//DENA ITXI
		}
		spriteMugitu(jokalaria->id, jokalaria->pos.x, jokalaria->pos.y);
		pantailaGarbitu();
		irudiakMarraztu();
		spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);
		pantailaBerriztu();
	} while ((egoera == JOLASTEN || egoera == ERREPIKATZEN) && atera == 0);//X KLIKATZEN EDO MAPATIK ATERATZEN EZ ZAREN BITARTEAN

	//SORTUTAKOA BORRANTZEN DUGU
	irudiaKendu(fondo.id);
	irudiaKendu(posicion.id);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return atera;
}
int CIUDADMAPA(JOKO_ELEMENTUA jokalaria, EGOERA egoera, int sartu, CONDICION* piedraRota, CONDICION* tenerPico, CONDICION* taberneroHablar, JOKO_ELEMENTUA mapa, JOKO_ELEMENTUA* donde_ir, CONDICION bossInteraccion, Mix_Chunk* puerta, int xSprite[], int ySprite[], int move[], int spriteKop, int spriteMove[], int spriteKont[], int mirar[], int tamaño[], JOKO_ELEMENTUA* helburua3, JOKO_ELEMENTUA* helburua4, int* misko_vida) {

	int ebentu, atera = 1;

	JOKO_ELEMENTUA fondo, posicion, harria;
	Mix_Music* musica_fondo;//AUDIOS LARGOS = MUSIC
	Mix_Chunk* pico1, * pico2;//AUDIOS CORTOS = CHUNK

	musica_fondo = Mix_LoadMUS(JOKOA_SOUND);//AUDIOAK IZEN BATEKIN ERLAZIONATU
	pico1 = Mix_LoadWAV(PICO_OBJETO);
	pico2 = Mix_LoadWAV(PICO_AIRE);

	int jokalariaPosX;
	int jokalariaPosY;

	if (sartu == 2) {//LA POSICION QUE TENDRA SI VIENE DESDE EL EXTERIOR DEL CASTILLO
		jokalaria.pos.x = 297;
		jokalaria.pos.y = 10;
		jokalariaPosX = 9;
		jokalariaPosY = 2;
	}
	else if (sartu == 7) {//LA POSICION QUE TIENE SI ENTRA DESDE LA PLAYA
		jokalaria.pos.x = 297;
		jokalaria.pos.y = 429;
		jokalariaPosX = 9;
		jokalariaPosY = 13;
	}
	else if (sartu == 8) {//MEATEGITIK SARTU
		//POSIZIOA
		jokalaria.pos.x = 145;
		jokalaria.pos.y = 238;
		jokalariaPosX = 5;
		jokalariaPosY = 8;
		ySprite[0] = 0;
		mirar[0] = 1;
		//MUSICA
		toggleMusic();//CAMBIAR LA MUSICA
		audioInit();
		Mix_PlayMusic(musica_fondo, -1);//MUSICA ALDATU
		Mix_VolumeMusic(50);//BOLUMENA JEITXI
		mapa.id = JOKOA_objetuarenIrudiaSortu(MAPA_DE_TODO);//HERRIKO MINIMAPA SORTU
		irudiaMugitu(mapa.id, 640, 0);
		if (bossInteraccion == NO) {//SI NO SE HA PASADO EL BOSS TODAVIA LE DECIMOS QUE TIENE QUE ENTRAR A LA MINA
			donde_ir->id = JOKOA_objetuarenIrudiaSortu(DONDE_IR);
			irudiaMugitu(donde_ir->id, 903, 263);
		}
	}
	else {//LA POSICION QUE TENDRA SI SALE DE LA CASA, ETXETIK ATERA --> POSIZIOA
		jokalaria.pos.x = 487;
		jokalaria.pos.y = 390;
		jokalariaPosX = 14;
		jokalariaPosY = 12;
	}
	spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);

	fondo.id = JOKOA_objetuarenIrudiaSortu(MAPA001);
	posicion.id = JOKOA_objetuarenIrudiaSortu(POSICION);
	irudiaMugitu(posicion.id, 877, 270);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	if (*piedraRota == NO) {//HARRIA EZ BADUGU APURTU IRUDIA SORTZEN DUGU
		harria.id = JOKOA_objetuarenIrudiaSortu(PIEDRA);
		irudiaMugitu(harria.id, 152, 201);
	}

	do {
		ebentu = ebentuaJasoGertatuBada();

		pertsonaiarenMugimendua(mirar, spriteMove, xSprite, ySprite, ebentu, spriteKont, &jokalaria, &jokalariaPosX, &jokalariaPosY,0);
		if (CASA_EXTERIOR[jokalariaPosY + 1][jokalariaPosX] == 1 && mirar[0] == 5) {
			mirar[0] = 1;
		}
		if (CASA_EXTERIOR[jokalariaPosY][jokalariaPosX - 1] == 1 && mirar[0] == 6) {
			mirar[0] = 2;
		}
		if (CASA_EXTERIOR[jokalariaPosY][jokalariaPosX + 1] == 1 && mirar[0] == 7) {
			mirar[0] = 3;
		}
		if (CASA_EXTERIOR[jokalariaPosY - 1][jokalariaPosX] == 1 && mirar[0] == 8) {
			mirar[0] = 4;
		}
		if (CASA_EXTERIOR[jokalariaPosY][jokalariaPosX] == 3) {//PASA IR AL CASTILLO EXTERIOR
			atera = 2;
		}
		else if (CASA_EXTERIOR[jokalariaPosY][jokalariaPosX] == 2) {//PARA VOLVER A LA CASA
			atera = 0;
			Mix_PlayChannel(-1, puerta, 0);//SI ENTRA A LA CASA PONEMOS UN SONIDO DE PUERTA
		}

		if (CASA_EXTERIOR[jokalariaPosY][jokalariaPosX] == 8) {//HONDARTZA
			if (*taberneroHablar == NO) {//EZIN DEZAKEZU HONDARTZARA JOAN TABERNEROAREKIN HITZ EGIN ARTE
				interaccionIrAntesDeTabernero(xSprite, ySprite, spriteKop, tamaño);
				jokalariaPosY -= 1;
				jokalaria.pos.y -= 38;//BLOKE BAT ATZERA
			}
			else {//VAS A LA PLAYA
				atera = 7;
			}
		}
		else if (CASA_EXTERIOR[jokalariaPosY][jokalariaPosX] == 9) {//MEATEGIA
			atera = 8;
			if (egoera == JOLASTEN) {//ORAINDIK EZ BADUZU JOKOA BUKATU IRUDIA BORRATU
				irudiaKendu(donde_ir->id);
			}
			irudiaKendu(mapa.id);//HIRIKO MINIMAPA KENDU
		}
		if (ebentu == TECLA_SPACE && *tenerPico == SI) {//SI TIENE EL PICO Y LE DA AL SPACE MIRA SI HAY TALKAK CERCA, SI HAY TALKAK HACE UN SONIDO, SI NO HAY OTRO
			if (mirar[0] == 1 && CASA_EXTERIOR[jokalariaPosY + 1][jokalariaPosX] == 1) {
				Mix_PlayChannel(-1, pico1, 0);
			}
			else if (mirar[0] == 3 && CASA_EXTERIOR[jokalariaPosY][jokalariaPosX + 1] == 1) {
				Mix_PlayChannel(-1, pico1, 0);
			}
			else if (mirar[0] == 2 && CASA_EXTERIOR[jokalariaPosY][jokalariaPosX - 1] == 1) {
				Mix_PlayChannel(-1, pico1, 0);
			}
			else if (mirar[0] == 4 && CASA_EXTERIOR[jokalariaPosY - 1][jokalariaPosX] == 1) {
				Mix_PlayChannel(-1, pico1, 0);
			}
			else {
				audioInit();
				Mix_PlayChannel(-1, pico2, 0);
			}
			if ((jokalariaPosY - 1) == 7 && (jokalariaPosX == 5) && *piedraRota == NO && *tenerPico == SI && ebentu == TECLA_SPACE && mirar[0] == 4) {//PARA ROMPER LA PIEDRA			
				SDL_Delay(20);//PARA QUE NO SEA INSTANTANEAMENTE
				irudiaKendu(harria.id);//QUITAMOS LA IMAGEN DE LA PIEDRA
				*piedraRota = SI;//LA CONDICION DE LA PIEDRA LA PASAMOS A SI
				CASA_EXTERIOR[7][5] = 0;//LA POSICION DE LA PIEDRA LA PASAMOS A 0 PARA QUE PUEDAS ANDAR POR AHI
				irudiaKendu(helburua3->id);//QUITAMOS EL OBJETIVO ACTUAL
				helburua4->id = JOKOA_objetuarenIrudiaSortu(HELBURUA_4);//PONEMOS EL SIGUIENTE OBJETIVO
				irudiaMugitu(helburua4->id, 1100, 300);
			}
			else if ((jokalariaPosY == 7) && ((jokalariaPosX - 1) == 5) && *piedraRota == NO && *tenerPico == SI && ebentu == TECLA_SPACE && mirar[0] == 2) {
				SDL_Delay(20);//PARA QUE NO SEA INSTANTANEAMENTE
				irudiaKendu(harria.id);//QUITAMOS LA IMAGEN DE LA PIEDRA
				*piedraRota = SI;//LA CONDICION DE LA PIEDRA LA PASAMOS A SI
				CASA_EXTERIOR[7][5] = 0;//LA POSICION DE LA PIEDRA LA PASAMOS A 0 PARA QUE PUEDAS ANDAR POR AHI
				irudiaKendu(helburua3->id);//QUITAMOS EL OBJETIVO ACTUAL
				helburua4->id = JOKOA_objetuarenIrudiaSortu(HELBURUA_4);//PONEMOS EL SIGUIENTE OBJETIVO
				irudiaMugitu(helburua4->id, 1100, 300);
			}
		}
		if (ebentu == GERTAERA_IRTEN) {//PARA QUE EL JUEGO SE CIERRA SI CLICKAS EN LA X
			sgItxi();
			egoera = ITXI;
		}
		spriteMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
		pantailaGarbitu();
		irudiakMarraztu();
		spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);
		pantailaBerriztu();

	} while ((egoera == JOLASTEN || egoera == ERREPIKATZEN) && atera == 1);//X KLIKATZEN EDO MAPATIK ATERATZEN EZ ZAREN BITARTEAN

	irudiaKendu(fondo.id);
	irudiaKendu(posicion.id);
	if (*piedraRota == NO) {//SI NO HAS ROTO LA PIEDRA LA BORRAMOS
		irudiaKendu(harria.id);
	}
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return atera;
}
int CASTILLOEXTERIOR(int* misko_vida, JOKO_ELEMENTUA jokalaria, EGOERA egoera, int sartu, CONDICION tenerPico, int xSprite[], int ySprite[], int move[], int spriteKop, int spriteMove[], int spriteKont[], int mirar[], int tamaño[]) {

	int ebentu, atera = 2;
	JOKO_ELEMENTUA fondo, posicion;

	Mix_Music* musica_fondo;//AUDIOS LARGOS = MUSIC
	Mix_Chunk* pico1, * pico2;//AUDIOS CORTOS = CHUNK


	musica_fondo = Mix_LoadMUS(JOKOA_SOUND);//RELACIONAMOS LOS AUDIOS CON UN NOMBRE
	pico1 = Mix_LoadWAV(PICO_OBJETO);
	pico2 = Mix_LoadWAV(PICO_AIRE);

	int jokalariaPosX;
	int jokalariaPosY;


	if (sartu == 3) {//LA POSICION QUE TENDRA SI ENTRA DESDE EL CASTILLO
		jokalaria.pos.x = 295;
		jokalaria.pos.y = 116;
		tamaño[1] = 96;
		jokalariaPosX = 9;
		jokalariaPosY = 5;
		//CAMBIAMOS LA MUSICA DE LA DEL CASTILLO A LA DEL CAMPO
		toggleMusic();
		Mix_PlayMusic(musica_fondo, -1);
	}
	else {//LA  POSICION QUE TENDRA SI ENTRA DESDE EL EXTERIOR DE LA CASA
		jokalaria.pos.x = 295;
		jokalaria.pos.y = 420;

		jokalariaPosX = 9;
		jokalariaPosY = 13;
	}
	spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);

	//CREAMOS EL FONDO Y TU POSICION
	fondo.id = JOKOA_objetuarenIrudiaSortu(MAPA003);
	posicion.id = JOKOA_objetuarenIrudiaSortu(POSICION2);
	irudiaMugitu(posicion.id, 880, 120);

	do {
		ebentu = ebentuaJasoGertatuBada();

		pertsonaiarenMugimendua(mirar, spriteMove, xSprite, ySprite, ebentu, spriteKont, &jokalaria, &jokalariaPosX, &jokalariaPosY,0);
		if (CASTILLO_EXTERIOR[jokalariaPosY + 1][jokalariaPosX] == 1 && mirar[0] == 5) {
			mirar[0] = 1;
		}
		if (CASTILLO_EXTERIOR[jokalariaPosY][jokalariaPosX - 1] == 1 && mirar[0] == 6) {
			mirar[0] = 2;
		}
		if (CASTILLO_EXTERIOR[jokalariaPosY][jokalariaPosX + 1] == 1 && mirar[0] == 7) {
			mirar[0] = 3;
		}
		if (CASTILLO_EXTERIOR[jokalariaPosY - 1][jokalariaPosX] == 1 && mirar[0] == 8) {
			mirar[0] = 4;
		}

		if (CASTILLO_EXTERIOR[jokalariaPosY][jokalariaPosX] == 4) {//SI TOCAS EL BLOQUE 4 VAS AL CASTILLO
			atera = 3;
		}
		else if (CASTILLO_EXTERIOR[jokalariaPosY][jokalariaPosX] == 3) {//SI TOCAS EL BLOQUE 3 VAS AL EXTERIOR DE LA CASA
			atera = 1;
		}

		if (ebentu == TECLA_SPACE && tenerPico == SI) {//SI TIENE EL PICO Y LE DA AL SPACE MIRA SI HAY TALKAK CERCA, SI HAY TALKAK HACE UN SONIDO, SI NO HAY OTRO
			if (mirar[0] == 1 && CASTILLO_EXTERIOR[jokalariaPosY + 1][jokalariaPosX] == 1) {
				Mix_PlayChannel(-1, pico1, 0);
			}
			else if (mirar[0] == 3 && CASTILLO_EXTERIOR[jokalariaPosY][jokalariaPosX + 1] == 1) {
				Mix_PlayChannel(-1, pico1, 0);
			}
			else if (mirar[0] == 2 && CASTILLO_EXTERIOR[jokalariaPosY][jokalariaPosX - 1] == 1) {
				Mix_PlayChannel(-1, pico1, 0);
			}
			else if (mirar[0] == 4 && CASTILLO_EXTERIOR[jokalariaPosY - 1][jokalariaPosX] == 1) {
				Mix_PlayChannel(-1, pico1, 0);
			}
			else {
				Mix_PlayChannel(-1, pico2, 0);
			}
		}
		if (ebentu == GERTAERA_IRTEN) {//PARA QUE EL JUEGO SE CIERRA SI CLICKAS EN LA X
			sgItxi();
			egoera = ITXI;
		}
		spriteMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
		pantailaGarbitu();
		irudiakMarraztu();
		spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);
		pantailaBerriztu();

	} while ((egoera == JOLASTEN || egoera == ERREPIKATZEN) && atera == 2);//MIENTEAS NO LE DES A LA X O SALGAS DEL MAPA ESTAS EN ESTE WHILE

	//QUITAMOS LO CREADO EN ESTE MAPA
	irudiaKendu(fondo.id);
	irudiaKendu(posicion.id);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return atera;
}
int CASTILLOMAPA(int* misko_vida, JOKO_ELEMENTUA jokalaria, EGOERA egoera, int sartu, CONDICION tenerPico, Mix_Chunk* puerta, int xSprite[], int ySprite[], int move[], int spriteKop, int spriteMove[], int spriteKont[], int mirar[], int tamaño[]) {

	int ebentu, atera = 3;
	JOKO_ELEMENTUA fondo, posicion;

	Mix_Music* musica_fondo;//AUDIOS LARGOS = MUSIC
	Mix_Chunk* pico1, * pico2;//AUDIOS CORTOS = CHUNK

	musica_fondo = Mix_LoadMUS(MUSICA_CASTILLO);//RELACIONAMOS LOS AUDIOS CON UN NOMBRE
	pico1 = Mix_LoadWAV(PICO_OBJETO);
	pico2 = Mix_LoadWAV(PICO_AIRE);

	int jokalariaPosX;
	int jokalariaPosY;

	if (sartu == 4) {//LA POSICION QUE TENDRA SI ENTRAS DESDE LA TABERNA
		jokalariaPosX = 13;
		jokalariaPosY = 20;
		jokalaria.pos.x = 243;
		jokalaria.pos.y = 360;
		toggleMusic();//CAMBIAMOS LA MUSICA DE LA DE LA TABERNA A LA DEL CASTILLO
		Mix_PlayMusic(musica_fondo, -1);
		Mix_VolumeMusic(50);//BAJAR EL VOLUMEN
	}
	else if (sartu == 5) {//LA POSICION QUE TENDRA SI ENTRAS DESDE LA PITONISA
		jokalariaPosX = 2;
		jokalariaPosY = 4;
		jokalaria.pos.x = 36;
		jokalaria.pos.y = 60;
		toggleMusic(); // CAMBIAMOS LA MUSICA DE LA DE LA PITONISA A LA DEL CASTILLO
		Mix_PlayMusic(musica_fondo, -1);
		Mix_VolumeMusic(50);//BAJAR EL VOLUMEN
	}
	else if (sartu == 6) {
		jokalariaPosX = 24;
		jokalariaPosY = 14;
		jokalaria.pos.x = 452;
		jokalaria.pos.y = 252;
	}
	else {//LA POSICION QUE TENDRA SI ENTRA DESDE EL EXTERIOR DEL CASTILLO
		jokalariaPosX = 17;
		jokalariaPosY = 22;
		jokalaria.pos.x = 319;
		jokalaria.pos.y = 396;
		toggleMusic();//CAMBIAMOS LA MUSICA DE LA DEL CAMPO A LA DES CASTILLO
		Mix_PlayMusic(musica_fondo, -1);
		Mix_VolumeMusic(50);//BAJAR EL VOLUMEN
	}
	tamaño[1] = 192;
	spriteakMarraztu_txikia(xSprite, ySprite, spriteKop, tamaño);

	fondo.id = JOKOA_objetuarenIrudiaSortu(MAPA004);
	posicion.id = JOKOA_objetuarenIrudiaSortu(POSICION);
	irudiaMugitu(posicion.id, 877, 10);


	do {
		ebentu = ebentuaJasoGertatuBada();

		pertsonaiarenMugimendua_txikia(mirar, spriteMove, xSprite, ySprite, ebentu, spriteKont, &jokalaria, &jokalariaPosX, &jokalariaPosY);
		if (CASTILLO[jokalariaPosY + 1][jokalariaPosX] == 1 && mirar[0] == 5) {
			mirar[0] = 1;
		}
		if (CASTILLO[jokalariaPosY][jokalariaPosX - 1] == 1 && mirar[0] == 6) {
			mirar[0] = 2;
		}
		if (CASTILLO[jokalariaPosY][jokalariaPosX + 1] == 1 && mirar[0] == 7) {
			mirar[0] = 3;
		}
		if (CASTILLO[jokalariaPosY - 1][jokalariaPosX] == 1 && mirar[0] == 8) {
			mirar[0] = 4;
		}

		if (CASTILLO[jokalariaPosY][jokalariaPosX] == 4) {//SI TOCAS EL BLOQUE 4 VAS AL EXTERIOR DEL CASTILLO 
			atera = 2;
		}
		else if (CASTILLO[jokalariaPosY][jokalariaPosX] == 5) {//SI TOCAS EL BLOQUE 5 VAS A LA TABERNA
			atera = 4;
			Mix_PlayChannel(-1, puerta, 0);//AUDIO DE PUERTA
		}
		else if (CASTILLO[jokalariaPosY][jokalariaPosX] == 7) {//SI TOCAS EL BLOQUE 7 VAS AL MAPA DE LA PITONISA
			atera = 5;
		}
		else if (CASTILLO[jokalariaPosY][jokalariaPosX] == 6) {//SI TOCAS EL BLOQUE 6 VAS A LA CASA GRANDE
			atera = 6;
			Mix_PlayChannel(-1, puerta, 0);//AUDIO DE PUERTA
		}

		if (ebentu == TECLA_SPACE && tenerPico == SI) {//SI TIENE EL PICO Y LE DA AL SPACE MIRA SI HAY TALKAK CERCA, SI HAY TALKAK HACE UN SONIDO, SI NO HAY OTRO
			if (mirar[0] == 1 && CASTILLO[jokalariaPosY + 1][jokalariaPosX] == 1) {
				Mix_PlayChannel(-1, pico1, 0);
			}
			else if (mirar[0] == 3 && CASTILLO[jokalariaPosY][jokalariaPosX + 1] == 1) {
				Mix_PlayChannel(-1, pico1, 0);
			}
			else if (mirar[0] == 2 && CASTILLO[jokalariaPosY][jokalariaPosX - 1] == 1) {
				Mix_PlayChannel(-1, pico1, 0);
			}
			else if (mirar[0] == 4 && CASTILLO[jokalariaPosY - 1][jokalariaPosX] == 1) {
				Mix_PlayChannel(-1, pico1, 0);
			}
			else {
				Mix_PlayChannel(-1, pico2, 0);
			}
		}
		if (ebentu == GERTAERA_IRTEN) {//SI CLICKAS LA X CIERRAS EL JUEGO
			sgItxi();
			egoera = ITXI;
		}
		spriteMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
		pantailaGarbitu();
		irudiakMarraztu();
		spriteakMarraztu_txikia(xSprite, ySprite, spriteKop, tamaño);
		pantailaBerriztu();

	} while ((egoera == JOLASTEN || egoera == ERREPIKATZEN) && atera == 3);//MIENTEAS NO LE DES A LA X O SALGAS DEL MAPA ESTAS EN ESTE WHILE

	irudiaKendu(fondo.id);
	irudiaKendu(posicion.id);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return atera;
}
int TABERNA(int* misko_vida, JOKO_ELEMENTUA jokalaria, EGOERA egoera, CONDICION* taberneroHablar, JOKO_ELEMENTUA* donde_ir, Mix_Chunk* puerta, int xSprite[], int ySprite[], int move[], int spriteKop, int spriteMove[], int spriteKont[], int mirar[], int tamaño[], JOKO_ELEMENTUA* helburua1, JOKO_ELEMENTUA* helburua2) {

	int ebentu, atera = 4;
	int mugitu = 0;
	JOKO_ELEMENTUA fondo, posicion, tabernero;
	Mix_Music* musica_fondo;//AUDIOS LARGOS = MUSIC
	spriteKop = 3;
	tamaño[1] = 96;
	musica_fondo = Mix_LoadMUS(MUSICA_TABERNA);//RELACIONAMOS MUSICA CON NOMBRES
	toggleMusic();//PONEMOS LA MUSICA DE LA TABERNA
	Mix_PlayMusic(musica_fondo, -1);
	Mix_VolumeMusic(50);//BAJAR EL VOLUMEN

	//POSICION DEL JUGADOR
	jokalaria.pos.x = 296;
	jokalaria.pos.y = 420;
	//POSICION DEL JUGADOR EN LA MATRIZ
	int jokalariaPosX = 9;
	int jokalariaPosY = 13;

	spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);

	fondo.id = JOKOA_objetuarenIrudiaSortu(MAPA005);
	posicion.id = JOKOA_objetuarenIrudiaSortu(POSICION);
	irudiaMugitu(posicion.id, 877, 10);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	if (*taberneroHablar == SI) {//SI HAS HABLADO YA CON EL TABERNERO LO PONEMOS EN UNA POSICION
		spriteKop++;
		tabernero.pos.x = 296;
		tabernero.pos.y = 88;
		tabernero.id = JOKOA_spritearenIrudiaSortu(TABERNERO_ANDANDO1);
		spriteMugitu(tabernero.id, tabernero.pos.x, tabernero.pos.y);
		pantailaGarbitu();
		irudiakMarraztu();
		spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);
		pantailaBerriztu();
		if (egoera == ERREPIKATZEN) tamaño[1] = 48;
	}
	do {
		ebentu = ebentuaJasoGertatuBada();

		pertsonaiarenMugimendua(mirar, spriteMove, xSprite, ySprite, ebentu, spriteKont, &jokalaria, &jokalariaPosX, &jokalariaPosY,0);
		if (TABERNA_MAPA[jokalariaPosY + 1][jokalariaPosX] == 1 && mirar[0] == 5) {
			mirar[0] = 1;
		}
		if (TABERNA_MAPA[jokalariaPosY][jokalariaPosX - 1] == 1 && mirar[0] == 6) {
			mirar[0] = 2;
		}
		if (TABERNA_MAPA[jokalariaPosY][jokalariaPosX + 1] == 1 && mirar[0] == 7) {
			mirar[0] = 3;
		}
		if (TABERNA_MAPA[jokalariaPosY - 1][jokalariaPosX] == 1 && mirar[0] == 8) {
			mirar[0] = 4;
		}

		if (TABERNA_MAPA[jokalariaPosY][jokalariaPosX] == 5) {//SI TOCAS EL BLOQUE 5 SALES DE LA TABERMA
			atera = 3;
			Mix_PlayChannel(-1, puerta, 0);//AUDIO DE PUERTA
		}

		ebentu = ebentuaJasoGertatuBada();
		if (TABERNA_MAPA[jokalariaPosY][jokalariaPosX] == 40 && *taberneroHablar == NO) {//PARA HABLAR CON EL TABERNERO SOLO LA PRIMERA VEZ
			while (*taberneroHablar == NO) {//UNA VEZ TE SIENTAS NO TE PUEDES VOLVER A LEVANTAR
				do {
					ebentu = ebentuaJasoGertatuBada();
				} while (ebentu != TECLA_e);
				interaccionTABERNERO(&tabernero, mirar, spriteMove, xSprite, ySprite, spriteKont, tamaño);
				*taberneroHablar = SI;//CAMBIAMOS LA CONDICION DE HABLAR CON EL TABERNERO A SI
				SDL_Delay(2);
				puzle1_hasieraAmaieraPantaila();//INICIAMOS EL PUZZLE 1
				irudiaMugitu(donde_ir->id, 925, 423);//MOVEMOS LA IMAGEN DE DONDE IR HACIA LA PLAYA
				irudiaKendu(helburua1->id);//QUITAMOS EL OBJETIVO ACTUAL
				helburua2->id = JOKOA_objetuarenIrudiaSortu(HELBURUA_2);//PONEMOS EL NUEVO OBJETIVO
				irudiaMugitu(helburua2->id, 1100, 300);
				jokalariaPosY += 1;//MOVEMOS UN BLOQUE EL PERSONAJE
				jokalaria.pos.y += 38;
				pantailaGarbitu();
				irudiakMarraztu();
				spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);
				pantailaBerriztu();
			}
		}
		if (ebentu == GERTAERA_IRTEN) {//PARA QUE EL JUEGO SE CIERRA SI CLICKAS X
			sgItxi();
			egoera = ITXI;
		}
		spriteMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
		pantailaGarbitu();
		irudiakMarraztu();
		spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);
		pantailaBerriztu();

	} while ((egoera == JOLASTEN || egoera == ERREPIKATZEN) && atera == 4);//MIENTEAS NO LE DES A LA X O SALGAS DEL MAPA ESTAS EN ESTE WHILE

	irudiaKendu(fondo.id);
	irudiaKendu(posicion.id);
	if (*taberneroHablar == SI) {
		spriteKendu(tabernero.id);
	}
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return atera;
}
int PITONISA(int* misko_vida, JOKO_ELEMENTUA jokalaria, EGOERA egoera, CONDICION* pitonisaHablar, int xSprite[], int ySprite[], int move[], int spriteKop, int spriteMove[], int spriteKont[], int mirar[], int tamaño[]) {

	int ebentu, atera = 5;
	Mix_Music* musica_fondo;//AUDIOS LARGOS = MUSIC

	tamaño[1] = 96;

	toggleMusic();
	musica_fondo = Mix_LoadMUS(MUSICA_PITONISA);//RELACIONAMOS MUSICA CON NOMBRES
	toggleMusic();
	Mix_PlayMusic(musica_fondo, -1);//PONEMOS LA MUSICA DE LA PITONISA
	Mix_VolumeMusic(50);//BAJAR EL VOLUMEN


	JOKO_ELEMENTUA pitonisa, fondo, posicion;

	//POSICION DE JOKALARI
	int jokalariaPosX = 9;
	int jokalariaPosY = 13;
	jokalaria.pos.x = 296;
	jokalaria.pos.y = 420;
	spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);

	//POSICION DE LA PITONISA
	pitonisa.pos.x = 296;
	pitonisa.pos.y = 192;

	fondo.id = JOKOA_objetuarenIrudiaSortu(MAPA009);
	pitonisa.id = JOKOA_objetuarenIrudiaSortu(PITONISA_DE_PIE);
	irudiaMugitu(pitonisa.id, pitonisa.pos.x, pitonisa.pos.y);
	posicion.id = JOKOA_objetuarenIrudiaSortu(POSICION);
	irudiaMugitu(posicion.id, 877, 10);

	do {
		ebentu = ebentuaJasoGertatuBada();

		pertsonaiarenMugimendua(mirar, spriteMove, xSprite, ySprite, ebentu, spriteKont, &jokalaria, &jokalariaPosX, &jokalariaPosY,0);
		if (PITONISA_MAPA[jokalariaPosY + 1][jokalariaPosX] == 1 && mirar[0] == 5) {
			mirar[0] = 1;
		}
		if (PITONISA_MAPA[jokalariaPosY][jokalariaPosX - 1] == 1 && mirar[0] == 6) {
			mirar[0] = 2;
		}
		if (PITONISA_MAPA[jokalariaPosY][jokalariaPosX + 1] == 1 && mirar[0] == 7) {
			mirar[0] = 3;
		}
		if (PITONISA_MAPA[jokalariaPosY - 1][jokalariaPosX] == 1 && mirar[0] == 8) {
			mirar[0] = 4;
		}
		if (PITONISA_MAPA[jokalariaPosY][jokalariaPosX] == 7) {
			atera = 3;
		}
		ebentu = ebentuaJasoGertatuBada();
		if (PITONISA_MAPA[jokalariaPosY][jokalariaPosX] == 21 && *pitonisaHablar == NO) {//SI TE SIENTAS ENFRENTE DE LA PITONISA
			while (*pitonisaHablar == NO) {//UNA VEZ TE SIENTAS NO TE LEVANTAS

				do {
					ebentu = ebentuaJasoGertatuBada();
				} while (ebentu != TECLA_e);

				interaccionPITONISA(xSprite, ySprite, spriteKop, tamaño);//COVERSACION DE LA PITONISA
				jokalariaPosY += 1;//UN BLOQUE HACIA ATRAS
				jokalaria.pos.y += 38;
				*pitonisaHablar = SI;//CAMBIAMOS LA CONDICION DE HABLAR CON LA PITONISA A SI
			}
		}
		if (ebentu == GERTAERA_IRTEN) {//PARA QUE EL JUEGO SE CIERRA SI CLICKAS X
			sgItxi();
			egoera = ITXI;
		}
		spriteMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
		pantailaGarbitu();
		irudiakMarraztu();
		spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);
		pantailaBerriztu();
	} while ((egoera == JOLASTEN || egoera == ERREPIKATZEN) && atera == 5);//MIENTEAS NO LE DES A LA X O SALGAS DEL MAPA ESTAS EN ESTE WHILE

	irudiaKendu(fondo.id);
	irudiaKendu(pitonisa.id);
	irudiaKendu(posicion.id);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return atera;
}
int PLAYA(int* misko_vida, JOKO_ELEMENTUA jokalaria, EGOERA egoera, CONDICION* abrirCofre, CONDICION* tenerPico, JOKO_ELEMENTUA* donde_ir, JOKO_ELEMENTUA* pico, int xSprite[], int ySprite[], int move[], int spriteKop, int spriteMove[], int spriteKont[], int mirar[], int tamaño[], JOKO_ELEMENTUA* helburua2, JOKO_ELEMENTUA* helburua3) {

	int ebentu, atera = 6;
	JOKO_ELEMENTUA fondo, posicion, cofre;

	Mix_Chunk* pico1, * pico2;//AUDIOS CORTOS

	pico1 = Mix_LoadWAV(PICO_OBJETO);
	pico2 = Mix_LoadWAV(PICO_AIRE);

	//POSICION JOKALARIA
	int jokalariaPosX = 9;
	int jokalariaPosY = 2;
	jokalaria.pos.x = 295;
	jokalaria.pos.y = 10;
	spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);

	//POSICION COFRE
	int cofrePosX = 9;
	int cofrePosy = 9;
	cofre.pos.x = 295;
	cofre.pos.y = 276;


	fondo.id = JOKOA_objetuarenIrudiaSortu(MAPA010);
	posicion.id = JOKOA_objetuarenIrudiaSortu(POSICION);
	irudiaMugitu(posicion.id, 877, 370);

	if (*abrirCofre == NO) {//SI NO HAS ABIERTO EL COFRE PONEMOS LA IMAGEN DEL COFRE CERRADO
		cofre.id = JOKOA_objetuarenIrudiaSortu(COFRE_CERRADO);
	}
	else {//SI LO HAS ABIERTO DEL COFRE ABIERTO
		cofre.id = JOKOA_objetuarenIrudiaSortu(COFRE_ABIERTO);
	}
	irudiaMugitu(cofre.id, cofre.pos.x, cofre.pos.y);

	do {
		ebentu = ebentuaJasoGertatuBada();

		pertsonaiarenMugimendua(mirar, spriteMove, xSprite, ySprite, ebentu, spriteKont, &jokalaria, &jokalariaPosX, &jokalariaPosY,0);
		if (PLAYA_MAPA[jokalariaPosY + 1][jokalariaPosX] == 1 && mirar[0] == 5) {
			mirar[0] = 1;
		}
		if (PLAYA_MAPA[jokalariaPosY][jokalariaPosX - 1] == 1 && mirar[0] == 6) {
			mirar[0] = 2;
		}
		if (PLAYA_MAPA[jokalariaPosY][jokalariaPosX + 1] == 1 && mirar[0] == 7) {
			mirar[0] = 3;
		}
		if (PLAYA_MAPA[jokalariaPosY - 1][jokalariaPosX] == 1 && mirar[0] == 8) {
			mirar[0] = 4;
		}

		if (PLAYA_MAPA[jokalariaPosY][jokalariaPosX] == 8) {//SI ESTAS EN EL BLOQUE 8 VAS AL EXTERIOR DE LA CASA
			atera = 1;
		}
		if (PLAYA_MAPA[jokalariaPosY + 1][jokalariaPosX] == PLAYA_MAPA[cofrePosy][cofrePosX] && *abrirCofre == NO && ebentu == TECLA_e) {//SI TE PONES ENFRENTE DEL COFRE Y DE LAS A LA E
			interaccionCofre(xSprite,  ySprite, spriteKop, tamaño);//TODO LO QUE SALE EN LA INTERACION
			irudiaKendu(cofre.id);//CAMBIAMOS LA IMAGEN
			cofre.id = JOKOA_objetuarenIrudiaSortu(COFRE_ABIERTO);
			irudiaMugitu(cofre.id, cofre.pos.x, cofre.pos.y);
			*abrirCofre = SI;//CONDICION ABRIR COFRE = SI
			*tenerPico = SI;//CONDICION TENER PICO = SI
			pico->id = JOKOA_objetuarenIrudiaSortu(PICO_OBJ);//PONEMOS EL PICO EN LA INTERFAZ
			irudiaMugitu(pico->id, 1092, 52);
			irudiaMugitu(donde_ir->id, 903, 263);
			irudiaKendu(helburua2->id);//CAMBIAMOS LOS OBJETIVOS DEL JUGADOR
			helburua3->id = JOKOA_objetuarenIrudiaSortu(HELBURUA_3);
			irudiaMugitu(helburua3->id, 1100, 300);
			pantailaGarbitu();
			irudiakMarraztu();
			pantailaBerriztu();
		}
		if (ebentu == TECLA_SPACE && *tenerPico == SI) {//SI TIENE EL PICO Y LE DA AL SPACE MIRA SI HAY TALKAK CERCA, SI HAY TALKAK HACE UN SONIDO, SI NO HAY OTRO
			if (mirar[0] == 1 && PLAYA_MAPA[jokalariaPosY + 1][jokalariaPosX] == 1) {
				Mix_PlayChannel(-1, pico1, 0);
			}
			else if (mirar[0] == 3 && PLAYA_MAPA[jokalariaPosY][jokalariaPosX + 1] == 1) {
				Mix_PlayChannel(-1, pico1, 0);
			}
			else if (mirar[0] == 2 && PLAYA_MAPA[jokalariaPosY][jokalariaPosX - 1] == 1) {
				Mix_PlayChannel(-1, pico1, 0);
			}
			else if (mirar[0] == 4 && PLAYA_MAPA[jokalariaPosY - 1][jokalariaPosX] == 1) {
				Mix_PlayChannel(-1, pico1, 0);
			}
			else {
				Mix_PlayChannel(-1, pico2, 0);
			}
		}
		if (ebentu == GERTAERA_IRTEN) {//SI CLICKAS LA X CIERRAS EL JUEGO
			sgItxi();
			egoera = ITXI;
		}
		spriteMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
		pantailaGarbitu();
		irudiakMarraztu();
		spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);
		pantailaBerriztu();
	} while ((egoera == JOLASTEN || egoera == ERREPIKATZEN) && atera == 6);//MIENTEAS NO LE DES A LA X O SALGAS DEL MAPA ESTAS EN ESTE WHILE

	irudiaKendu(fondo.id);
	irudiaKendu(posicion.id);
	irudiaKendu(cofre.id);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return atera;
}
int DUNGEON1(int* misko_vida, JOKO_ELEMENTUA jokalaria, EGOERA egoera, int sartu, CONDICION* piedraLargaRota, CONDICION* mineroSalvado, JOKO_ELEMENTUA* donde_ir, JOKO_ELEMENTUA* mapa_mina, CONDICION bossInteraccion, int xSprite[], int ySprite[], int move[], int spriteKop, int spriteMove[], int spriteKont[], int mirar[], int tamaño[]) {

	int ebentu, atera = 8;

	int jokalariaPosX;
	int jokalariaPosY;

	//AUDIOS UTILIZADOS
	Mix_Music* musica_fondo;
	Mix_Chunk* pico1, * pico2;

	ySprite[0] = 0;

	musica_fondo = Mix_LoadMUS(MINA_CHILL);
	pico1 = Mix_LoadWAV(PICO_OBJETO);
	pico2 = Mix_LoadWAV(PICO_AIRE);


	JOKO_ELEMENTUA minero, fondo, posicion, piedra_larga;

	piedra_larga.pos.x = 376;
	piedra_larga.pos.y = 247;


	toggleMusic();
	Mix_PlayMusic(musica_fondo, -1);
	Mix_VolumeMusic(50);//BAJAR EL VOLUMEN

	if (sartu == 9) {
		jokalariaPosX = 5;
		jokalariaPosY = 9;
		jokalaria.pos.x = 180;
		jokalaria.pos.y = 320;
	}
	else {//POSICION QUE TENDRIA SI ENTRAS DESDE EL EXTERIOR
		jokalariaPosX = 14;
		jokalariaPosY = 3;
		jokalaria.pos.x = 522;
		jokalaria.pos.y = 92;
		mapa_mina->id = JOKOA_objetuarenIrudiaSortu(MAPA_MINA);//PONEMOS EL MINIMAPA DE LA MINA
		irudiaMugitu(mapa_mina->id, 640, 0);
		if (bossInteraccion == NO) {//SI NO TE HAS PASADO EL BOSS TE DECIMOS A DONDE IR
			donde_ir->id = JOKOA_objetuarenIrudiaSortu(DONDE_IR);
			irudiaMugitu(donde_ir->id, 930, 340);
		}

	}
	spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);

	fondo.id = JOKOA_objetuarenIrudiaSortu(MAPA006);

	if (*mineroSalvado == NO) {//SI NO TE HAS PASADO EL PUZZLE 3 PONEMOS AL MINERO
		minero.id = JOKOA_objetuarenIrudiaSortu(MINERO_HERIDO);
		irudiaMugitu(minero.id, 376, 133);
	}
	posicion.id = JOKOA_objetuarenIrudiaSortu(POSICION2);
	irudiaMugitu(posicion.id, 660, 30);

	if (*piedraLargaRota == NO) {//SI NO TE HAS PASADO EL PUZZLE 2 PONEMOS LA PIEDRA
		piedra_larga.id = JOKOA_objetuarenIrudiaSortu(PIEDRA_LARGA);
		irudiaMugitu(piedra_larga.id, piedra_larga.pos.x, piedra_larga.pos.y);
	}

	do {
		ebentu = ebentuaJasoGertatuBada();

		pertsonaiarenMugimendua(mirar, spriteMove, xSprite, ySprite, ebentu, spriteKont, &jokalaria, &jokalariaPosX, &jokalariaPosY,0);
		if (DUNGEON_1[jokalariaPosY + 1][jokalariaPosX] == 1 && mirar[0] == 5) {
			mirar[0] = 1;
		}
		if (DUNGEON_1[jokalariaPosY][jokalariaPosX - 1] == 1 && mirar[0] == 6) {
			mirar[0] = 2;
		}
		if (DUNGEON_1[jokalariaPosY][jokalariaPosX + 1] == 1 && mirar[0] == 7) {
			mirar[0] = 3;
		}
		if (DUNGEON_1[jokalariaPosY - 1][jokalariaPosX] == 1 && mirar[0] == 8) {
			mirar[0] = 4;
		}

		if (DUNGEON_1[jokalariaPosY][jokalariaPosX] == 9) {//SI ESTAS EN EL BLOQUE 9 VAS AL EXTERIOR
			atera = 1;
			irudiaKendu(mapa_mina->id);
			if (egoera == JOLASTEN) {//SI TODAVIA NO TE HAS PASADO EL JUEGO QUITAMOS EL DONDE IR
				irudiaKendu(donde_ir->id);
			}
		}
		if (DUNGEON_1[jokalariaPosY][jokalariaPosX] == 10) {//SI ESTAS EN EL BLOQUE 10 VAS AL SIGUIENTE NIVEL DE LA MINA
			atera = 9;
		}
		if (ebentu == TECLA_SPACE) {
			if (mirar[0] == 1 && DUNGEON_1[jokalariaPosY + 1][jokalariaPosX] == 1) {
				Mix_PlayChannel(-1, pico1, 0);
			}
			else if (mirar[0] == 3 && DUNGEON_1[jokalariaPosY][jokalariaPosX + 1] == 1) {
				Mix_PlayChannel(-1, pico1, 0);
			}
			else if (mirar[0] == 2 && DUNGEON_1[jokalariaPosY][jokalariaPosX - 1] == 1) {
				Mix_PlayChannel(-1, pico1, 0);
			}
			else if (mirar[0] == 4 && DUNGEON_1[jokalariaPosY - 1][jokalariaPosX] == 1) {
				Mix_PlayChannel(-1, pico1, 0);
			}
			else {
				Mix_PlayChannel(-1, pico2, 0);
			}
		}
		if (*mineroSalvado == NO && ebentu == TECLA_e) {//INICIAR EL PUZZLE 3 SI NO TE LO HAS PASADO
			if ((jokalariaPosY - 1) == 4 && jokalariaPosX == 10) {
				puzle3(xSprite, ySprite, spriteKop, tamaño, move, spriteMove, spriteKont, mirar, &jokalaria);//PUZZLE3
				irudiaKendu(minero.id);//UNA VEZ PASADO EL PUZZLE 3 BORRAMOS AL MINERO
				DUNGEON_1[4][10] = 0;//PONEMOS EL BLOQUE DEL MINERO A 0 PARA QUE PUEDAS ANDAR POR AHI
				*mineroSalvado = SI;//CONDICION DEL MINERO SALVADO = SI
				jokalaria.pos.x = 370;
				jokalaria.pos.y = 168;
			}
		}
		if (*piedraLargaRota == NO && ebentu == TECLA_SPACE && mirar[0] == 4) {//INICIAR EL PUZZLE 2 SI NO TE LO HAS PASADO
			if ((jokalariaPosY - 1) == 8 && jokalariaPosX == 10) {
				puzle2();//PUZZLE2
				irudiaKendu(piedra_larga.id);;//UNA VEZ PASADO EL PUZZLE 3 BORRAMOS LA PIEDRA
				DUNGEON_1[8][10] = 0;//PONEMOS EL BLOQUE DE LA PIERDRA A 0 PARA QUE PUEDAS ANDAR POR AHI
				*piedraLargaRota = SI;//CONDICION DEL PIEDRA LARGA ROTA = SI
			}
		}
		if (ebentu == GERTAERA_IRTEN) {//SI CLICKAS LA X CIERRAS EL JUEGO
			sgItxi();
			egoera = ITXI;
		}

		spriteMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
		pantailaGarbitu();
		irudiakMarraztu();
		spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);
		pantailaBerriztu();

	} while ((egoera == JOLASTEN || egoera == ERREPIKATZEN) && atera == 8);//MIENTEAS NO LE DES A LA X O SALGAS DEL MAPA ESTAS EN ESTE WHILE

	irudiaKendu(fondo.id);
	irudiaKendu(posicion.id);
	if (*mineroSalvado == NO) {//SI NO TE HAS PASADO EL PUZZLE 3 BORRAMOS AL MINERO
		irudiaKendu(minero.id);
	}
	if (*piedraLargaRota == NO) {//SI NO TE HAS PASADO EL PUZZLE 2 BORRAMOS LA PIEDRA
		irudiaKendu(piedra_larga.id);
	}
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return atera;
}
int DUNGEON2(int* misko_vida, JOKO_ELEMENTUA jokalaria, EGOERA egoera, int sartu, CONDICION* monstruosMuertos, int xSprite[], int ySprite[], int move[], int spriteKop, int spriteMove[], int spriteKont[], int mirar[], int tamaño[]) {

	int ebentu, atera = 9;
	JOKO_ELEMENTUA fondo, posicion, lurra;

	lurra.pos.x = 151;
	lurra.pos.y = 200;

	int jokalariaPosX;
	int jokalariaPosY;
	int kopuru;				//+++++++++++++++NUMERO DE MOBS1++++++++++++++++++++
	int kopuru2;			//+++++++++++++++NUMERO DE MOBS2++++++++++++++++++++
	int kopuru3 = 0;			//+++++++++++++++NUMERO DE FLECHAS++++++++++++++++++
	int casilla = 38;


	JOKO_ELEMENTUA enemigo1[10], enemigo2[10], flecha[20], barra;
	int num, espera[10], enemigo1posx[10], enemigo1posy[10], ene1vidas[10], avanzarx[20], avanzary[20];
	int ene2vidas[10], enemigo2posx[10], enemigo2posy[10], shoot[10], direc[20], kont[20], flechaposx[20], flechaposy[20];
	int barranum = 10, denbora = 0, t = 0, ataque = 0;

	Mix_Music* musica_fondo;
	musica_fondo = Mix_LoadMUS(MINA);
	int lurraPOS;
	lurraPOS = DUNGEON_2[11][15];

	fondo.id = JOKOA_objetuarenIrudiaSortu(MAPA007);
	posicion.id = JOKOA_objetuarenIrudiaSortu(POSICION2);
	irudiaMugitu(posicion.id, 697, 300);

	if (*monstruosMuertos == NO) { //SI ES LA PRIMERA VEZ QUE ENTRAS SE TAPA LA SALIDA, SE CREA LA BARRA Y LOS ENEMIGOS
		kopuru = 2; //NUMERO DE ENEMIGOS1
		kopuru2 = 1; //NUMERO DE ENEMIGOS2
		crearpersonajes(enemigo1, enemigo2, tamaño, espera, enemigo1posx, enemigo1posy, enemigo2posx, enemigo2posy, avanzarx, avanzary, ene1vidas, ene2vidas, shoot, &spriteKop, kopuru, kopuru2); //FUNCION PARA CREAR LOS ENEMIGOS
		barra.pos.x = 10;
		barra.pos.y = 10;
		barra.id = crearbarra(xSprite, ySprite, tamaño, &spriteKop, &barranum);
		lurra.id = JOKOA_objetuarenIrudiaSortu(TIERRA);
		irudiaMugitu(lurra.id, 565, 405);
	}
	else { //SI ES LA SEGUNDA VEZ QUE ENTRAS LOS ENEMIGOS NO APARECEN
		kopuru = 0;
		kopuru2 = 0;
	}

	if (sartu == 10) {//POSICION SI ENTRAS DESDE EL NIVEL 3 DE LA MINA
		jokalariaPosX = 14;
		jokalariaPosY = 11;
		jokalaria.pos.x = 525;
		jokalaria.pos.y = 395;
	}
	else {//POSICION SI ENTRAS DESDE EL NIVEL 1 DE LA MINA
		jokalariaPosX = 1;
		jokalariaPosY = 3;
		jokalaria.pos.x = 31;
		jokalaria.pos.y = 90;
		if (egoera == JOLASTEN) {//SI NO TE HAS PASADO EL JUEGO PONEMOS MUSICA DE PELEA
			toggleMusic();
			Mix_PlayMusic(musica_fondo, -1);
			Mix_VolumeMusic(50);//BAJAR EL VOLUMEN
		}
	}
	spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);


	do {
		ebentu = ebentuaJasoGertatuBada();
		vidasprite(*misko_vida, tamaño, xSprite, ySprite, 1);

		for (num = 0; num < kopuru; num++) {
			if (ene1vidas[num] <= 0) { //SI UN ENEMIGO MUERE EL ULTIMO TOMA SU LUGAR EN EL ARRAY Y DESAPARECE
				spriteKendu(enemigo1[num].id);
				DUNGEON_2[enemigo1posy[num]][enemigo1posx[num]] = 0;
				enemigo1posy[num] = enemigo1posy[kopuru - 1];
				enemigo1posx[num] = enemigo1posx[kopuru - 1];
				enemigo1[num] = enemigo1[kopuru - 1];
				ene1vidas[num] = ene1vidas[kopuru - 1];
				kopuru -= 1; //CUANTOS ENEMIGOS DE ESTE TIPO QUEDAN
				spriteKop -= 1;
				barranum -= 1; //LA POSICION QUE TIENE LA BARRA EN EL ARRAY
			}
		}
		for (num = 0; num < kopuru2; num++) {
			if (ene2vidas[num] <= 0) { //SI UN ENEMIGO MUERE EL ULTIMO TOMA SU LUGAR EN EL ARRAY Y DESAPARECE
				spriteKendu(enemigo2[num].id);
				DUNGEON_2[enemigo2posy[num]][enemigo2posx[num]] = 0;
				enemigo2posy[num] = enemigo2posy[kopuru2 - 1];
				enemigo2posx[num] = enemigo2posx[kopuru2 - 1];
				enemigo2[num] = enemigo2[kopuru2 - 1];
				ene2vidas[num] = ene2vidas[kopuru2 - 1];
				kopuru2 -= 1; //CUANTOS ENEMIGOS DE ESTE TIPO QUEDAN
				spriteKop -= 1;
				barranum -= 1; //LA POSICION QUE TIENE LA BARRA EN EL ARRAY
			}
		}

		pertsonaiarenMugimendua(mirar, spriteMove, xSprite, ySprite, ebentu, spriteKont, &jokalaria, &jokalariaPosX, &jokalariaPosY, 0); 

		//PONEMOS LA BARRA DE POTENCIA ENCIMA DEL PERSONAJE
		if (kopuru != 0 || kopuru2 != 0) { //SOLO SE MUEVE SI HAY ENEMIGOS
			barra.pos.x = jokalaria.pos.x;
			barra.pos.y = jokalaria.pos.y - 30;
			spriteMugitu(barra.id, barra.pos.x, barra.pos.y);
		}

		if (DUNGEON_2[jokalariaPosY + 1][jokalariaPosX] == 1 && mirar[0] == 5) {
			mirar[0] = 1;
		}
		if (DUNGEON_2[jokalariaPosY][jokalariaPosX - 1] == 1 && mirar[0] == 6) {
			mirar[0] = 2;
		}
		if (DUNGEON_2[jokalariaPosY][jokalariaPosX + 1] == 1 && mirar[0] == 7) {
			mirar[0] = 3;
		}
		if (DUNGEON_2[jokalariaPosY - 1][jokalariaPosX] == 1 && mirar[0] == 8) {
			mirar[0] = 4;
		}

		denbora++; //CONTADOR DE LOS ENEMIGOS
		if (ataque < 50) ataque++; //CONTADOR PARA QUE SE MUEVA EL SPRITE DEL ATAQUE
		if (denbora > 750) { //EL CONTADOR PARA EL MOVIMIENTO DE LOS ENEMIGOS
			movimiento1(jokalaria, enemigo1, espera, enemigo1posx, enemigo1posy, avanzarx, avanzary, casilla, kopuru, DUNGEON_2); //HACIA DONDE SE MOVERA ENEMIGO1
			movimiento2(jokalaria, enemigo2, shoot, enemigo2posx, enemigo2posy, avanzarx, avanzary, casilla, kopuru, kopuru2, DUNGEON_2); //HACIA DONDE SE MOVERA ENEMIGO2
			denbora = 0;
			t = 1; //PARA QUE LOS SPRITES CAMBIEN
		}
		flechadireccion(jokalaria, enemigo2, flecha, direc, tamaño, kont, &spriteKop, xSprite, ySprite, flechaposx, flechaposy, enemigo2posx, enemigo2posy, kopuru2, &kopuru3, shoot, denbora, casilla);
		flechagolpeo(jokalaria, flecha, direc, xSprite, ySprite, kont, flechaposx, flechaposy, &spriteKop, &*misko_vida, &kopuru3, casilla, DUNGEON_2);

		for (num = 0; num < kopuru; num++) {
			spriteMugitu(enemigo1[num].id, enemigo1[num].pos.x, enemigo1[num].pos.y);
		}
		for (num = 0; num < kopuru2; num++) {
			spriteMugitu(enemigo2[num].id, enemigo2[num].pos.x, enemigo2[num].pos.y);
		}
		for (num = 0; num < kopuru3; num++) {
			spriteMugitu(flecha[num].id, flecha[num].pos.x, flecha[num].pos.y);
		}
		if (ebentu == TECLA_SPACE) {
			if (ySprite[barranum] >= 2) {
				golpesonido(jokalariaPosX, jokalariaPosY, mirar, enemigo1posx, enemigo1posy, kopuru, DUNGEON_2); //EL SONIDO QUE HACE AL GOLPEAR
				golpenorabide(jokalaria, enemigo1, xSprite, ySprite, espera, enemigo1posx, enemigo1posy, ene1vidas, mirar, casilla, kopuru, ataque, barranum, DUNGEON_2); //EL EFECTO DEL GOLPE EN ENEMIGO1
				golpenorabide2(jokalaria, enemigo2, xSprite, ySprite, enemigo2posx, enemigo2posy, ene2vidas, mirar, casilla, kopuru2, ataque, barranum, DUNGEON_2); //EL EFECTO DEL GOLPE EN ENEMIGO1
				xSprite[barranum] = 0;
				ySprite[barranum] = 0;
				ataque = 0;
			}
		}
		enemigosprite(enemigo1, enemigo2, xSprite, ySprite, avanzarx, avanzary, move, spriteKont, spriteMove, kopuru, kopuru2, &t); //EL MOVIMIENTO DEL SPRITE DE LOS ENEMIGOS
		jokalaria = hostiaerantzun(jokalaria, enemigo1, espera, kopuru, casilla, &ataque, *&misko_vida, &jokalariaPosX, &jokalariaPosY, DUNGEON_2); //LA REACCION DEL JUGADOR CUANDO LE GOLPEAN
		if (ataque == 50 && (xSprite[barranum] != 4 || ySprite[barranum] != 4)) { //EL SPRITE DE LA BARRA DE ATAQUE
			ataque = 0;
			if (xSprite[barranum] == 4) {
				xSprite[barranum] = 0;
				ySprite[barranum] += 1;
			}
			xSprite[barranum] += 1;
		} 

		if (kopuru == 0 && kopuru2 == 0 && *monstruosMuertos == NO) {//HASTA QUE NO MATES A TODOS LOS ENEMIGOS LAS SALIDAS ESTAN BLOQUEADAS
			spriteKendu(barra.id);
			irudiaKendu(lurra.id);
			DUNGEON_2[11][15] = 11;
			*monstruosMuertos = SI;
		}
		if (DUNGEON_2[jokalariaPosY][jokalariaPosX] == 10 && *monstruosMuertos == SI) {//SI ESTAS EN EL BLOQUE 10 Y HAS MATADO A LOS MONSTRUOS TE VAS AL NIVEL 3
			atera = 8;
		}
		if (DUNGEON_2[jokalariaPosY][jokalariaPosX] == 11) {//NIVEL 1 DE LA MINA
			atera = 10;
		}
		if (ebentu == GERTAERA_IRTEN) {//CERRAR EL JUEGO SI LE DAS A LA X
			sgItxi();
			egoera = ITXI;
		}
		spriteMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
		pantailaGarbitu();
		irudiakMarraztu();
		spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);
		pantailaBerriztu();
		egoera = JOKOA_egoera(2, *misko_vida);
	} while ((egoera == JOLASTEN || egoera == ERREPIKATZEN) && atera == 9);//MIENTEAS NO LE DES A LA X O SALGAS DEL MAPA ESTAS EN ESTE WHILE
	irudiaKendu(fondo.id);
	irudiaKendu(posicion.id);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return atera;
}
int DUNGEON3(JOKO_ELEMENTUA* vidas, JOKO_ELEMENTUA jokalaria, EGOERA* egoera, int sartu, CONDICION* bossInteraccion, JOKO_ELEMENTUA* mapa_mina, JOKO_ELEMENTUA* menu, JOKO_ELEMENTUA* donde_ir, JOKO_ELEMENTUA* pico, int* boss_vida, int* misko_vida, int xSprite[], int ySprite[], int move[], int spriteKop, int spriteMove[], int spriteKont[], int mirar[], int tamaño[], JOKO_ELEMENTUA* helburua4) {

	int ebentu, atera = 10;

	JOKO_ELEMENTUA fondo, posicion;
	spriteKop = 5;
	//Mix_Music* boss;
	Mix_Chunk* pico1, * pico2;
	//AUDIOS DEL PICO
	pico1 = Mix_LoadWAV(PICO_OBJETO);
	pico2 = Mix_LoadWAV(PICO_AIRE);
	int jokalariaPosX;
	int jokalariaPosY;

	//jokalaria.id = JOKOA_spritearenIrudiaSortu(JOKOA_PLAYER_IMAGE);

	//POSICION DEL JOKALARI
	ySprite[0] = 2;
	jokalariaPosX = 2;
	jokalariaPosY = 11;
	jokalaria.pos.x = 68;
	jokalaria.pos.y = 390;

	spriteMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);

	int sinboloaPOS;
	int runaPOS;
	sinboloaPOS = DUNGEON_3[8][5];
	runaPOS = DUNGEON_3[8][3];

	fondo.id = JOKOA_objetuarenIrudiaSortu(MAPA008);
	posicion.id = JOKOA_objetuarenIrudiaSortu(POSICION2);
	irudiaMugitu(posicion.id, 900, 300);


	pantailaGarbitu();
	irudiakMarraztu();
	spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);
	pantailaBerriztu();

	do {
		ebentu = ebentuaJasoGertatuBada();

		if (*bossInteraccion == NO) { //Si ha entrado por primera vez en el mapa
			interaccionDUNGEON3(xSprite, ySprite, spriteKop, tamaño, jokalariaPosX, jokalariaPosY, mirar, spriteMove, ebentu, spriteKont, jokalaria);


			//Aqui va sonido del boss gritando
			irudiaKendu(fondo.id);
			spriteKendu(jokalaria.id);
			irudiaKendu(helburua4->id);
			irudiaKendu(menu->id);
			irudiaKendu(mapa_mina->id);
			irudiaKendu(donde_ir->id);
			irudiaKendu(pico->id);
			irudiaKendu(posicion.id);
			pantailaGarbitu();
			irudiakMarraztu();
			pantailaBerriztu();
			*egoera = puzleBoss(*&vidas, *&bossInteraccion, *egoera, *&boss_vida, *&misko_vida,  spriteKop,  tamaño,  xSprite,  ySprite, spriteKont);
			*bossInteraccion = SI;

		}

		else {//Si no entras por primera vez, habilitas el movimiento
			pertsonaiarenMugimendua(mirar, spriteMove, xSprite, ySprite, ebentu, spriteKont, &jokalaria, &jokalariaPosX, &jokalariaPosY,0);
			if (DUNGEON_3[jokalariaPosY + 1][jokalariaPosX] == 1 && mirar[0] == 5) {
				mirar[0] = 1;
			}
			if (DUNGEON_3[jokalariaPosY][jokalariaPosX - 1] == 1 && mirar[0] == 6) {
				mirar[0] = 2;
			}
			if (DUNGEON_3[jokalariaPosY][jokalariaPosX + 1] == 1 && mirar[0] == 7) {
				mirar[0] = 3;
			}
			if (DUNGEON_3[jokalariaPosY - 1][jokalariaPosX] == 1 && mirar[0] == 8) {
				mirar[0] = 4;
			}
			if (DUNGEON_3[jokalariaPosY][jokalariaPosX] == 11) {
				atera = 9;
			}
			if (ebentu == TECLA_SPACE) {//SONIDOS DEL PICO CUANDO GOLPEAS
				if (mirar[0] == 1 && DUNGEON_3[jokalariaPosY + 1][jokalariaPosX] == 1) {
					Mix_PlayChannel(-1, pico1, 0);
				}
				else if (mirar[0] == 3 && DUNGEON_3[jokalariaPosY][jokalariaPosX + 1] == 1) {
					Mix_PlayChannel(-1, pico1, 0);
				}
				else if (mirar[0] == 2 && DUNGEON_3[jokalariaPosY][jokalariaPosX - 1] == 1) {
					Mix_PlayChannel(-1, pico1, 0);
				}
				else if (mirar[0] == 4 && DUNGEON_3[jokalariaPosY - 1][jokalariaPosX] == 1) {
					Mix_PlayChannel(-1, pico1, 0);
				}
				else {
					Mix_PlayChannel(-1, pico2, 0);;
				}
			}
			if (ebentu == GERTAERA_IRTEN) {
				sgItxi();
				*egoera = ITXI;
			}
			spriteMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
			pantailaGarbitu();
			irudiakMarraztu();
			spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);
			pantailaBerriztu();
		}
	} while ((*egoera == JOLASTEN || *egoera == ERREPIKATZEN) && atera == 10);//MIENTEAS NO LE DES A LA X O TE PASES EL BOSS O SALGAS DEL MAPA ESTAS EN ESTE WHILE

	if (*egoera == ERREPIKATZEN) {
		irudiaKendu(fondo.id);
		pantailaGarbitu();
		irudiakMarraztu();
		pantailaBerriztu();
	}
	

	return atera;
}
int CASAGRANDE(int* misko_vida, JOKO_ELEMENTUA jokalaria, EGOERA egoera, Mix_Chunk* puerta, int xSprite[], int ySprite[], int move[], int spriteKop, int spriteMove[], int spriteKont[], int mirar[], int tamaño[]) {

	int ebentu, atera = 6, sonido1 = 0, sonido2 = 0;
	JOKO_ELEMENTUA fondo, posicion;

	int jokalariaPosX;
	int jokalariaPosY;

	//POSICIONE DEL JOKALARI CUANDO ENTRA
	jokalaria.pos.x = 297;
	jokalaria.pos.y = 420;
	jokalariaPosX = 9;
	jokalariaPosY = 11;

	tamaño[1] = 96;

	spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);

	fondo.id = JOKOA_objetuarenIrudiaSortu(MAPA011);
	posicion.id = JOKOA_objetuarenIrudiaSortu(POSICION);
	irudiaMugitu(posicion.id, 877, 10);

	do {
		ebentu = ebentuaJasoGertatuBada();

		pertsonaiarenMugimendua(mirar, spriteMove, xSprite, ySprite, ebentu, spriteKont, &jokalaria, &jokalariaPosX, &jokalariaPosY,0);
		if (CASA_GRANDE[jokalariaPosY + 1][jokalariaPosX] == 1 && mirar[0] == 5) {
			mirar[0] = 1;
		}
		if (CASA_GRANDE[jokalariaPosY][jokalariaPosX - 1] == 1 && mirar[0] == 6) {
			mirar[0] = 2;
		}
		if (CASA_GRANDE[jokalariaPosY][jokalariaPosX + 1] == 1 && mirar[0] == 7) {
			mirar[0] = 3;
		}
		if (CASA_GRANDE[jokalariaPosY - 1][jokalariaPosX] == 1 && mirar[0] == 8) {
			mirar[0] = 4;
		}

		if ((CASA_GRANDE[jokalariaPosY][jokalariaPosX] == 6)) {//SALIR DE LA CASA GRANDE A LA CASA
			atera = 3;
			Mix_PlayChannel(-1, puerta, 0);//SONIDO DE PUERTA
		}
		if (ebentu == GERTAERA_IRTEN) {//SI CLICKAS LA X CIERRAS EL JUEGO
			sgItxi();
			egoera = GALDU;
		}
		spriteMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
		pantailaGarbitu();
		irudiakMarraztu();
		spriteakMarraztu(xSprite, ySprite, spriteKop, tamaño);
		pantailaBerriztu();

	} while ((egoera == JOLASTEN || egoera == ERREPIKATZEN) && atera == 6);//MIENTEAS NO LE DES A LA X O SALGAS DEL MAPA ESTAS EN ESTE WHILE

	irudiaKendu(fondo.id);
	irudiaKendu(posicion.id);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return atera;
}


