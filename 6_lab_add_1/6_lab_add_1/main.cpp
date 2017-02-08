#include "stdafx.h"
#include "StringStack.h"

int main()
{
	CStringStack stack;
	stack.Push("str");
	CStringStack stack2(stack);
	return 0;
}
