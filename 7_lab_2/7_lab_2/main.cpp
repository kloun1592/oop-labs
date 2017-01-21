#include "stdafx.h"
#include "Stack.h"

using namespace std;

int main()
{
	CMyStack<string> stack(2);
	stack.Push("str");
	stack.Push("str2");
	stack.PrintStack();
	stack.Clear();
	cout << endl;
	stack.PrintStack();
	return 0;
}
