//
// Created by angar on 9/09/2024.
//

#ifndef TOOLS_H
#define TOOLS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* formatearNumeroConComas(long numero) {
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
#endif //TOOLS_H>

