/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.h
 * Brief: Este archivo contiene todo lo necesario para utilizar el archivo funciones.c
 * Author: Grupo 2
 *
 * Created on May 16, 2020, 5:02 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX 300

/*Esta funcion se encarga de recibir lo ingresado por teclado y devuelve la 
cantidad de caracteres ingresados.
 Recibe un puntero a char donde guarda el caracter ingresado.
 Devuelve un int con la cantidad de caracteres ingresados.*/
int lectura (char *p1);

/*Esta funcion se encarga de definir si una frase es o no un palindromo.
 Recibe dos punteros a char.
 Devuelve un int que es 1 si es un palindromo o 0 si no lo es.*/
int is_palindromo (char *p1, char *p2);

#endif /* FUNCIONES_H */
