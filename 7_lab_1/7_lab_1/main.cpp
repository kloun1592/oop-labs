#include "stdafx.h"

template <typename T>
T ArraySum(std::vector<T> const& arr)
{
	return !arr.empty() ? std::accumulate(arr.begin(), arr.end(), T()) 
						: T();
}

int main()
{
	std::vector<int> arrInt = { 1, 1, 1 };
	std::cout << "Int sum: " << ArraySum(arrInt) << std::endl;

	std::vector<float> arrFloat = { 1.2f, 1.1f, 1.0f };
	std::cout << "Float sum: " << ArraySum<>(arrFloat) << std::endl;

	std::vector<std::string> arrStr = { "an", "sw", "er" };
	std::cout << "Str sum: " << ArraySum(arrStr) << std::endl;

	std::vector<int> arrEmpty;
	std::cout << "Int sum2: " << ArraySum(arrEmpty) << std::endl;

	return 0;
}
