#include <stdio.h>
#include <stdlib.h>
#define CANT_VALORES 500

void cargarVector(int V[CANT_VALORES]) {
    int valor = 0;

    for (int i = 0; i < CANT_VALORES; i++) {
        printf("Valor n%d: ", i + 1);
        scanf("%d", &valor);
        V[i] = valor;
    }
}

int main() {
    int Vector[CANT_VALORES] = {0};
    int cantNum[] = {0, 0, 0};  // zeros, positivos, negativos
    int sumas[] = {0, 0};       // positivos, negativos

    printf("Ingrese %d valores para el vector:\n", CANT_VALORES);
    cargarVector(Vector);

    for (size_t i = 0; i < CANT_VALORES; i++) {
        if (Vector[i] == 0) cantNum[0]++;
        if (Vector[i] > 0) {
            cantNum[1]++;
            sumas[0] += Vector[i];
        }
        if (Vector[i] < 0) {
            cantNum[2]++;
            sumas[1] += Vector[i];
        }
    }

    printf("\nCantidad de valores:\n");
    printf("   Ceros: %d   Positivos: %d   Negativos: %d", cantNum[0], cantNum[1], cantNum[2]);
    printf("\nSuma de valores:\n   Positivos: %d\n   Negativos: %d", sumas[0], sumas[1]);

    system("pause");
    return 0;
}
