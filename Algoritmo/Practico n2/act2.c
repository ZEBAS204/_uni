#include <stdio.h>
#include <stdlib.h>
#define VECTOR_SIZE 100

int main() {
    int vectorNumbs[VECTOR_SIZE] = {0};
    int numSum = 0;

    for (int i = 0; i < VECTOR_SIZE; i++) {
        printf("Ingrese numero %d a cargar en el vector: ", i + 1);
        scanf("%d", &vectorNumbs[i]);
        numSum += vectorNumbs[i];
    }

    printf("Promedio total: %.2f\n", (float)numSum / VECTOR_SIZE);

    system("pause");
    return 0;
}
