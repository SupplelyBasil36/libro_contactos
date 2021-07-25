#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct datosContacto
{
    int numero;
    char nombre[50];
    datosContacto *sig;
    datosContacto *ant;
} *primero, *ultimo;

typedef struct datosContacto datosC;

struct libraries
{
    int numero;
}variable1;


#include "functions.h"