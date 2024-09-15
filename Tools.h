//
// Created by angar on 9/09/2024.
//

#ifndef TOOLS_H
#define TOOLS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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

/**
 * Responsable: Edwar Esteban Fonseca Jimenez.
 * Método que busca la última ocurrencia de una subcadena dentro de otra cadena.
 * @param cadena Cadena principal donde se busca la subcadena.
 * @param subcadena Subcadena que se desea buscar en la cadena principal.
 * @return Un entero que representa la posición donde inicia la última aparición de la subcadena,
 *         o 0 si la subcadena no se encuentra.
 */
int findLastOccurrence(char *string, char *substring) {
    char *lastOccurrence = NULL;
    char *temp = strstr(string, substring);

    while (temp != NULL) {
        lastOccurrence = temp;
        temp = strstr(temp + 1, substring);
    }

    if (lastOccurrence != NULL) {
        return (int)(lastOccurrence - string);
    } else {
        return 0;
    }
}

/**
 * Responsable: Edwar Eseban Fonseca Jimenez.
 * Método que valida si los paréntesis en una cadena están balanceados.
 * @param cadena Cadena de texto que contiene los paréntesis a evaluar.
 * @return Un valor entero: 1 si los paréntesis están balanceados, 0 en caso contrario.
 */
int validateParenthesis(char *string) {
    int count = 0;

    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == '(') {
            count++;
        } else if (string[i] == ')') {
            count--;
            if (count < 0) {
                return 0;
            }
        }
    }

    return count == 0;
}

/**
 * Responsable: Maria Fernanda Angarita.
 * Método que divide una cadena de texto en un arreglo de caracteres.
 * @param cadena Cadena de texto que se desea dividir.
 * @param array Arreglo de caracteres donde se almacenará cada carácter de la cadena.
 * La función copia cada carácter de la cadena al arreglo y finaliza agregando el carácter nulo '\0'.
 */

    void divideString(char *string, char *array) {
        int length = strlen(string);
        for (int i = 0; i < length; i++) {
            array[i] = string[i];
        }
        array[length] = '\0';
    }

/**
 * Responsable: Maria Fernanda Angarita.
 * Método que verifica si una cadena de texto es un palíndromo.
 * @param cadena Cadena de texto que se desea verificar.
 * @return Un entero que indica si la cadena es un palíndromo (1 si es palíndromo, 0 si no lo es).
 * La función compara los caracteres de los extremos de la cadena, ignorando mayúsculas y espacios, hasta llegar al centro.
 * Si todos los caracteres correspondientes coinciden, la función retorna 1 (verdadero),de lo contrario, retorna 0 (falso).
 */
    int isPalindrome(char *string) {
        int left = 0;
        int right = strlen(string) - 1;

        while (left < right) {
            if (!isalpha(string[left])) {
                left++;
                continue;
            }
            if (!isalpha(string[right])) {
                right--;
                continue;
            }

            if (tolower(string[left]) != tolower(string[right])) {
                return 0;
            }

            left++;
            right--;
        }
        return 1;
    }

#endif // TOOLS_H>
