#include "actuadores.h"
#include <stdio.h>

void evaluar_estado(Motor *m){
    if(m->temperatura > 75.0){
        m->estado = m->estado | 0x04;//      0000 0001  (Estado actual: solo encendido)
                                    //     | 0000 0100  (Máscara OR: quiero encender el Bit 2)
                                    //       ---------
                                    //       0000 0101  (Resultado: motor encendido con alarma)
    }
    //Si el resultado es distinto de 0, el bit está activo.
    int encendido = m->estado & 0x01;       // Máscara Bit 0 (0x01)
    int antihorario = m->estado & 0x02;     // Máscara Bit 0 (0x02)
    int alarma_temp = m->estado & 0x04;     // Máscara Bit 0 (0x03)
    int alarma_corr = m->estado & 0x08;     // Máscara Bit 0 (0x04)

    // Impresión por pantalla
    printf("\n Motor: %d: %s | Giro %s%s%s\n",
        m->id,
        encendido ? "Encendido" : "Apagado",
        antihorario ? "Antihorario" : "Horario",
        alarma_temp ? " | ALARMA TEMPERATURA ACTIVADA!" : "",
        alarma_corr ? " | ALARMA SOBRECORRIENTE ACTIVADA!" : "");
}
// Manejo de Archivos
int guardar_registro(const char *nombre_archivo, Motor motores[], int cantidad){
    FILE *fp = fopen(nombre_archivo, "w");
    if (fp == NULL){
        printf("ERROR: no se pudo crear el archivo\n");
        return 0;
    }
    // Cabecera del CSV
    fprintf(fp, "ID_Motor,Temperatura,Corriente,Estado_Hex\n");

    for(int i=0; i < cantidad; i++){
        fprintf(fp, "%d, %.1f, %.1f, 0x%02X\n",
            motores[i].id,
            motores[i].temperatura,
            motores[i].corriente,
            motores[i].estado);
    }

    fclose(fp);
    return 1;
    }
    
    // Manejo de Archivos - Leer
int leer_registro(const char *nombre_archivo){
    FILE *fp = fopen(nombre_archivo, "r");
    if (fp == NULL){
        printf("ERROR: no se pudo leer el archivo\n");
        return 0;
    }
    char linea[150]; // arreglo de caracteres"buffer" para leer cada línea
    while (fgets(linea, sizeof(linea), fp) != NULL){
        printf("%s", linea);
    }
    fclose(fp);
    return 1;
}