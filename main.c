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

                printf("Enter a number without the simbols and the ");
                scanf("%s", entrada);
                fflush(stdin);

                if (isNumberValid(entrada)) {
                    numero = atol(entrada);

                    numeroFormateado = formatNumber(numero);

                    printf("Formatted number: %s\n", numeroFormateado);

                    free(numeroFormateado);

                } else {
                    printf("Error: Invalid entry. It must be a whole number without commas or periods.\n");
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
                    printf("Enter a text string (letters and spaces only): ");
                    fgets(cadena, sizeof(cadena), stdin);

                    // Eliminar el salto de línea si es ingresado
                    size_t longitud = strlen(cadena);
                    if (cadena[longitud - 1] == '\n') {
                        cadena[longitud - 1] = '\0';
                    }

                    // Validar la entrada
                    esValida = validEntry(cadena);
                    if (!esValida) {
                        printf("Invalid entry. Only letters and spaces are allowed.\n");
                    }

                } while (!esValida);

                capitalizeLetters(cadena);

                printf("Capitalized chain: %s\n", cadena);

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
