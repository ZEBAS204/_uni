#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VECTOR_SIZE 100
#define MIN_NUM_VAL 0
#define MAX_NUM_VAL 100

int main() {
    int vectorNumbs[VECTOR_SIZE] = {0};
    int numSelect = 0;
    int promedio = 0;

    printf("Ingrese numeros entre entre %d y %d:\n", MIN_NUM_VAL, MAX_NUM_VAL);

    int i = 0;
    do {
        printf("Num %d: ", i + 1);
        scanf("%d", &numSelect);

        if (numSelect >= MIN_NUM_VAL && numSelect <= MAX_NUM_VAL) {
            vectorNumbs[i] = numSelect;
            promedio += numSelect;
            i++;
        } else {
            printf("\nEl numero debe ser entre entre %d y %d!\nIntentelo de nuevo. ", MIN_NUM_VAL, MAX_NUM_VAL);
        }
    } while (i < VECTOR_SIZE);

    printf("\nPromedio total: %.2f", (float)promedio / VECTOR_SIZE);

    int repes = 0;
    for (size_t j = 0; j < VECTOR_SIZE; j++) vectorNumbs[j] == 10 && repes++;
    printf("\nEl numero 10 se ha repetido %d %s", repes, repes == 1 ? "vez" : "veces");

    int numEnteros = 0;
    for (size_t k = 0; k < VECTOR_SIZE; k++) vectorNumbs[k] % 2 == 0 && numEnteros++;
    printf("\nNumeros enteros encontrados: %d\n", numEnteros);

    system("pause");
    return 0;
}
