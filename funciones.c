/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.c
 * Brief: Este archivo contiene las funciones encargadas de recibir los caracteres
 *        y establecer si es palindromo o no.
 * Author: Grupo 2
 * 
 * Created on May 16, 2020, 5:02 PM
 */

#include "funciones.h"
#include <stdio.h>

//Establece las condiciones para ser una letra
#define ES_LETRA(x) ((((x)>='a')&&((x)<='z'))||(((x)>='A')&&((x)<='Z')))

//Establece las condiciones para ser un signo de puntuacion
#define ES_SIGNO(x) (((x)==' ')||((x)=='.')||((x)==':')||((x)==';')||((x)==',')||((x)=='?')||((x)=='!'))

//Hace el pasaje de minuscula a mayuscula
#define TO_UPPER(x) ((((x)>='a')&&((x)<='z'))? ((x)+'A'-'a'):(x))

//Esta funcion se encarga de recibir lo ingresado por teclado y devuelve la cantidad
//de caracteres ingresados
int lectura (char *p1)
{
    //Zona de variables.
    int cont,error;
    char caracter;
    char *paux;
    paux=p1;
    
    //Se repite mientras que haya error
    do
    {   
        //Reiniciamos el puntero en el arreglo.
        p1=paux;
        printf("Ingrese la oracion a analizar. Tener en cuenta que los caracteres validos son:\nletras, espacios, comas, puntos, dos puntos, punto y coma, signo de exclamacion e interrogacion.\n");
        cont=0;
        error=0;
        
        //Se repite mientras que no haya mas letras que el maximo.
        while((caracter=getchar())!='\n')
        {
            //Asegura que se encuentre dentro del arreglo y sea un caracter valido
            if((cont<MAX)&&((ES_LETRA(caracter))||(ES_SIGNO(caracter))))
            {
                //Guardo el caracter en el arreglo
                *p1=caracter;
                //Incrementamos el puntero y el contador de caracteres
                ++p1;
                ++cont;
            }
            //Si no es un caracter valido hay un error
            else
            {
                error=1;
            }   
        }
        //Si el contador supera el maximo permitido hay error
        if(cont>=MAX)
        {
           error=1;
           printf("Se ha superado la cantidad maxima de caracteres.\n");
        }
        else if(error==1)
        {
            printf("Se ha inresado un caracter invalido.\n");
        }
    }while(error==1);
    return cont;
}

//Se encarga de definir si una frase es o no un palindromo
int is_palindromo (char *p1, char *p2) 
{
    //Caso base (caracteres impares): los punteros apuntan al mismo caracter
    if(p1==p2)
    {
        return 1;
    }
    
    //Si ambos punteros son signos se llama recursivamente con los punteros
    //incrementados
    if((ES_SIGNO(*p1))&&(ES_SIGNO(*p2)))
    {
        return is_palindromo((p1+1),(p2-1));
    }
    //Si uno de los punteros es signo y el otro letra se llama recursivamente
    //con el puntero correspondiente incrementado
    else if((ES_SIGNO(*p1))&&(ES_LETRA(*p2)))
    {
        return is_palindromo((p1+1),p2);
    }
    else if ((ES_LETRA(*p1))&&(ES_SIGNO(*p2)))
    {
        return is_palindromo(p1, (p2-1));
    }
    //Ambos son letras 
    else
    {
        //Caso base(caracteres pares): los punteros estan en los caracteres del medio
        if((p1+1)==p2)
        {
            //Si son la misma letra, o la misma letra en mayuscula y minuscula es palindromo
            if((*p1==*p2)||(TO_UPPER(*p1)==TO_UPPER(*p2)))
            {
                return 1;
            }
            //Si no son la misma letra no es palindromo
            else
            {
                return 0;
            }
        }
        //Los punteros no estan en el medio
        else
        {
            //Si apuntan al mismo caracter o o la misma letra en mayuscula y minuscula
            //el resultado depende de los siguientes caracteres
            if((*p1==*p2)||(TO_UPPER(*p1)==TO_UPPER(*p2)))
            {
                return is_palindromo((p1+1),(p2-1));
            }
            //Si no son iguales no es un palindromo
            else
            {
                return 0;
            }
        }
    }
}


