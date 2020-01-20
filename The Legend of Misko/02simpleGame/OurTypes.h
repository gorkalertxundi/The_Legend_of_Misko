#ifndef OURTYPES_H
#define OURTYPES_H

#include "ebentoak.h"

typedef enum { JOLASTEN, GALDU, IRABAZI, ERREPIKATZEN, ITXI }EGOERA;
typedef enum { IRUDIA, MARGOA, TESTUA } MOTA;
typedef enum { SI, NO } CONDICION;//Si ha hecho cierta accion

//AÑADIDO
typedef enum { IZQ, DER } DAGA;
typedef enum { IPAR, HEGO, EKI, MENDE } NORANTZA;
//<

typedef struct
{
  POSIZIOA pos;
  int id;
  MOTA mota;
  CONDICION condicion;
}JOKO_ELEMENTUA;
typedef struct
{
	POSIZIOA pos;
	int id;
	DAGA orientacion;
	NORANTZA norantza;
}PUZZLE1;

#endif