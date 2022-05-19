
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * A partir de un modelo matematico correspondiente a la verificacion de CUIL.
 * Se pide:
 * 1. Realizar un diagrama de flujo
 * 2. Realizar un programa en "C" que permita:
 * 2.a Ingresar un numero de CUIL (solo numeros, sin separacion por guiones o puntos)
 * 2.b Verificar que el ultimo digito sea el correcto.
 * 3. Realizar el programa en el entorno code blocks y subir a este espacio el codigo.
 */

/*
 *      +------------------+          +--------------------+          +----------------------+
 *      |                  |          |                    |          |                      |
 *      |   20, 23 y 30    |  +----+  |     DOCUMENTO      |  +----+  |  DIGITO VERIFICADOR  |
 *      |                  |          |    (8 numeros)     |          |                      |
 *      +------------------+          |                    |          +----------------------+
 *                                    +--------------------+
 *    +                      +                                      +                          +
 *    |                      |      +                        +      +                          +
 *    +----------------------+      +------------------------+      +--------------------------+
 *             PERSONA                         DNI                          VERIFICACION
 *
 */

void getCuil();
bool isOnlyDigits(char cuil[30]);
bool isLastDigitValid(char cuil[30]);

int main() {
    char exit[4] = {""};

    while (1) {
        printf("Ingrese el CUIL a verificar: ");
        getCuil();
        printf("\n[ ENTER PARA CONTINUAR ]\n");

        while ((getchar()) != '\n');
        fflush(stdin);

        printf("\nIntentarlo de nuevo...? Y/N = Y\n");
        fgets(exit, 3, stdin);
        if (tolower(exit[0]) == 'n') break;
    }

    return 0;
}

/*
char* formatCuil(char cuil[30]) {
    // Dereference array
    char* current = cuil;  // &cuil[0]

    if (*current == '\0' || current == "") return -1;

    char formatedCuil[30] = {""};

    for (; current < &cuil[30]; current++) {
        // Check if number
        if (isdigit(*current)) strncat(formatedCuil, current, 1);

        if (*current == '\0' || current == "") break;
    }

    return formatedCuil;
}
*/

bool isOnlyDigits(char cuil[30]) {
    // Dereference array
    char* current = cuil;  // &cuil[0]

    if (isspace(*current)) return false;
    if (*current == '0') {
        printf("\nNo se permiten CUILS comenzando con cero!");
        return false;
    }

    // See: https://www.cplusplus.com/reference/cctype/
    for (; current < &cuil[30]; current++) {
        // printf("\nVeriying %c... isDigit? %c\n", *current, isdigit(*current) ? 'Y' : 'N');

        if (iscntrl(*current)) break;     // Break on any of: \n, \0, \t, etc...
        if (isdigit(*current)) continue;  // Skip if digit

        // Now we are sure it's not a digit
        return false;
    }

    return true;
}

bool isLastDigitValid(char cuil[30]) {
    // Calculate and verify the verification digit
    // See: https://es.wikipedia.org/wiki/Clave_%C3%9Anica_de_Identificaci%C3%B3n_Tributaria
    //
    // Multiplicamos
    // # # 1 2 3 4 5 6 7 8 --> ## = 20
    // -------------------------------
    //
    // 2 0 1 2 3 4 5 6 7 8
    // 5 4 3 2 7 6 5 4 3 2
    // -------------------
    // 10+0+3+4+21+24+25+24+21+16= 148
    // 148/11 y redondeado a 5
    // 11 - 5 = 6 -> digito verificador

    // We know that the last digit is in the 10th position
    int lastDigit = ((int)cuil[10] - 48);  // Convert to number

    int v = 5;             // Numero a multiplicar
    int unsigned res = 0;  // Resultado

    for (int i = 0; i < 10; i++) {
        if (v == 1) v = 7;
        // printf("Multiplicando %d x %d\n", ((int)cuil[i] - 48), v);
        res += ((int)cuil[i] - 48) * v;  // Convert to number and multiply by v
        v--;
    }

    // Verify if the rest is equall to the last digit provided
    // printf("\nResultado es: %d\t---\tResto: %d\n", res, 11 - (res % 11));
    if (11 - (res % 11) == lastDigit) return true;

    return false;
}

void getCuil() {
    bool isValid = false;
    char cuil[30] = {""};

    while (1) {
        fflush(stdin);
        fgets(cuil, 30, stdin);

        // Check if only contains digits
        isValid = isOnlyDigits(cuil);

        if (!isValid) {
            printf("\nSolo se permiten ingresar numeros. Intentelo de nuevo.\n");
            continue;  // Skip
        }

        // Check if the cuil is at least 11 characters long
        // T.Persona (2) + DNI (8) + Verification (1)
        // Regex used in anses.gob.ar: /^(\D*)(.+9)(\D*)$/
        if (strlen(cuil) - 1 < 11) {  // n-1 to count \0 character!
            // printf("\n===============\nLENGTH: %d\n===============\n", strlen(cuil) - 1);
            printf("\nEl CUIL ingresado debe contener el tipo de persona fisica, DNI y digito verificador!");
            printf("\nEjemplo ##12345678X, donde: ## es el tipo (con ceros), 1234567 es el DNI y X es el digito verificador.");
            printf("\nIntentelo de nuevo: ");
            continue;
        }

        // Verify if the first two digits includes any of:
        // 20 -> Hombre
        // 23 -> Mujer
        // 30 -> Sociedades
        // Nota: el CUIT incluye mas tipos de personas fisicas
        char tempStr[3] = {""};  // Two digits + \0
        strncat(tempStr, &cuil[0], 1);
        strncat(tempStr, &cuil[1], 1);

        int personTypeDigit = atoi(tempStr);  // Convert the string to int
        int personTypes[] = {20, 23, 30, 0};  // 0 is only used to exit the loop
        bool found = false;

        for (int* p = personTypes; *p; p++) {
            if (*p == personTypeDigit) {
                found = true;
                break;
            }
        }

        if (!found) {
            printf("\nNumero de tipo de persona incorrecto! Intentelo de nuevo\n");
            continue;  // Skip
        }

        // Verify the last digit
        if (!isLastDigitValid(cuil)) {
            printf("\nEl digito verificador no coincide con el tipo de persona! Intentelo de nuevo\n");
            continue;  // Skip
        }

        break;
    }

    printf("\nEl CUIL es correcto");
    printf("\nCUIL ingresado: %s\n", cuil);
}
