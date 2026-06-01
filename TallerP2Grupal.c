#include <stdio.h>
#include <stdlib.h>
void IngresarCalificaciones (int n, float calificaciones [][3]);
int main (){
    int n;
    printf("--Sistemas de gestion de calificaciones Udla--\n");
    printf("Ingrese la cantidad de estudiantes a registrar: ");
    while (scanf("%d", &n) !=1 || n<=0)
    {
        printf("Entrada invalida, ingrese un numero entero mayor a 0: ");
    }
    float calificaciones [n][3];
    IngresarCalificaciones(n,calificaciones);
    return 0;
}
void procesarEstudiantes(int n, float calificaciones[][3], float *promedios, float *maximos, float *minimos) {
    for (int i = 0; i < n; i++) {
        float suma = 0;
        float max = calificaciones[i][0];
        float min = calificaciones[i][0];

        for (int j = 0; j < 3; j++) {
            float nota = calificaciones[i][j];
            suma += nota;
            if (nota > max) max = nota;
            if (nota < min) min = nota;
        }
        *(promedios + i) = suma / 3.0f;
        *(maximos + i) = max;
        *(minimos + i) = min;
    }
}
