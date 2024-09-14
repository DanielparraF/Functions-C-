//
// Created by angar on 9/09/2024.
//

#ifndef TOOLS_H
#define TOOLS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* formatNumber(long numero) {
    char buffer[50];
    char* resultado;
    int longitud, i, j, comas = 0;

    sprintf(buffer, "%ld", numero);
    longitud = strlen(buffer);

    // Calcular cuántas comas se necesitan
    comas = (longitud - 1) / 3;

    resultado = (char*)malloc(longitud + comas + 1);

    for (i = longitud - 1, j = longitud + comas - 1; i >= 0; i--, j--) {
        resultado[j] = buffer[i];
        if ((longitud - i) % 3 == 0 && i > 0) {
            j--;
            resultado[j] = ',';
        }
    }

    resultado[longitud + comas] = '\0';

    return resultado;
}

int esNumeroValido(char* entrada) {
    int i = 0;


    if (entrada[0] == '-') {
        i = 1;
    }

    // Verificar que todos los caracteres sean dígitos
    for (; entrada[i] != '\0'; i++) {
        if (!isdigit(entrada[i])) {
            return 0;
        }
    }

    return 1;
}
void capitalizeLetters(char cadena[]) {
    int longitud = strlen(cadena);//funcion strlen nos da la longitud de la cadena ingresada
    int nuevoInicioPalabra = 1; // Para saber si es el inicio de una nueva palabra.

    for (int i = 0; i < longitud; i++) {
        if (isspace(cadena[i])) { //isspace valida los "white-space" o saltos de linea "
            nuevoInicioPalabra = 1; // El Siguiente carácter puede ser el inicio de una palabra.
        } else if (nuevoInicioPalabra) {
            // Si es el inicio de una nueva palabra, ya que la anterior condicion validó la posible primera palabra
            if (i == longitud - 1 || isspace(cadena[i + 1])) {
                // Si la palabra es de un solo carácter, lo convertimos a minuscula
                cadena[i] = tolower(cadena[i]);
            } else {
                // Convertimos la primera letra de la palabra en mayúscula
                cadena[i] = toupper(cadena[i]);
            }
            nuevoInicioPalabra = 0; // Ya no es inicio de palabra (no hay más palabras).
        } else {
            // Convertimos el resto de caracteres en minúscula
            cadena[i] = tolower(cadena[i]);
        }
    }
}
int validarEntrada(char cadena[]) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (!isalpha(cadena[i]) && !isspace(cadena[i])) {
            return 0; // Retorna 0 si encuentra un carácter no permitido
        }
    }
    return 1; // Retorna 1 si todos los caracteres son válidos
}

#endif //TOOLS_H>

