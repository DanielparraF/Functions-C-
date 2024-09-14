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
                "1. Buscar la ultima ocurrencia de una subcadena dentro de otra \n"
                "2. Dividir una cadena de Texto \n"
                "3. Unir el arreglo de caracteres de una cadena\n"
                "4. Verificar si una cadena de Texto finaliza con otra\n"
                "5. Formatear un valor Numerico\n"
                "6. Verificar si una cadena de texto es Palindroma\n"
                "7. Validar Parentesis\n"
                "8. Capitalizar una cadena de Texto\n"
                "X. Salir\n\n"

                "Digite su Opcion: ";

    do {
        printf("%s", menu);
        scanf(" %c", &option);
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

                break;
            }
            case '3': {

                break;
            }
            case '4': {

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
                printf("Opcion no valida. Intente de nuevo.\n");
                break;
        }
    } while (toupper(option) != 'X');
}
