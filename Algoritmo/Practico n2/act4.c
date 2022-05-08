#include <stdio.h>
#include <stdlib.h>
#define MIN_NUM_VAL 0

// Dynamic vector
int *dinamycVector(int n) {
    int *tmp = (int *)malloc(n * sizeof(int));

    if (tmp == NULL) {
        printf("Error: Out of memory …\n");
        exit(1);
    }
    return tmp;
}

int main() {
    int *Vector;
    int arrayLenght = 0;

    printf("Ingrese la cantidad de numeros: ");
    scanf("%d", &arrayLenght);

    // Set array
    if (arrayLenght < 1) arrayLenght = 1;
    Vector = dinamycVector(arrayLenght);
    Vector[0] = 0;  // ensure initial value

    int totalSum = 0;
    int index = 0;
    do {
        int numSelect = 0;

        printf("Num %d: ", index + 1);
        scanf("%d", &numSelect);

        if (numSelect >= MIN_NUM_VAL) {
            // Always ensure that the biggest value is the first one
            if (numSelect > Vector[0]) {
                Vector[index] = Vector[0];
                Vector[0] = numSelect;
            } else
                Vector[index] = numSelect;

            index++;
        } else
            printf("\nEl numero debe ser mayor a %d!\nIntentelo de nuevo. ", MIN_NUM_VAL);

    } while (index < arrayLenght);

    printf("El mayor numero es: %d", Vector[0]);

    // printf("Indexes: ");
    // for (int i = 0; i < arrayLenght; i++) printf("%d: %d\t", i + 1, Vector[i]);

    system("pause");
    return 0;
}
