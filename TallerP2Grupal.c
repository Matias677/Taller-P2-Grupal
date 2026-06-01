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
void IngresarCalificaciones(int n, float calificaciones[][3]) {
    for (int i = 0; i < n; i++) {
        printf("\n--- Registro del Estudiante %d ---\n", i + 1);
        for (int j = 0; j < 3; j++) {
            do {
                printf("  Nota Asignatura %d (0.0 - 10.0): ", j + 1);
                if (scanf("%f", &calificaciones[i][j]) != 1) {
                    printf("    Error: Ingrese un valor numerico valido.\n");
                    while (getchar() != '\n'); // Limpiar entrada invalida
                    calificaciones[i][j] = -1; // Forzar repeticion del bucle
                } else if (calificaciones[i][j] < 0.0 || calificaciones[i][j] > 10.0) {
                    printf("    Error: La nota debe estar en el rango de 0 a 10.\n");
                }
            } while (calificaciones[i][j] < 0.0 || calificaciones[i][j] > 10.0);
        }
    }
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
void procesarAsignaturas(
    int n,
    float calificaciones[][3],
    float *promediosAsig,
    float *maxAsig,
    float *minAsig,
    int *aprobados,
    int *reprobados)
{
    int i, j;

    for(j = 0; j < 3; j++)
    {
        float suma = 0;
        float max = calificaciones[0][j];
        float min = calificaciones[0][j];

        int contAprobados = 0;
        int contReprobados = 0;

        for(i = 0; i < n; i++)
        {
            float nota = calificaciones[i][j];

            suma += nota;

            if(nota > max)
            {
                max = nota;
            }

            if(nota < min)
            {
                min = nota;
            }

            if(nota >= 6)
            {
                contAprobados++;
            }
            else
            {
                contReprobados++;
            }
        }

        *(promediosAsig + j) = suma / n;
        *(maxAsig + j) = max;
        *(minAsig + j) = min;
        *(aprobados + j) = contAprobados;
        *(reprobados + j) = contReprobados;
    }
}