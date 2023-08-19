// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>
#include <stdbool.h>  

typedef struct {
    double real;
    double imag;
    bool isComplex;
}Complex;

Complex solveQuadratic(double a, double b, double c) {
    Complex result;
    result.isComplex = false;
    if (a == 0){
        if (b == 0){
            printf("Valores no corresponden a una ecuación válida\n");
            result.real = 0.0;
            result.imag = 0.0;
        } else{
            printf("Valores corresponden a ecuación lineal\n");
            result.real = -c/b;
            result.imag = 0.0;
        }
        return result;
    }
    double discriminant = b * b - 4 * a * c;
    if (discriminant == 0){
        result.real = -b/(2*a);
        result.imag = 0.0;
    } else if (discriminant > 0) {
        result.real = (-b + sqrt(discriminant)) / (2 * a);
        result.imag = (-b - sqrt(discriminant)) / (2 * a);
    } else {
        result.real = -b / (2 * a);
        result.imag = sqrt(-discriminant) / (2 * a);
        result.isComplex = true;
    }
    return result;
}
int main() {
    double a, b, c;
    Complex solution;
    printf("Ingrese los coeficientes de la ecuación cuadrática (ax2 + bx + c):\n");
    printf("a: ");
    scanf("%lf", &a);
    printf("b: ");
    scanf("%lf", &b);
    printf("c: ");
    scanf("%lf", &c);
    solution = solveQuadratic(a, b, c);
    if (solution.imag == 0.0 & solution.isComplex==false) {
        printf("Solución real: x = %.6lf\n", solution.real);
    } else if (solution.isComplex == false){
        printf("Soluciones reales:\n");
        printf("x1 = %.6lf\n", solution.real);
        printf("x2 = %.6lf\n", solution.imag);
    } else {
        printf("Soluciones complejas:\n");
        printf("x1 = %.6lf + %.6lfi\n", solution.real, solution.imag);
        printf("x2 = %.6lf - %.6lfi\n", solution.real, solution.imag);
    }
    return 0;
}
