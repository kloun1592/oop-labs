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

#pragma warning(push)
#pragma warning(disable: 4715)
	double sgn(double const& x)
	{
		if (x > 0.0)   return 1.0;
		if (x == 0.0)  return 0.0;
		if (x < 0.0)   return -1.0;
	}
#pragma warning(pop)

// ��������� ����� ����������� ��������� ax^2 + bx + c = 0
EquationRoots2 Solve2(double const& a, double const& b, double const& c)
{
	if (a == 0.0)
	{
		throw std::invalid_argument("first coefficient should be > 0");
	}

	EquationRoots2 x;
	const double d = b * b - 4.0 * a * c;
	if (d < 0.0)
	{
		throw std::domain_error("Equation mustn't have complex roots");
	}
	if (d == 0.0)
	{
		x.numRoots = 1;
		x.roots[0] = -b / (2.0 * a);
	}
	if (d > 0.0)
	{
		x.numRoots = 2;
		x.roots[0] = (-b + sqrt(d)) / (2.0 * a);
		x.roots[1] = (-b - sqrt(d)) / (2.0 * a);
	}
	return x;
}

// ��������� ����� ����������� ��������� ax^3 + bx^2 + cx + d = 0
EquationRoots3 Solve3(double a, double b, double c, double d)
{
	if (a == 0.0)
	{
		throw std::invalid_argument("first coefficient should be > 0");
	}

	b /= a;
	c /= a;
	d /= a;

	EquationRoots3 x;
	const double q = (pow(b, 2) - 3 * c) / 9;
	const double r = (2 * pow(b, 3) - 9 * b * c + 27 * d) / 54;
	const double s = pow(q, 3) - pow(r, 2);

	if (s > 0)
	{
		const double phi = acos(r / sqrt(q * q * q)) / 3;
		x.numRoots = 3;
		x.roots[0] = 2 * sqrt(q) * cos(phi) - (b / 3);
		x.roots[1] = 2 * sqrt(q) * cos(phi + (M_PI * 2) / 3) - b / 3;
		x.roots[2] = 2 * sqrt(q) * cos(phi - (M_PI * 2) / 3) - b / 3;
	}

	if (s < 0)
	{
		if (q > 0)
		{
			const double phi = acosh(abs(r) / cbrt(q));
			x.numRoots = 1;
			x.roots[0] = -2 * sgn(r) * sqrt(q) * cosh(phi) - (b / 3);
		}

		if (q < 0)
		{
			const double phi = asinh(abs(r) / sqrt(pow(abs(q), 3))) / 3;
			x.numRoots = 1;
			x.roots[0] = -2 * sgn(r) * sqrt(abs(q)) * sinh(phi) - (b / 3);
		}

		if (q == 0)
		{
			x.numRoots = 1;
			x.roots[0] = -1 * cbrt(c - (b * b * b) / 27) - (b / 3);
		}
	}

	if (s == 0)
	{
		x.numRoots = 2;
		x.roots[0] = -2 * cbrt(r) - (b / 3);
		x.roots[1] = cbrt(r) - (b / 3);
	}
	return x;
}

// ��������� ����� ��������� 4-� ������� ax^4 + bx^3 + cx^2 + dx + e = 0
EquationRoots4 Solve4(double a, double b, double c, double d, double e)
{
	if (a == 0.0)
	{
		throw std::invalid_argument("first coefficient should be > 0");
	}

	b /= a;
	c /= a;
	d /= a;
	e /= a;

	// px^3 + qx^2 + rx + s = 0
	const double q = -c;
	const double r = (b * d) - (4 * e);
	const double s = -1 * (b * b * e) + 4 * c * e - (d * d);

	EquationRoots3 x = Solve3(1, q, r, s);

	const double a2 = 1;
	double b2 = b / 2 + sqrt((b * b) / 4 - c + x.roots[0]);
	double c2 = x.roots[0] / 2 + sqrt((x.roots[0] * x.roots[0]) / 4 - e);
	EquationRoots2 res = Solve2(a2, b2, c2);

	b2 = b / 2 - sqrt((b * b) / 4 - c + x.roots[0]);
	c2 = x.roots[0] / 2 - sqrt((x.roots[0] * x.roots[0]) / 4 - e);
	EquationRoots2 res2 = Solve2(a2, b2, c2);

	EquationRoots4 answer;
	answer.roots[0] = res.roots[0];
	answer.roots[1] = res.roots[1];
	answer.roots[2] = res2.roots[0];
	answer.roots[3] = res2.roots[1];
	return answer;
}