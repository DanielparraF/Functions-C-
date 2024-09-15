#include <ctype.h>
#include <stdio.h>
#include "Tools.h"

void mainMenu();
int main() {
    mainMenu();
    return 0;
}

void mainMenu() {
    char option;
    char *menu ="-----------------------------------------------------------------\n"
                "<<<<<<<MENU PRINCIPAL>>>>>>\n\n"
                "1. Find the last occurrence of a substring within another \n"
                "2. Split a Text string \n"
                "3. Join the array of characters in a string\n"
                "4. Check if a Text string ends with another\n"
                "5. Format a Numeric value\n"
                "6. Check if a text string is a Palindroma\n"
                "7. Validate Parentheses\n"
                "8. Capitalize a Text string\n"
                "X. Exit\n\n"

                "Type your Option: ";

    do {
        printf("%s", menu);
        scanf(" %c", &option);
        printf("-----------------------------------------------------------------\n" );
        fflush(stdin);
        switch (toupper(option)) {
            case '1': {
                char string[100], substring[100];
                printf("Enter the main string: ");
                fgets(string, sizeof(string), stdin);
                printf("Enter the substring to search for: ");
                fgets(substring, sizeof(substring), stdin);

                size_t length1 = strlen(string);
                size_t length2 = strlen(substring);
                if (string[length1 - 1] == '\n') string[length1 - 1] = '\0';
                if (substring[length2 - 1] == '\n') substring[length2 - 1] = '\0';

                int position = findLastOccurrence(string, substring);
                if (position > 0) {
                    printf("The last occurrence of the \nsubstring is at position: %d\n", position);
                } else {
                    printf("Substring not found.\n");
                }

                break;
            }
            case '2': {

                char string[200];
                char array[200];

                printf("Enter a text string: ");
                scanf(" %[^\n]", string);

                divideString(string, array);

                printf("Character array: ");
                for (int i = 0; i < strlen(array); i++) {
                    printf("%c ", array[i]);
                }
                printf("\n");
                break;
            }
            case '3': {// Punto 3: Unir arreglo de caracteres en una cadena
                char array[100];
                char separator;

                // Validación de entrada del arreglo de caracteres
                printf("Ingrese el arreglo de caracteres (sin espacios): ");
                scanf(" %[^\n]", array);

                if (strlen(array) == 0) {
                    printf("Error: El arreglo de caracteres no puede estar vacío.\n");
                    break;
                }

                fflush(stdin); // Si usas un compilador que lo permita

                // Validar entrada del separador
                printf("Ingrese el caracter separador: ");
                scanf(" %c", &separator);

                if (separator == '\n') {
                    printf("Error: Debes ingresar un carácter válido como separador.\n");
                    break;
                }

                // Llamar a la función que une el arreglo en una cadena
                char* result = joinCharactersToString(array, separator);

                printf("Cadena resultante: %s\n", result);
                free(result); // Liberar la memoria asignada
                break;
            }
            case '4': { // Punto 4: Verificar si una cadena termina con otra
                char string[100], substring[100];

                // Validación de entradas para las cadenas
                printf("Ingrese la cadena principal: ");
                fgets(string, sizeof(string), stdin);
                printf("Ingrese la subcadena: ");
                fgets(substring, sizeof(substring), stdin);

                // Eliminar saltos de línea al final de las cadenas si existen
                size_t length1 = strlen(string);
                size_t length2 = strlen(substring);
                if (string[length1 - 1] == '\n') string[length1 - 1] = '\0';
                if (substring[length2 - 1] == '\n') substring[length2 - 1] = '\0';

                // Validar que las cadenas no sean vacías
                if (strlen(string) == 0 || strlen(substring) == 0) {
                    printf("Error: La cadena o subcadena no pueden estar vacías.\n");
                    break;
                }

                // Llamar a la función que verifica si la cadena termina con la subcadena
                int endsWith = endsWithSubstring(string, substring);
                if (endsWith) {
                    printf("La cadena termina con la subcadena.\n");
                } else {
                    printf("La cadena no termina con la subcadena.\n");
                }
                break;
            }
            case '5': {

                char entrada[50];
                long numero;
                char* numeroFormateado;

                printf("Ingresa un numero entero: ");
                scanf("%s", entrada);
                fflush(stdin);

                if (esNumeroValido(entrada)) {
                    numero = atol(entrada);

                    numeroFormateado = formatNumber(numero);

                    printf("Número formateado: %s\n", numeroFormateado);

                    free(numeroFormateado);

                } else {
                    printf("Error: Entrada no válida. Debe ser un número entero sin comas ni puntos.\n");
                }

                break;
            }
            case '6': {

                char string[100];

                printf("Enter a string of characters: ");
                scanf(" %[^\n]", string);
                if (isPalindrome(string))
                    printf("The string is a palindrome.\n");
                else
                    printf("The string is not a palindrome.\n");
                getchar();
                break;

            }
            case '7': {
                char string[100];
                printf("Enter a string with parentheses: ");
                fgets(string, sizeof(string), stdin);
                size_t longitud = strlen(string);
                if (string[longitud - 1] == '\n') string[longitud - 1] = '\0';

                if (validateParenthesis(string)) {
                    printf("The parentheses are balanced.\n");
                } else {
                    printf("Parentheses are not balanced.\n");
                }
                break;
            }
            case '8': {
                char cadena[100];
                int esValida = 0;

                do {
                    printf("Ingrese una cadena de texto (solo letras y espacios): ");
                    fgets(cadena, sizeof(cadena), stdin);

                    // Eliminar el salto de línea si es ingresado
                    size_t longitud = strlen(cadena);
                    if (cadena[longitud - 1] == '\n') {
                        cadena[longitud - 1] = '\0';
                    }

                    // Validar la entrada
                    esValida = validarEntrada(cadena);
                    if (!esValida) {
                        printf("Entrada no válida. Solo se permiten letras y espacios.\n");
                    }

                } while (!esValida);

                capitalizeLetters(cadena);

                printf("Cadena capitalizada: %s\n", cadena);

                break;
            }
            case 'X':
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (toupper(option) != 'X');
}
