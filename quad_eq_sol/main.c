#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#pragma warning(disable : 4996)


typedef struct root_t {
	double x1;
	double x2;
} root_t;

root_t InitRoot() {
	root_t root;
	root.x1 = 0.0f;
	root.x2 = 0.0f;
	return root;
}

bool QuadricEqSolution(double a, double b, double c, root_t* roots) {
	if (a == 0.0f) {
		printf("Equation is not quadric");
		return false;
	}
	*roots = InitRoot();
	double D = 0.0f;
	D = b * b - 4.0 * a * c;
	
	if (D >= 0.0f) {
		D = sqrt(D);
		roots->x1 = (-b + D) / (2.0 * a);
		roots->x2 = (-b - D) / (2.0 * a);
		return true;
	}
	else {
		printf("There are no real roots.");
		return false;
	}
}
void PrintRoots(root_t roots) {
	if (roots.x1 == roots.x2)
		printf("\nThe root is %.3lf", roots.x1);
	else
		printf("\nThe roots are %.3lf and %.3lf", roots.x1, roots.x2);
}

void Input(double* a, double* b, double* c) {
	printf("Input a, b, c of quadratic equation ax^2 + bx + c = 0 separated by space\n");
	scanf("%lf %lf %lf", a, b, c);
}

int main() {
	double a = 0.0f, b = 0.0f, c = 0.0f;
	root_t roots;
	Input(&a, &b, &c);
	if (QuadricEqSolution(a, b, c, &roots) == true)
		PrintRoots(roots);
	return 0;
}