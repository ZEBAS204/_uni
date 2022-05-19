
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARTICULOS 100  // DEF: 100

/*
 * Se pide:
 * 1. Estructura Articulo { char nombre[50]; char codigo[30]; }
 * 2. Arreglo Articulos
 * 3. Funcion ingreso
 * 4. Funcion egreso
 * 5. Funcion imprimir listado
 * 6. Menu
 */

struct Articulo {
    char nombre[50];
    char codigo[30];
};

// Prototypes
void showMenu(struct Articulo stock[MAX_ARTICULOS]);
void showArticulo(struct Articulo *articulo);
void getArticulos(struct Articulo *stock);
void pushArticulo(struct Articulo *stock);
void popArticulo(struct Articulo *stock);

int main() {
    struct Articulo stock[MAX_ARTICULOS] = {0};

    printf("\nEspacio total de Stock: %d\n", MAX_ARTICULOS);

    // Execute menu loop
    showMenu(stock);

    return 0;
}

void showMenu(struct Articulo stock[MAX_ARTICULOS]) {
    bool running = true;

    while (running) {
        printf("\n-------------------------------------------");
        printf("\n  0: SALIR DEL PROGRAMA");
        printf("\n  1: MOSTRAR ARTICULOS");
        printf("\n  2: AGREGAR ARTICULO");
        printf("\n  3: REMOVER ARTICULO");
        printf("\n  5: LIMPIAR CONSOLA");
        printf("\n-------------------------------------------\n");
        printf("Ingrese accion a realizar: ");

        int busqueda = -1;

        if (scanf("%d%*c", &busqueda) == 0) {
            // Overflow
            fgetc(stdin);
            continue;
        };
        fflush(stdin);

        printf("\n");
        switch (busqueda) {
            case 0:
                running = !running;
                break;
            case 1:
                getArticulos(stock);
                break;
            case 2:
                pushArticulo(stock);
                break;
            case 3:
                popArticulo(stock);
                break;
            case 5:
                // Si el antivirus molesta, este es el responsable
                system("@cls||clear");
                break;
            default:
                printf("\nNo se ha encontrado ese resultado.\nPor favor, intentelo de nuevo.\n");
        }
    }
}

void showArticulo(struct Articulo *articulo) {
    printf("* NOMBRE: %s", articulo->nombre);
    printf("\n* CODIGO: %s", articulo->codigo);
}

void getArticulos(struct Articulo *stock) {
    if (iscntrl(*stock[0].nombre)) {
        printf("\nNo hay articulos en el stock\n");
        return;
    }

    printf("\nARTICULOS:\n");
    for (int i = 0; i < MAX_ARTICULOS; i++) {
        if (iscntrl(*stock[i].nombre)) break;

        printf("[%d]\n", i + 1);
        showArticulo(&stock[i]);
        printf("\n================\n");
    }
}

void pushArticulo(struct Articulo *stock) {
    fflush(stdin);

    // Create new struct to push to array
    struct Articulo newArticulo;

    printf("Ingrese el nombre del articulo: ");
    char nombre[50];
    fgets(nombre, 50, stdin);
    strtok(nombre, "\n");
    strcpy(newArticulo.nombre, nombre);

    printf("Ingrese el codigo del articulo: ");
    char codigo[30];
    fgets(codigo, 30, stdin);
    strtok(codigo, "\n");
    strcpy(newArticulo.codigo, codigo);

    printf("\nArticulo ingresado:\n");
    showArticulo(&newArticulo);

    // Try to locate a available space in the array
    // to push the new struct
    bool found = false;
    for (int i = 0; i < MAX_ARTICULOS; i++) {
        // printf("Scanning: %s\n", stock[i].codigo);

        if (iscntrl(stock[i].nombre[0])) {
            found = true;
            stock[i] = newArticulo;
            break;
        }
    }

    found
        ? printf("\nEl articulo ingresado se ha guardado\n")
        : printf("\n[!] No hay espacio para guardar el articulo ingresado\n");
}

void popArticulo(struct Articulo *stock) {
    if (iscntrl(*stock[0].nombre)) {
        printf("\nNo hay articulos en el stock\n");
        return;
    }

    printf("\nIngrese el codigo del articulo que desea eliminar: ");
    char codigo[30];
    fgets(codigo, 30, stdin);

    // Remove the trailing space at the end of the string
    // (without this the comparison will fail)
    strtok(codigo, "\n");

    // Try to locate the articulo in the array
    int index = -1;
    for (int i = 0; i < MAX_ARTICULOS; i++) {
        // printf("\n[%d] Comparing: [%s] === [%s]\n", i, stock[i].codigo, codigo);

        if (strcmp(stock[i].codigo, codigo) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("\nNo se han encontrado articulos con el codigo ingresado\n");
        return;
    }

    // Delete the articulo
    // Move all the articulos to the left
    for (int i = index; i < MAX_ARTICULOS; i++) {
        // Prevent the last item to get memory
        if (i == MAX_ARTICULOS - 1) {
            stock[i].nombre[0] = '\0';
            stock[i].codigo[0] = '\0';
            break;
        }

        stock[i] = stock[i + 1];
    }

    printf("\nArticulo eliminado!\n");
}
