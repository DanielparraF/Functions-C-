#include <ctype.h>
#include <stdio.h>

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

                break;
            }
            case '6': {

                break;
            }
            case '7': {

                break;
            }
            case '8': {

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