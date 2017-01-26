#include "stdafx.h"
#include "Stack.h"

int main()
{
	std::cout << "=====================================" << std::endl;
	std::cout << "Int stack" << std::endl;
	std::cout << std::endl;

	CMyStack<std::string> stringStack(2);
	stringStack.Push("str");
	stringStack.Push("str2");

	std::cout << "Top element of stack: " << stringStack.GetTopElement() << std::endl;
	std::cout << "Stack before pop: " << std::endl;
	stringStack.PrintStack();

	std::cout << "Stack after pop: " << std::endl;
	stringStack.Pop();
	stringStack.PrintStack();

	CMyStack<std::string> stringStack2(1);
	stringStack2 = stringStack;
	std::cout << "Another stack after copying: " << std::endl;
	stringStack.PrintStack();

	std::cout << "Stack after clear: " << std::endl;
	stringStack.Clear();
	stringStack.PrintStack();

	std::cout << "=====================================" << std::endl;
	std::cout << "Int stack" << std::endl;
	std::cout << std::endl;

	CMyStack<int> intStack(2);
	intStack.Push(1);
	intStack.Push(2);

	std::cout << "Top element of stack: " << intStack.GetTopElement() << std::endl;
	std::cout << "Stack before pop: " << std::endl;
	intStack.PrintStack();

	std::cout << "Stack after pop: " << std::endl;
	intStack.Pop();
	intStack.PrintStack();

	CMyStack<int> intStack2(1);
	intStack2 = intStack;
	std::cout << "Another stack after copying: " << std::endl;
	intStack2.PrintStack();

	std::cout << "Stack after clear: " << std::endl;
	intStack.Clear();
	intStack.PrintStack();
	return 0;
}
