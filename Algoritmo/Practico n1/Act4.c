/*
* ACTIVIDAD N4:
*  Diseñar un algoritmo que implemente una estructura repetitiva
* para determinar el mayor de un grupo de 50 numeros ingresados por teclado.
*/

#include <stdio.h>

#define MAX_NUMS 50

int requestNum(int valNum) {
    int result;

    printf("\nIngrese val%d: ", valNum);
    scanf("%d", &result);

    // printf("Numero ingresado: %d", result);

    return result;
}

int main() {
    int i;
    int vals[MAX_NUMS];

    printf("Ingrese %d numeros para obtener el mayor de ellos", MAX_NUMS);

    // Get x count of numbers from the user
    for (i = 0; i < MAX_NUMS; ++i) {
        int newVal = requestNum(i + 1);
        vals[i] = newVal;
    }

    // Loop array and store the largest number in arr[0]
    for (i = 1; i < MAX_NUMS; ++i) {
        // Change < to > if you want to find the smallest or biggest element
        if (vals[0] < vals[i]) vals[0] = vals[i];
    }

    // Print the first element in array
    printf("\nEl mayor elemento es: %d\n", vals[0]);

    return 0;
}
