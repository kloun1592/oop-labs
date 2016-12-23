#include "stdafx.h"

struct EquationRoot4
{
	double numRoots;
	double roots[4];
};

struct EquationRoots2
{
	int numRoots;
	double roots[2];
};

struct EquationRoots3
{
	int numRoots;
	double roots[3];
};

double sgn(double x)
{
	if (x > 0)   return 1;
	if (x == 0)  return 0;
	if (x < 0)   return -1;
}

// ¬ычисл€ем корни квадратного уравнени€ ax^2 + bx + c = 0
EquationRoots2 Solve2(double a, double b, double c)
{
	EquationRoots2 x;
	double d = b * b - 4 * a * c;
	if (d < 0)
	{
		throw std::domain_error("error msg");
	}
	if (d == 0)
	{
		x.roots[0] = -b / (2 * a);
		return x;
	}
	if (d > 0)
	{
		d = sqrt(d);
		x.roots[0] = (-b + d) / (2 * a);
		x.roots[1] = (-b - d) / (2 * a);
		return x;
	}
}

// ¬ычисл€ем корни кубического уравнени€ ax^3 + bx^2 + cx + d = 0
EquationRoots3 Solve3(double a, double b, double c, double d)
{
	EquationRoots3 x;
	double q = (a * a - 3 * b) / 9;
	double r = (2 * a * a * a - 9 * a * b + 27 * c) / 54;
	double s = q * q * q - r * r;

	if (s > 0)
	{
		double t = acos(r / sqrt(q * q* q)) / 3;
		x.roots[0] = 2 * sqrt(q) * cos(t) - (a / 3);
		//x.roots[1] = 2 * sqrt(q) * cos(t + (M_PI * 2) / 3) - a / 3;
		//x.roots[2] = 2 * sqrt(q) * cos(t - (M_PI * 2) / 3) - a / 3;
		return x;
	}

	if (s < 0)
	{
		if (q > 0)
		{
			double t = acosh(abs(r) / pow(q, 1.0 / 3));
			x.roots[0] = -2 * sgn(r) * sqrt(q) * cosh(t) - (a / 3);
			return x;
		}

		if (q < 0)
		{
			double t = asinh(abs(r) / abs(pow(q, 1.0 / 3)));
			x.roots[0] = -2 * sgn(r) * sqrt(q) * sinh(t) - (a / 3);
			return x;
		}

		if (q == 0)
		{
			x.roots[0] = -1 * pow(c - (a * a * a) / 27, 1.0 / 3) - (a / 3);
			return x;
		}
	}
	
	if (s == 0)
	{
		x.roots[0] = -2 * pow(r, 1.0 / 3) - (a / 3);
		return x;
	}
}

// ¬ычисл€ем корни уравнени€ 4-й степени ax^4 + bx^3 + cx^2 + dx + e = 0
EquationRoot4 Solve4(double a, double b, double c, double d, double e)
{
	if (a != 1)
	{
		throw std::invalid_argument("first coefficient should be > 0");
	}

	// px ^ 3 + qx ^ 2 + rx + s = 0
	double p = 1;
	double q = -c;
	double r = (b * d) - (4 * e);
	double s = (-(b * b * e)) + (4 * c * d) + (- (d * d));

	EquationRoots3 x = Solve3(p, q, r, s);

	double a2 = 1;
	double b2 = b / 2 + (b * b) / 4 - c + x.roots[0];
	double c2 = x.roots[0] / 2 + (x.roots[0] * x.roots[0]) / 4 - e;

	EquationRoots2 res = Solve2(a2, b2, c2);

	b2 = b / 2 - (b * b) / 4 + c - x.roots[0];
	c2 = x.roots[0] / 2 - (x.roots[0] * x.roots[0]) / 4 + e;

	EquationRoots2 res2 = Solve2(a2, b2, c2);

	EquationRoot4 answer;
	answer.roots[0] = res.roots[0];
	answer.roots[1] = res.roots[1];
	answer.roots[2] = res2.roots[0];
	answer.roots[3] = res2.roots[1];
	return answer;
}

int main()
{
	EquationRoots3 x = Solve3(2, -11, 12, 9);
	std::cout << x.roots[0] << std::endl;
	return 0;
}