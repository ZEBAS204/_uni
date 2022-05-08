#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CANT_VALORES 30

int main() {
    srand((unsigned int)time(NULL));  // Seed
    int V1[CANT_VALORES] = {0};
    int V2[CANT_VALORES] = {0};
    int V3[CANT_VALORES] = {0};

    // Populate array
    for (size_t i = 0; i < CANT_VALORES; i++) {
        // random number between 0 and 200
        V1[i] = rand() % 200;
        V2[i] = rand() % 200;
        V3[CANT_VALORES - i] = V1[i] * V2[i];  // n - 1
    }

    for (int k = 0; k < CANT_VALORES; k++)
        printf("\n%d:\t%d * %d = %d", k + 1, V1[k], V2[k], V3[k]);

    system("pause");
    return 0;
}
