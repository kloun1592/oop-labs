#include <array>

struct EquationRoots4
{
	int numRoots = 0;
	double roots[4] = { NULL, NULL, NULL, NULL };
};

struct EquationRoots2
{
	int numRoots = 0;
	double roots[2] = { NULL, NULL };
};

struct EquationRoots3
{
	int numRoots = 0;
	double roots[3] = { NULL, NULL, NULL };
};

// Вычисляем корни квадратного уравнения ax^2 + bx + c = 0
EquationRoots2 Solve2(double a, double b, double c);

// Вычисляем корни кубического уравнения ax^3 + bx^2 + cx + d = 0
EquationRoots3 Solve3(double a, double b, double c, double d);

// Вычисляем корни уравнения 4-й степени ax^4 + bx^3 + cx^2 + dx + e = 0
EquationRoots4 Solve4(double a, double b, double c, double d, double e);

double sgn(double const& x);
