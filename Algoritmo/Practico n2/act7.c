#include <stdio.h>
#include <stdlib.h>
#define CANT_VALORES 50

void cargarVector(int V[CANT_VALORES]) {
    int valor = 0;

    for (int i = 0; i < CANT_VALORES; i++) {
        while (1) {
            printf("Valor n%d: ", i + 1);
            scanf("%d", &valor);

            if (valor > 0) {
                V[i] = valor;
                break;
            } else
                printf("\nEl valor debe ser mayor a 0 (cero).\nIntentelo de nuevo. ");
        }
    }
}

int main() {
    int V1[CANT_VALORES] = {0};
    int V2[CANT_VALORES] = {0};
    int V3[CANT_VALORES] = {0};

    printf("Ingrese %d valores para el vector 1:\n", CANT_VALORES);
    cargarVector(V1);
    printf("\nIngrese %d valores para el vector 2:\n", CANT_VALORES);
    cargarVector(V2);

    for (size_t i = 0; i < CANT_VALORES; i++) V3[i] = V1[i] + V2[i];

    printf("\n\nSuma de valores:\n");
    for (size_t k = 0; k < CANT_VALORES; k++) printf(
        "%d%s",
        V3[k], k == 0 ? "\t" : k % 10 == 0 ? "\n"
                                           : "\t");

    system("pause");
    return 0;
}
