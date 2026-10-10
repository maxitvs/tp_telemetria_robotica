#include <stdio.h>
#include "actuadores.h"

// Declaración e inicialización de un arreglo de motores
int main(){
    Motor celda[2] = {
        {101, 82.5, 3.2, 0x01}, // Motor 101: Encendido (Bit 0). Temp alta (> 75).
        {102, 45.0, 1.8, 0x03}  // Motor 102: Encendido (Bit 0) y Antihorario (Bit 1). Temp normal.
    };

    // Procesamiento de las alarmas mediante operaciones bit a bit
    printf("\n--------------------------------\n");
    printf("\n--- Inicializando Evaluacion ---\n");
    evaluar_estado(&celda[0]);
    evaluar_estado(&celda[1]);
    printf("\n--- Evaluacion Finalizada ---\n");
    printf("\n--------------------------------\n");

    // Guardar en archivo
    if(guardar_registro("telemetria.txt", celda, 2)){
        printf("Registro guardado con exito.\n");
    }

    // Leer y mostrar el archivo guardado
    printf("\n --- Leyendo archivo guardado --- \n");
    leer_registro("telemetria.txt");

    return 0;
}

//Compilar código: gcc main.c actuadores.c -o programa
//Ejecutar programa: .\programa.exe