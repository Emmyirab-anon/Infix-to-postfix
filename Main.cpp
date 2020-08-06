#include <iostream>
#include "StackType.h"
using namespace std;

int bodmas(char c)
{
	if (c == '^')
		return 3;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}
int main()
{
	StackType s;
	s.Push('X');
	string exp, newForm;
	cout << "Please input your expression: ";
	cin >> exp;

	int counter = 0;
	while (counter < exp.length())
	{
		switch (exp[counter])
		{
		case '(':
			s.Push('(');
			break;

		case ')':
			while (s.Top() != 'X' && s.Top() != '(')
			{
				char x = s.Top();
				s.Pop();
				newForm += x;
			}

			if (s.Top() == '(')
				s.Pop();
			break;

		case '*':
		case '/':
			while (s.Top() != 'X' && bodmas(exp[counter]) <= bodmas(s.Top()))
			{
				if (s.Top() != '(' && s.Top() != '+' && s.Top() != '-')
				{
					char x = s.Top();
					s.Pop();
					newForm += x;
				}
			}
			s.Push(exp[counter]);
			
			break;

		case '+':
		case '-':
			while (s.Top() != 'X' && bodmas(exp[counter]) <= bodmas(s.Top()))
			{
				if (s.Top() != '(')
				{
					char x = s.Top();
					s.Pop();
					newForm += x;
				}
			}
			s.Push(exp[counter]);
			break;
			
		case '^':
			while (s.Top() != 'X' && bodmas(exp[counter]) <= bodmas(s.Top()))
			{
				if (s.Top() != '(')
				{
					char x = s.Top();
					s.Pop();
					newForm += x;
				}
			}
			s.Push(exp[counter]);

		default:
			newForm += exp[counter];
		}

		counter++;
	}

	while (s.Top() != 'X' && bodmas(exp[counter]) <= bodmas(s.Top()))
	{
		char x = s.Top();
		s.Pop();
		newForm += x;
	}

	cout << newForm << endl;
	return 0;
}