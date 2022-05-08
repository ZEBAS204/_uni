/*
* ACTIVIDAD N7:
*  Diseñar un algoritmo que me permita ingresar 100 numeros enteros. Luego
* determinar cuantas veces se repite el numero 10 y mostrarlo.
*/

#include <stdio.h>

#define MAX_NUMS 100
#define NUM_TO_CHECK 10

int main() {
    int numRepetido = NUM_TO_CHECK;
    int repeticiones = 0;

    printf("Ingrese %d numeros para saber las repeticiones del numero %d", MAX_NUMS, numRepetido);

    // Get x count of numbers from the user
    for (int i = 0; i < MAX_NUMS; ++i) {
        int newVal;
        printf("\nIngrese un numero: ");
        scanf("%d", &newVal);

        if (newVal == numRepetido)
            repeticiones++;
    }

    // Print the first element in array
    printf("\nEl numero \"%d\" se ha repetido %d veces\n", NUM_TO_CHECK, repeticiones);

    return 0;
}
