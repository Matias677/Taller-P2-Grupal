#include <stdio.h>
#include <stdlib.h>
//Declaracion de funciones
void IngresarCalificaciones (int n, float calificaciones [][3]);
void procesarEstudiantes(int n, float calificaciones[][3], float *promedios, float *maximos, float *minimos);
void procesarAsignaturas(int n, float calificaciones[][3], float *promediosAsig, float *maxAsig, float *minAsig, int *aprobados, int *reprobados);
void mostrarResultados(int n, float calificaciones[][3], float *promEst, float *maxEst, float *minEst, float *promAsig, float *maxAsig, float *minAsig, int *aprobAsig, int *reprobAsig);
int main (){
    int n;
    printf("--Sistemas de gestion de calificaciones Udla--\n");
    printf("Ingrese la cantidad de estudiantes a registrar: ");
    while (scanf("%d", &n) !=1 || n<=0)
    {
        printf("Entrada invalida, ingrese un numero entero mayor a 0: ");
    }
    float calificaciones [n][3];
    float promEstudiantes[n], maxEstudiantes[n], minEstudiantes[n];
    float promAsignaturas[3], maxAsignaturas[3], minAsignaturas[3];
    int aprobadosAsig[3], reprobadosAsig[3];

    IngresarCalificaciones(n, calificaciones);
    procesarEstudiantes(n, calificaciones, promEstudiantes, maxEstudiantes, minEstudiantes);
    procesarAsignaturas(n, calificaciones, promAsignaturas, maxAsignaturas, minAsignaturas, aprobadosAsig, reprobadosAsig);
    mostrarResultados(n, calificaciones, promEstudiantes, maxEstudiantes, minEstudiantes, promAsignaturas, maxAsignaturas, minAsignaturas, aprobadosAsig, reprobadosAsig);
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
void procesarAsignaturas(int n, float calificaciones[][3], float *promediosAsig, float *maxAsig, float *minAsig, int *aprobados, int *reprobados) {
    for (int j = 0; j < 3; j++) {
        float suma = 0;
        //En esta parte la calificacion minima y máxima es la misma para toda la fila, cuando el for arranca recorre todos los alumnos y va comparando cada calificacion con la maxima y minima, si encuentra una calificacion mayor a la maxima, esta se actualiza, lo mismo para la minima, si encuentra una calificacion menor a la minima, esta se actualiza.
        float max = calificaciones[0][j];
        float min = calificaciones[0][j];
        int contAprobados = 0;
        int contReprobados = 0;

        for (int i = 0; i < n; i++) {
            float nota = calificaciones[i][j];
            suma += nota;
            if (nota > max) max = nota;
            if (nota < min) min = nota;

            if (nota >= 6.0f) {
                contAprobados++;
            } else {
                contReprobados++;
            }
        }
        *(promediosAsig + j) = suma / (float)n;
        *(maxAsig + j) = max;
        *(minAsig + j) = min;
        *(aprobados + j) = contAprobados;
        *(reprobados + j) = contReprobados;
    }
}
void mostrarResultados(int n, float calificaciones[][3], float *promEst, float *maxEst, float *minEst, float *promAsig, float *maxAsig, float *minAsig, int *aprobAsig, int *reprobAsig) {
    printf("\n=========================================================\n");
    printf("                  REPORTE DE CALIFICACIONES              \n");
    
    // No te olvides que el %.1f es para mostrar solo un decimal 
    printf("Estudiante\tAsig1\tAsig2\tAsig3\tProm.\tMax\tMin\n");
    for (int i = 0; i < n; i++) {
        printf("Est. %d\t\t%.1f\t%.1f\t%.1f\t%.2f\t%.1f\t%.1f\n", 
               i + 1, calificaciones[i][0], calificaciones[i][1], calificaciones[i][2], 
               *(promEst + i), *(maxEst + i), *(minEst + i));
    }
    
    printf("\n---------------------------------------------------------\n");
    printf("ANÁLISIS ESTADÍSTICO POR ASIGNATURA:\n");
    
    for (int j = 0; j < 3; j++) {
        printf("Asignatura %d:\n", j + 1);
        printf("  > Promedio General: %.2f\n", *(promAsig + j));
        printf("  > Calificacion Mas Alta: %.1f\n", *(maxAsig + j));
        printf("  > Calificacion Mas Baja: %.1f\n", *(minAsig + j));
        printf("  > Estudiantes Aprobados: %d\n", *(aprobAsig + j));
        printf("  > Estudiantes Reprobados: %d\n", *(reprobAsig + j));
        printf("\n");
    }
    
}