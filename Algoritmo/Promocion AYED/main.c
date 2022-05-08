# define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#if _DEBUG
# define CANT_PERSONAS 5
#else
# define CANT_PERSONAS 50
#endif

/*
* Realizar un programa en C/C++ que me permita registrar una agenda telefónica para 50 personas.
* La misma debe registrar los datos: Apellido y Nombre, Dirección, Teléfono, edad y documento.
* El programa deberá incluir las siguientes funciones:
    [x] Función de carga
    [x] Función de búsqueda por documento o por apellido
    [x] Función de ordenamiento por apellido e impresión de todos los registros
    [x] Menu porque me gusta ver las cosas
*/

#pragma once

void agregarPersona(struct Agenda* persona, int i);
void mostrarPersona(struct Agenda* persona, int i);
void mostrarPersonas(struct Agenda* persona, int cantPersonas);
void static sortAgenda(struct Agenda* persona, int cantPersonas);
void findInAgenda(struct Agenda* persona, int cantPersonas);
void showMenu(struct Agenda* persona, int cantPersonas);
// Util
bool compStrings(char a[], char b[]);
int getNum(int maxBuffer);
void clearConsole();

struct Agenda {
    int documento;
    int telefono;
    char nombre[30];
    char apellido[30];
    int edad;
};


int main() {
    const int cantPersonas = CANT_PERSONAS;
    struct Agenda persona[CANT_PERSONAS];

    // Populate array
    #if _DEBUG
    for (int i = 0; i < cantPersonas; i++) {
        //strcpy(persona[i].apellido, "pApellido");
        //strcpy(persona[i].nombre, "pNombre");
        persona[i].telefono = 6345*(i+1);
        persona[i].documento = 423*(i+1);
        persona[i].edad = (i+1)*2;
    }
    strcpy(persona[0].apellido, "zAmpa");
    strcpy(persona[0].nombre, "Zazzz");
    strcpy(persona[1].apellido, "vAs");
    strcpy(persona[1].nombre, "Vasaw");
    strcpy(persona[2].apellido, "Lumpa");
    strcpy(persona[2].nombre, "Floppa");
    strcpy(persona[3].apellido, "Redder");
    strcpy(persona[3].nombre, "Roco");
    strcpy(persona[4].apellido, "Rick");
    strcpy(persona[4].nombre, "Astley");

    printf("\nAutomatically populated structure array!\n");
    #else
    for (int i = 0; i < cantPersonas; i++)
        agregarPersona(persona, i);
    #endif

    showMenu(persona, cantPersonas);

    return 0;
}

void agregarPersona(struct Agenda *persona, int i) {
    printf("\n[Enter para confirmar]\n");
    printf("\nAgregando nueva persona a la agenda: N%d", i + 1);

    printf("\nIngrese el nombre de la persona: ");
    scanf("%30s", &(persona[i].nombre));
    fflush(stdin);

    printf("\nIngrese el apellido de la persona: ");
    scanf("%30s", &(persona[i].apellido));
    fflush(stdin);

    printf("\nIngrese el numero de documento de la persona: ");
    persona[i].documento = getNum(9);

    printf("\nIngrese el numero de telefono de la persona: ");
    persona[i].telefono = getNum(10);

    printf("\nIngrese la edad de la persona: ");
    persona[i].edad = getNum(3);
}

/// <summary>
/// Muestra todos los datos de una determinada persona en la Agenda
/// utilizando como indentificador su indice o posicion en la estructura
/// </summary>
void mostrarPersona(struct Agenda *persona, int i) {
    printf("\nTelefono: +%i", persona[i].telefono);
    printf("\nDocumento: %i", persona[i].documento);
    printf("\nNombre Completo: %s %s", persona[i].apellido, persona[i].nombre);
    printf("\nEdad: %i %s", persona[i].edad, persona[i].edad < 1 ? "ano" : "anos");
}

/// <summary>
/// Muestra todas las personas en la Agenda
/// Dependencias: mostrarPersona()
/// </summary>
void mostrarPersonas(struct Agenda *persona, int cantPersonas) {
    for (int i = 0; i < cantPersonas; i++) {
        printf("\n---------------");
        mostrarPersona(persona, i);
    }
    printf("\n---------------\n");
}

/// <summary>
/// Permite buscar una determinada persona en la Agenda
/// utilizando como parametros su ID o apellido
/// </summary>
void findInAgenda(struct Agenda* persona, int cantPersonas) {
    printf("\n[ INGRESE 0 PARA SALIR ]\n");

    sortAgenda(persona, cantPersonas);

    while (1) {
        fflush(stdin);
        bool found = false;
        char busqueda[30];

        printf("Ingrese el apellido o documento de la persona a buscar: ");
        scanf("%30s", busqueda);

        if (busqueda[0] == '0') break;

        if (
            isdigit(busqueda[0]) != 0
            && (isdigit(busqueda[1]) != 0 || busqueda[1] == '\0')
        ) {
            char *temp;
            int documento;

            // strtol return long, simply convert it to integer
            documento = (int) strtol(busqueda, &temp, 0);

            for (int i = 0; i < cantPersonas; i++)
                if (persona[i].documento == documento) {
                    mostrarPersona(persona, i);
                    found = true;
                    break;
                }
        }
        // If not, we treat the input as a string and expect to be a second name
        else {
            for (int i = 0; i < cantPersonas; i++)
                if (compStrings(persona[i].apellido, busqueda)) {
                    mostrarPersona(persona, i);
                    found = true;
                    break;
                }
        }

        if (found) break;
        else printf("\nNingun persona en la Agenda coincide con ese apellido o documento. Intentelo de nuevo.\n");
    }
}


