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
                "<<<<<<<Main Menu>>>>>>\n\n"
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
                printf("Enter the character array (without spaces): ");
                scanf(" %[^\n]", array);

                if (strlen(array) == 0) {
                    printf("Error: Character array cannot be empty.\n");
                    break;
                }

                fflush(stdin); // Si usas un compilador que lo permita

                // Validar entrada del separador
                printf("Enter the separator character: ");
                scanf(" %c", &separator);

                if (separator == '\n') {
                    printf("Error: You must enter a valid character as a separator.\n");
                    break;
                }

                // Llamar a la función que une el arreglo en una cadena
                char* result = joinCharactersToString(array, separator);

                printf("Resulting string: %s\n", result);
                free(result); // Liberar la memoria asignada
                break;
            }
            case '4': { // Punto 4: Verificar si una cadena termina con otra
                char string[100], substring[100];

                // Validación de entradas para las cadenas
                printf("Enter the main string: ");
                fgets(string, sizeof(string), stdin);
                printf("Enter the substring: ");
                fgets(substring, sizeof(substring), stdin);

                // Eliminar saltos de línea al final de las cadenas si existen
                size_t length1 = strlen(string);
                size_t length2 = strlen(substring);
                if (string[length1 - 1] == '\n') string[length1 - 1] = '\0';
                if (substring[length2 - 1] == '\n') substring[length2 - 1] = '\0';

                // Validar que las cadenas no sean vacías
                if (strlen(string) == 0 || strlen(substring) == 0) {
                    printf("Error: String or substring cannot be empty.\n");
                    break;
                }

                // Llamar a la función que verifica si la cadena termina con la subcadena
                int endsWith = endsWithSubstring(string, substring);
                if (endsWith) {
                    printf("The string ends with the substring.\n");
                } else {
                    printf("String does not end with substring.\n");
                }
                break;
            }
            case '5': {

                char input[50];
                long number;
                char* formattedNumber;

                printf("Ingresa un numero entero: ");
                scanf("%s", input);
                fflush(stdin);

                if (isValidNumber(input)) {
                    number = atol(input);

                    formattedNumber = formatNumber(number);

                    printf("Número formateado: %s\n", formattedNumber);

                    free(formattedNumber);

                } else {
                    printf("Error: Invalid input. Must be an integer without commas or periods.\n");
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
                char string[100];
                int isValid = 0;

                do {
                    printf("Enter a text string (letters and spaces only): ");
                    fgets(string, sizeof(string), stdin);

                    // Eliminar el salto de línea si es ingresado
                    size_t longitud = strlen(string);
                    if (string[longitud - 1] == '\n') {
                        string[longitud - 1] = '\0';
                    }

                    // Validar la entrada
                    isValid = validateEntry(string);
                    if (!isValid) {
                        printf("Invalid entry. Only letters and spaces are allowed.\n");
                    }

                } while (!isValid);

                capitalizeLetters(string);

                printf("Capitalized string: %s\n", string);

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
