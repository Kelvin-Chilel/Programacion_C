#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXTO 1500

void guardar_texto(const char *texto, const char *nombre_archivo) {
    FILE *archivo = fopen(nombre_archivo, "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo %s para escritura.\n", nombre_archivo);
        return;
    }

    fprintf(archivo, "%s", texto);
    fclose(archivo);
    printf("Texto guardado en %s.\n", nombre_archivo);
}

void crear_archivo_binario(const char *texto, const char *nombre_archivo) {
    FILE *archivo = fopen(nombre_archivo, "wb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo %s para escritura binaria.\n", nombre_archivo);
        return;
    }

    fwrite(texto, sizeof(char), strlen(texto), archivo);
    fclose(archivo);
    printf("Archivo binario creado: %s.\n", nombre_archivo);
}

void crear_archivo_txt(const char *texto, const char *nombre_archivo) {
    guardar_texto(texto, nombre_archivo);
}

int main() {
    char texto[MAX_TEXTO];
    char nombre_archivo[MAX_TEXTO];
    int opcion;

    while (1) {
        printf("Menú de opciones:\n");
        printf("1. Ingresar texto y guardarlo en un archivo.\n");
        printf("2. Crear un archivo binario a partir del texto ingresado.\n");
        printf("3. Crear un archivo .txt a partir del texto ingresado.\n");
        printf("4. Salir.\n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1:
                printf("Ingrese el texto: ");
                fgets(texto, MAX_TEXTO, stdin);
                texto[strcspn(texto, "\n")] = 0; 
                printf("Ingrese el nombre del archivo: ");
                fgets(nombre_archivo, MAX_TEXTO, stdin);
                nombre_archivo[strcspn(nombre_archivo, "\n")] = 0; 
                guardar_texto(texto, nombre_archivo);
                break;
            case 2:
                if (strlen(texto) == 0) {
                    printf("Primero debe ingresar texto en la opción 1.\n");
                } else {
                    strcpy(nombre_archivo, "archivo_binario.bin");
                    crear_archivo_binario(texto, nombre_archivo);
                }
                break;
            case 3:
                if (strlen(texto) == 0) {
                    printf("Primero debe ingresar texto en la opción 1.\n");
                } else {
                    strcpy(nombre_archivo, "archivo_txt.txt");
                    crear_archivo_txt(texto, nombre_archivo);
                }
                break;
            case 4:
                printf("Saliendo del programa.\n");
            default:
                printf("Opción inválida. Por favor, ingrese una opción válida.\n");
        }
    }

}
