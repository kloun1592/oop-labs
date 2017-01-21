#include "stdafx.h"
#include "solve.h"

double sgn(double x)
{
	return (x > 0) - (x < 0);
}

// Вычисляем корни квадратного уравнения ax^2 + bx + c = 0
EquationRoots2 Solve2ByDiscriminant(double a, double b, double c)
{
	EquationRoots2 x;
	const auto d = b * b - 4 * a * c;
	if (d < 0)
	{
		throw std::domain_error("Equation has only complex roots");
	}
	else if (d == 0)
	{
		x.numRoots = 1;
		x.roots[0] = -b / (2 * a);
	}
	else
	{
		x.numRoots = 2;
		x.roots[0] = (-b + sqrt(d)) / (2 * a);
		x.roots[1] = (-b - sqrt(d)) / (2 * a);
	}
	return x;
}

EquationRoots2 Solve2(double a, double b, double c)
{
	if (a == 0)
	{
		throw std::invalid_argument("first coefficient mustn't be 0");
	}
	return Solve2ByDiscriminant(a, b, c);
}

// Вычисляем корни кубического уравнения x^3 + bx^2 + cx + d = 0
EquationRoots3 Solve3ByViete(double a, double b, double c)
{
	EquationRoots3 x;
	const auto q = (pow(a, 2) - 3 * b) / 9;
	const auto r = (2 * pow(a, 3) - 9 * a * b + 27 * c) / 54;
	const auto s = pow(q, 3) - pow(r, 2);

	if (s > 0)
	{
		const auto phi = acos(r / sqrt(pow(q, 3))) / 3;
		x.numRoots = 3;
		x.roots[0] = -2 * sqrt(q) * cos(phi) - (a / 3);
		x.roots[1] = -2 * sqrt(q) * cos(phi + (M_PI * 2) / 3) - a / 3;
		x.roots[2] = -2 * sqrt(q) * cos(phi - (M_PI * 2) / 3) - a / 3;
	} 
	else if (s < 0)
	{
		if (q > 0)
		{
			const auto phi = acosh(abs(r) / sqrt(pow(q, 3))) / 3;
			x.numRoots = 1;
			x.roots[0] = -2 * sgn(r) * sqrt(q) * cosh(phi) - (a / 3);
		}
		else if (q < 0)
		{
			const auto phi = asinh(abs(r) / sqrt(pow(abs(q), 3))) / 3;
			x.numRoots = 1;
			x.roots[0] = -2 * sgn(r) * sqrt(abs(q)) * sinh(phi) - (a / 3);
		}
		else
		{
			x.numRoots = 1;
			x.roots[0] = -cbrt(c - (pow(a, 3)) / 27) - (a / 3);
		}
	}
	else
	{
		x.numRoots = 2;
		x.roots[0] = -2 * cbrt(r) - (a / 3);
		x.roots[1] = cbrt(r) - (a / 3);
	}
	return x;
}

EquationRoots3 Solve3(double a, double b, double c, double d)
{
	if (a == 0)
	{
		throw std::invalid_argument("first coefficient mustn't be 0");
	}
	return Solve3ByViete(b / a, c / a, d / a);
}

// Вычисляем корни уравнения 4-й степени x^4 + ax^3 + bx^2 + cx + d = 0
EquationRoots4 Solve4ByFerrari(double a, double b, double c, double d)
{
	EquationRoots4 answer;

	// px^3 + qx^2 + rx + s = 0
	const auto q = -b;
	const auto r = (a * c) - (4 * d);
	const auto s = -1 * (a * a * d) + 4 * b * d - (c * c);

	EquationRoots3 x = Solve3(1, q,  r, s);

	auto a2 = 1;
	auto b2 = a / 2 + sqrt((a * a) / 4 - b + x.roots[0]);
	auto c2 = x.roots[0] / 2 + sqrt((x.roots[0] * x.roots[0]) / 4 - d);
	
	try
	{
		EquationRoots2 res = Solve2(a2, b2, c2);
		answer.roots[0] = res.roots[0];
		answer.roots[1] = res.roots[1];
		answer.roots[2] = NAN;
		answer.roots[3] = NAN;
	}
	catch (const std::exception)
	{
		answer.roots[0] = NAN;
		answer.roots[1] = NAN;
		b2 = a / 2 - sqrt((a * a) / 4 - b + x.roots[0]);
		c2 = x.roots[0] / 2 - sqrt((x.roots[0] * x.roots[0]) / 4 - d);
		EquationRoots2 res2 = Solve2(a2, b2, c2);
		answer.roots[2] = res2.roots[0];
		answer.roots[3] = res2.roots[1];
	}

	try
	{
		b2 = a / 2 - sqrt((a * a) / 4 - b + x.roots[0]);
		c2 = x.roots[0] / 2 - sqrt((x.roots[0] * x.roots[0]) / 4 - d);
		EquationRoots2 res2 = Solve2(a2, b2, c2);
	}
	catch (const std::exception)
	{
		answer.roots[2] = NAN;
		answer.roots[3] = NAN;
	}

	if (std::isnan(answer.roots[0]) &&
		std::isnan(answer.roots[1]) &&
		std::isnan(answer.roots[2]) &&
		std::isnan(answer.roots[3]))
	{
		throw std::domain_error("Equation has only complex roots");
	}
	return answer;
}

EquationRoots4 Solve4(double a, double b, double c, double d, double e)
{
	if (a == 0)
	{
		throw std::invalid_argument("first coefficient mustn't be 0");
	}
	return Solve4ByFerrari(b / a, c / a, d / a, e / a);
}
