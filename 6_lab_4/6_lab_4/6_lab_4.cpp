#include "stdafx.h"
#include "solve.h"

int main()
{
	double a, b, c, d, e = 0;
	while ((std::cin >> a) && (std::cin >> b) && (std::cin >> c) && (std::cin >> d) && (std::cin >> e))
	{
		try
		{
			const auto roots = Solve4(a, b, c, d, e);
			for (unsigned i = 0; i < roots.numRoots; i++)
			{
				std::cout << "x = " << roots.roots[i] << std::endl;
			}
			std::cout << std::endl;
		}
		catch (const std::exception & ex)
		{
			std::cerr << ex.what() << std::endl << std::endl;
		}
	}
	return 0;
}
