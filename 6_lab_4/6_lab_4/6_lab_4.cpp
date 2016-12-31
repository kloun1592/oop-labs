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
			for (const auto root : roots.roots)
			{
				std::cout << "x = " << root << std::endl;
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
