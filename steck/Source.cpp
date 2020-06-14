#include <iostream>
#include <string>
#include "Stack.h"
#include "Stack.cpp"
using namespace std;

enum ScopeType
{
	CIRCLE_IN = '(',
	CIRCLE_OUT = ')',
	FIGURE_IN = '{',
	FIGURE_OUT = '}',
	SQUARE_IN = '[',
	SQUARE_OUT = ']',
};

void CheckCorectCircleScopes(string str);

void main()
{
	//Stack st;
	//st.Push(56);
	//cout << "Count: " << st.GetCount() << endl;
	//st.Push(23);
	//st.Push(77);
	//st.Push(88);
	//cout << "Count: " << st.GetCount() << endl;
	//cout << "Element: " << st.Pop() << endl;
	//cout << "Count: " << st.GetCount() << endl;

	/*while (!st.IsEmpty())
		cout << st.Pop() << endl;*/

	/*string code = "void main() { Stack st(10); }";

	enum ScopeType
	{
		CIRCLE_IN = '(',
		CIRCLE_OUT = ')'
	};

	Stack scopes(10);

	for (char s : code)
	{
		switch (s)
		{
		case CIRCLE_IN:
			scopes.Push(s);
			break;
		case CIRCLE_OUT:
			if (scopes.Peek() == CIRCLE_IN)
				scopes.Pop();
			else
				cout << "Error at symbol: " << s << endl;
			break;
		}
	}
	if (!scopes.IsEmpty())
	{
		cout << "Error!" << endl;
	}
	else
		cout << "Correct code!\n";*/

	string code = "[void main()) { Stack st(10); }]";
	CheckCorectCircleScopes(code);

	system("pause");
}

void CheckCorectCircleScopes(string str)
{
	Stack<char> scopes;
	int z = 0;
	int index = 0;
	bool isCorrect = true;
	for (char s : str)
	{
		switch (s)
		{
		case CIRCLE_IN:
			scopes.Push(s);
			index = z;
			break;
		case FIGURE_IN:
			scopes.Push(s);
			index = z;
			break;
		case SQUARE_IN:
			scopes.Push(s);
			index = z;
			break;
		case CIRCLE_OUT:
			if (scopes.Peek() == CIRCLE_IN)
				scopes.Pop();
			else
			{
				cout << "Error at symbol: " << s << endl;
				for (int i = 0; i <= z; i++)
				{
					cout << str[i];
				}
				cout << endl;
				isCorrect = false;
			}
			break;
		case FIGURE_OUT:
			if (scopes.Peek() == FIGURE_IN)
				scopes.Pop();
			else
			{
				cout << "Error at symbol: " << s << endl;
				for (int i = 0; i <= z; i++)
				{
					cout << str[i];
				}
				cout << endl;
				isCorrect = false;
			}
			break;
		case SQUARE_OUT:
			if (scopes.Peek() == SQUARE_IN)
				scopes.Pop();
			else
			{
				cout << "Error at symbol: " << s << endl;
				for (int i = 0; i <= z; i++)
				{
					cout << str[i];
				}
				cout << endl;
				isCorrect = false;
			}
			break;
		}
		z++;
	}
	if (!scopes.IsEmpty())
	{
		//system("cls");
		cout << "Error!" << endl;
		for (int i = 0; i <= index; i++)
		{
			cout << str[i];
		}
		cout << endl;
	}
	else
	{
		if(isCorrect)
			cout << "Correct code!\n";
	}
}