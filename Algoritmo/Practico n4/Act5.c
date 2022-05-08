#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Productos {
    char id[30];        // Codigo del articulo
    char nombre[30];    // Nombre del articulo
    float precio;       // Precio del articulo
    int stock;          // Cantidad de productos actuales en stock
    int cantMin;        // Cantidad minima de articulos en stock
};


void agregarProducto(struct Productos* producto, int i, int cantProductos);
void modificarProducto(struct Productos* producto, int i);
void menorMinimo(struct Productos* producto, int cantProductos);
void mostrarProducto(struct Productos* producto, int productIndex); // Show product by ID/CODIGO
void mostrarProductos(struct Productos* producto, int cantProductos);
int getProductIndexByID(struct Productos* producto, int cantProductos);
void showMenu(struct Productos* producto, int cantProductos);
bool compare(char a[], char b[]);

int main() {
    fflush(stdin);
    struct Productos* Producto;
    int cantProductos = 0;

    printf("\nIngresar el numero de Productos: ");
    scanf("%i", &cantProductos);
    fflush(stdin);

    // Alocar memoria para n cantidad de struct Productos
    Producto = (struct Productos*)malloc(cantProductos * sizeof(struct Productos));

    if (Producto == NULL) {
        puts("Sin memoria!\n");
        exit(1);
    }

    for (int i = 0; i < cantProductos; i++)
        agregarProducto(Producto, i, cantProductos);

    showMenu(Producto, cantProductos);

    getchar();

    return 0;
}

void showMenu(struct Productos* producto, int cantProductos) {
    bool running = true;

    while (running) {
        fflush(stdin);
        printf("\n-------------------------------------------");
        printf("\n  0: SALIR DEL PROGRAMA");
        printf("\n  1: MOSTRAR PRODUCTOS");
        printf("\n  2: VER O MODIFICAR PRODUCTO SEGUN CODIGO");
        printf("\n  3: MOSTRAR PRODUCTOS BAJO SU STOCK MINIMO");
        printf("\n  4: LIMPIAR CONSOLA");
        printf("\n-------------------------------------------\n");
        printf("Ingrese accion a realizar: ");
        int busqueda = NULL;
        scanf("%i", &busqueda);

        switch (busqueda) {
        case 0:
            running = !running;
            break;
        case 1:
            mostrarProductos(producto, cantProductos);
            break;
        case 2:
            modificarProducto(producto, getProductIndexByID(producto, cantProductos));
            break;
        case 3:
            menorMinimo(producto, cantProductos);
            break;
        case 4:
            system("@cls||clear"); // can fail
            break;
        default:
            printf("\nNo se ha encontrado ese resultado.\nPor favor, intentelo de nuevo.\n");
        }
    }
}

void agregarProducto(struct Productos* producto, int i, int cantProductos) {
    printf("\n[Enter para confirmar]\n");
    printf("\nCreando nuevo Producto N%d\n", i + 1);

    while (1) {
        char codigo[30];
        bool found = false;
        printf("Ingresar el codigo del Producto: ");
        fflush(stdin);
        scanf("%30s", &codigo);
        fflush(stdin);

        for (int j = 0; j < cantProductos; j++)
            if (j != i)
                if(!compare(producto[j].id, codigo)) found = true;

        if (!found) {
            strcpy(producto[i].id, codigo);
            break;
        }
        else
            printf("\nNo puede repetir el mismo codigo de producto. Intentelo de nuevo\n");
    }

    printf("Ingresar el nombre del Producto: ");
    scanf("%s", &(producto[i].nombre));
    fflush(stdin);

    printf("Ingresar el precio del Producto: $");
    scanf("%f", &(producto[i].precio));
    fflush(stdin);

    printf("Ingresar la cantidad actual del Producto en stock: ");
    scanf("%i", &(producto[i].stock));
    fflush(stdin);

    printf("Ingresar la cantidad minima que deberia tener el Producto en stock: ");
    scanf("%i", &(producto[i].cantMin));
    fflush(stdin);
}


void mostrarProducto(struct Productos* producto, int productIndex) {
    printf("\nCodigo: %s", producto[productIndex].id);
    printf("\nNombre: %s", producto[productIndex].nombre);
    printf("\nPrecio: %f", producto[productIndex].precio);
    printf("\nCantidad: %i", producto[productIndex].stock);
    printf("\nMin. Stock: %i", producto[productIndex].cantMin);
}

void mostrarProductos(struct Productos* producto, int cantProductos) {
    printf("\nProductos:");
    for (int i = 0; i < cantProductos; i++) {
        printf("\n-----");
        mostrarProducto(producto, i);
    }
}

void modificarProducto(struct Productos* producto, int i) {
    bool running = true;

    while (running) {
        system("@cls||clear"); // can fail
        fflush(stdin);
        mostrarProducto(producto, i);
        printf("\n----------------------------------------------------");
        printf("\n  0: SALIR");
        printf("\n  1: CAMBIAR PRECIO");
        printf("\n  2: CAMBIAR CANTIDAD");
        printf("\n----------------------------------------------------\n");
        printf("Ingrese accion a realizar: ");
        int busqueda = NULL;
        scanf("%i", &busqueda);
        fflush(stdin);

        switch (busqueda) {
        case 0:
            running = !running;
            break;
        case 1:
            printf("Ingrese el nuevo precio: $");
            scanf("%f", &(producto[i].precio));
            break;
        case 2:
            printf("Ingrese nuevo cantidad de articulos del Producto: ");
            scanf("%i", &(producto[i].stock));
            break;
        default:
            printf("\nNo se ha encontrado ese resultado.\nPor favor, intentelo de nuevo.\n");
        }
    }
}

void menorMinimo(struct Productos* producto, int cantProductos) {
    bool firstRun = false;
    for (int i = 0; i < cantProductos; i++) {
        if (producto[i].stock < producto[i].cantMin) {
            if (!firstRun) {
                printf("\nProductos con su stock debajo del minimo:");
                firstRun = false;
            }
            printf("\nCodigo: %s", producto[i].id);
            printf("\nNombre: %s", producto[i].nombre);
            printf("\n-----");
        }
    }
}

int getProductIndexByID(struct Productos* producto, int cantProductos) {
    printf("\n[ Ingrese salir para finalizar ]\n");
    int index = -1;

    while (1) {
        char codigo[30];
        printf("\nIngrese el codigo del producto: ");
        fflush(stdin);
        scanf("%30s", &codigo);
        fflush(stdin);

        for (int i = 0; i < cantProductos; i++) {
            index = i;
            break;
        }

        if (index != -1) return index;
        else
            printf("\nEl codigo introducido no coincide con ninguna lista de productos. Porfavor, intentelo de nuevo.\n");
    }
}


bool compare(char a[], char b[]) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return true;
        i++;
    }
    return false;
}