/// <summary>
/// Ordena la estructura en la agenda utilizando el Ordenamiento Burbuja
/// alfabeticamente de acuerdo al Apellido de la persona en orden ascendente
/// </summary>
void static sortAgenda(struct Agenda* persona, int cantPersonas) {
    bool static wasSorted = false; // prevent re-sorting the struct
    if (wasSorted) {
        #if _DEBUG
            printf("\nAlready sorted!\n");
        #endif
        return;
    }

    #if _DEBUG
        printf("\nSorting...\n");
    #endif

    for (int i = 0; i < cantPersonas - 1; i++)
        for (int j = 0; j < cantPersonas - i - 1; j++)
            if (strcmp(persona[j].apellido, persona[j + 1].apellido) > 0) {
                struct Agenda temp = persona[j];
                persona[j] = persona[j + 1];
                persona[j + 1] = temp;
            }

    wasSorted = true;
}

/// <summary>
/// Hace un menu, quien lo diria
/// </summary>
void showMenu(struct Agenda* persona, int cantPersonas) {
    bool running = true;

    while (running) {
        printf("\n-------------------------------------------");
        printf("\n  0: SALIR DEL PROGRAMA");
        printf("\n  1: MOSTRAR AGENDA");
        printf("\n  2: BUSCAR PERSONA (APELLIDO O DOCUMENTO)");
        printf("\n  3: ORDENAR AGENDA SEGUN APELLIDO");
        printf("\n  5: LIMPIAR CONSOLA");
        printf("\n-------------------------------------------\n");
        printf("Ingrese accion a realizar: ");

        int busqueda = NULL;
        scanf("%2i", &busqueda);
        fflush(stdin);

        switch (busqueda) {
            case 0:
                running = !running;
                break;
            case 1:
                mostrarPersonas(persona, cantPersonas);
                break;
            case 2:
                findInAgenda(persona, cantPersonas);
                break;
            case 3:
                sortAgenda(persona, cantPersonas);
                break;
            case 5:
                clearConsole();
                break;
            default:
                printf("\nNo se ha encontrado ese resultado.\nPor favor, intentelo de nuevo.\n");
        }
    }
}

/// <summary>
/// Permite limpiar la consola.
/// PERO, debido a que es una llamada al sistema por parte de la consola podria tener
/// un comportamiento inseperado O el antivirus podria dar falsos positivos
/// </summary>
void clearConsole() {
    system("@cls||clear");
}

/// <summary>
/// Compara los caracteres de dos strings y retorna si sos iguales
/// Ignorando mayusculas y minusculas
/// </summary>
/// <returns>True si son iguales. False si no son iguales</returns>
bool compStrings(char a[], char b[]) {
    char *aa = (char*)malloc(sizeof(a));
    char *bb = (char*)malloc(sizeof(b));

    // Copy strings to a new array
    // Prevents modifing the current case sensitivity
    strncpy(aa, a, sizeof(a));
    strncpy(bb, b, sizeof(b));

    // Convert strings to lowercase
    for (int i = 0; aa[i]; i++) aa[i] = tolower(aa[i]);
    for (int j = 0; bb[j]; j++) bb[j] = tolower(bb[j]);

    // Loop through all the string until we find a variation
    // between the two or a null character
    int i = 0;
    while (aa[i] != '\0' && bb[i] != '\0') {
        if (aa[i] != bb[i]) {
            free(aa);
            free(bb);
            return false;
        }
        i++;
    }

    free(aa);
    free(bb);
    return true;
}

/// <summary>
/// Asegura que el input ingresado sea un numero
/// </summary>
/// <param name="maxBuffer">Cantidad de numeros que retornara</param>
/// <returns>Integer o -1 para errores</returns>
int getNum(int maxBuffer) {
    maxBuffer++; // n + 1 to count '\0'

    bool isValid = false;
    char* ch = (char*)malloc(maxBuffer * sizeof(char));

    // Out of memory?
    if (!ch) return -1;

    // Empty buffer
    while ((getchar()) != '\n');

    while (1) {
        fgets(ch, maxBuffer, stdin);

        // Prevent starting zero and empty/scaped strings
        if (strlen(ch) != 0 && ch[0] != '0' && !isspace(ch[0])) {
            bool nonNums = true;

            for (int i = 0; i < strlen(ch); i++) {
                if (ch[i] == '\0') break;
                if (isdigit(ch[i]) == 0 && !isspace(ch[i])) {
                    nonNums = false;
                    break;
                }
            }
            if (nonNums) isValid = true;
        }

        if (isValid) {
            fflush(stdin);
            char* temp;

            // Convert string to integer (returns long)
            int returnInt = (int)strtol(ch, &temp, 0);

            free(ch);
            return returnInt;
        }
        else printf("\nEl valor ingresado no es un numero. Intentelo de nuevo.\n");
    }

    // Something is wrong, I can feel it
    free(ch);
    return -1;
}
