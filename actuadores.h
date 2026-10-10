#ifndef ACTUADORES_H
#define ACTUADORES_H
#include <stdio.h>

typedef struct {
 int id; // Identificador único del motor (ej: 101, 102)
 float temperatura; // Temperatura en grados Celsius
 float corriente; // Consumo en Amperes
 unsigned char estado; // Registro de flags de 8 bits
} Motor;

// Prototipo de la función de evaluación
void evaluar_estado(Motor *m);

//Prototipo para el manejo de archivos
int guardar_registro(const char *nombre_archivo, Motor motores[], int cantidad);
int leer_registro(const char *nombre_archivo);

#endif