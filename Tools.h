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
    char* result;
    int length, i, j, comas = 0;

    sprintf(buffer, "%ld", numero);
    length = strlen(buffer);

    // Calcular cuántas comas se necesitan
    comas = (length - 1) / 3;

    result = (char*)malloc(length + comas + 1);

    for (i = length - 1, j = length + comas - 1; i >= 0; i--, j--) {
        result[j] = buffer[i];
        if ((length - i) % 3 == 0 && i > 0) {
            j--;
            result[j] = ',';
        }
    }

    result[length + comas] = '\0';

    return result;
}

int isValidNumber(char* input) {
    int i = 0;

    if (input[0] == '-') {
        i = 1;
    }

    // Verificar que todos los caracteres sean dígitos
    for (; input[i] != '\0'; i++) {
        if (!isdigit(input[i])) {
            return 0;
        }
    }

    return 1;
}
void capitalizeLetters(char string[]) {
    int lenght = strlen(string);//funcion strlen nos da la longitud de la cadena ingresada
    int newHomeWord = 1; // Para saber si es el inicio de una nueva palabra.

    for (int i = 0; i < lenght; i++) {
        if (isspace(string[i])) { //isspace valida los "white-space" o saltos de linea "
            newHomeWord = 1; // El Siguiente carácter puede ser el inicio de una palabra.
        } else if (newHomeWord) {
            // Si es el inicio de una nueva palabra, ya que la anterior condicion validó la posible primera palabra
            if (i == lenght - 1 || isspace(string[i + 1])) {
                // Si la palabra es de un solo carácter, lo convertimos a minuscula
                string[i] = tolower(string[i]);
            } else {
                // Convertimos la primera letra de la palabra en mayúscula
                string[i] = toupper(string[i]);
            }
            newHomeWord = 0; // Ya no es inicio de palabra (no hay más palabras).
        } else {
            // Convertimos el resto de caracteres en minúscula
            string[i] = tolower(string[i]);
        }
    }
}

int validateEntry(char string[]) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (!isalpha(string[i]) && !isspace(string[i])) {
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
/**
 *Responsable Edgar Perez
 * Función que une un arreglo de caracteres en una cadena de texto con un separador.
 * @param array Arreglo de caracteres.
 * @param separator Carácter separador entre las palabras.
 * @return Cadena de texto unida.
 */
char* joinCharactersToString(char *array, char separator) {
    int length = strlen(array);
    char* result = (char*) malloc((2 * length) * sizeof(char)); // Reservar memoria para la cadena resultante
    int j = 0;

    for (int i = 0; i < length; i++) {
        result[j++] = array[i];
        if (i < length - 1) {
            result[j++] = separator;
        }
    }
    result[j] = '\0'; // Terminar la cadena con el carácter nulo
    return result;
}

/**
 **Responsable Edgar Perez
 * Función que verifica si una cadena termina con una subcadena.
 * @param string Cadena principal.
 * @param substring Subcadena.
 * @return 1 si la cadena termina con la subcadena, 0 en caso contrario.
 */
int endsWithSubstring(char *string, char *substring) {
    int stringLength = strlen(string);
    int substringLength = strlen(substring);

    if (substringLength > stringLength) {
        return 0; // La subcadena no puede ser mayor que la cadena principal
    }

    // Compara los últimos caracteres de la cadena con la subcadena
    return (strcmp(&string[stringLength - substringLength], substring) == 0);
}
#endif // TOOLS_H>
