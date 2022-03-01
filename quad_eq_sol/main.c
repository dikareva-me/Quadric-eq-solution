#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#pragma warning(disable : 4996)

typedef struct complex_t {
	double real;
	double imag;
}complex_t;

typedef struct root_t {
	complex_t x1;
	complex_t x2;
} root_t;

root_t InitRoot() {
	root_t root;
	root.x1.imag = 0;
	root.x1.real = 0;
	root.x2.imag = 0;
	root.x2.real = 0;

	return root;
}

bool QuadricEqSolution(double a, double b, double c, root_t* roots) {
	if (a == 0) {
		printf("Equation is not quadric");
		return false;
	}
	*roots = InitRoot();
	double D = 0;
	D = b * b - 4 * a * c;
	
	if (D > 0) {
		D = sqrt(D);
		roots->x1.real = (-b + D) / (2 * a);
		roots->x2.real = (-b - D) / (2 * a);
		return true;
	}
	else {
		roots->x1.real = -b / (2 * a);
		roots->x2.real = roots->x1.real;

		if (D == 0) 
			return true;
		else {
			D = sqrt(-D);
			roots->x1.imag = sqrt(D) / (2 * a);
			roots->x2.imag = -sqrt(D) / (2 * a);
			return true;
		}
	}
}
void PrintRoots(root_t roots) {
	if (roots.x1.real == roots.x2.real) {
		if (roots.x1.imag == roots.x2.imag)
				printf("\nThe root is %.3lf", roots.x1.real);
		else printf("\nThe roots are %.3lf+%.3lfi and %.3lf%.3lfi", 
			roots.x1.real, roots.x1.imag, roots.x2.real, roots.x2.imag);
	}
	else
		printf("\nThe roots are %.3lf and %.3lf", roots.x1.real, roots.x2.real);
}

int main() {
	double a = 0, b = 0, c = 0;
	printf("Input a, b, c of quadratic equation ax^2 + bx + c = 0 separated by space\n");
	scanf("%lf %lf %lf", &a, &b, &c);

	root_t roots;
	QuadricEqSolution(a, b, c, &roots);
	PrintRoots(roots);
	return 0;
}