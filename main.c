/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Grupo 2
 *
 * Created on May 16, 2020, 4:56 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define MAX 300

//Esta funcion se encarga de recibir lo ingresado por teclado y devuelve la cantidad
//de caracteres ingresados
extern int lectura (char *p1);

//Se encarga de definir si una frase es o no un palindromo
extern int is_palindromo (char *p1, char *p2);
/*
 * 
 */
int main(int argc, char** argv) 
{
    //Zona de variables
    char frase[MAX];
    int n=lectura(frase);
    int palindromo= is_palindromo(frase, &(frase[n-1]));
    
    //Si la funcion is_palindromo devuelve un 1 es palindromo
    if(palindromo)
    {
        printf("La frase ingresada es un palindromo.\n");
    }
    //Si la funcion is_palindromo devuelve un 0 no es palindromo
    else
    {
        printf("La frase ingresada no es un palindromo.\n");
    }
    return (EXIT_SUCCESS);
}

