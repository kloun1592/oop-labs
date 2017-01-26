#include "stdafx.h"

template <typename T>
T ArraySum(std::vector<T> const& arr, T && beginValue)
{
	if (!arr.empty())
	{
		auto sum = beginValue;
		for (auto elem: arr)
		{
			sum += elem;
		}
		return sum;
	}
	return T();
}

int main()
{
	std::string emptyStr = "";
	std::vector<int> arrInt = { 1, 1, 1 };
	std::cout << "Int sum: " << ArraySum(arrInt, 0) << std::endl;

	std::vector<float> arrFloat = { 1.2f, 1.1f, 1.0f };
	std::cout << "Float sum: " << ArraySum<>(arrFloat, 0.0f) << std::endl;

	std::vector<std::string> arrStr = { "an", "sw", "er" };
	std::cout << "Str sum: " << ArraySum(arrStr, std::move(emptyStr)) << std::endl;

	return 0;
}
