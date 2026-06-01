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