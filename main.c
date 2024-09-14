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
                 "1. Buscar la ultima ocurrencia de una sudcadena dentro de otra \n"
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

                break;
            }
            case '8': {
                char cadena[100];

                printf("Ingrese una cadena de texto: ");
                fgets(cadena, sizeof(cadena), stdin);

                // Eliminar el salto de línea si es ingresado
                size_t longitud = strlen(cadena);
                if (cadena[longitud - 1] == '\n') {
                    cadena[longitud - 1] = '\0';
                }

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

