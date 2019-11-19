#include "Laba5.h"

class Stack
{
private:
	int position = 0;
	int data[100];
public:
	void Push(int obj) { data[position++] = obj; }
	int Pop() { return data[--position]; }
};

void RNP()
{
	cout << "Imput your expression, if you want to imput func press F(with space!!!!): " << endl;
	char* expr = new char[256];
	cin.getline(expr, 256);
	char temp = ' ';
	for (int i = 0; expr[i] > 0; i++)
	{
		if (!isdigit(expr[i]) && expr[i] != '+' && expr[i] != '-' && expr[i] != '/' && expr[i] != '*' && expr[i] != '(' && expr[i] != ')' && expr[i] != ' ' && expr[i] != 'F')
		{
			cout << "Incorrect Input!" << endl;
			return;
		}
		if (expr[i] != ' ') temp = expr[i];
	}
	if (isdigit(temp))
	{
		cout << "Incorrect Input!" << endl;
		return;
	}
	Stack* st = new Stack();
	int i = 0;
	while (expr[i] > 0)
	{
		int num = 0;
		if (isdigit(expr[i]))
		{
			num = expr[i] - '0';
			while (expr[i + 1] - '0' >= '0' && expr[i + 1] - '0' <= '9')
			{
				num = 10 * num + expr[i + 1] - '0';
				i++;
			}
			st->Push(num);
		}
		else
		{
			double op2;
			switch (expr[i])
			{
			case '+':
				st->Push(st->Pop() + st->Pop());
				break;
			case '*':
				st->Push(st->Pop() * st->Pop());
				break;
			case '-':
				op2 = st->Pop();
				st->Push(st->Pop() - op2);
				break;
			case '/':
				op2 = st->Pop();
				if (op2 != 0.0)
					st->Push(st->Pop() / op2);
				else
					cout << "Error -> devision by zero!" << endl;
				break;
			case 'F':
				st->Push(Func());
				break;
			case 'q':
				cout << "Result: " << st->Pop() << endl;
				break;
			case ' ': break;
			default:
				cout << "Error -> Unknow command!" << endl;
				break;
			}
		}
		i++;
	}

	cout << "Result: " << st->Pop() << endl;
}

int Strlength(char* str)
{
	int i = 0;
	while (str[i] != '\0') i++;
	return i;
}

int Func()
{
	cout << "Imput your expression: " << endl;
	char* expr = new char[256];
	char* expr_temp = new char[256];
	cin.getline(expr, 256);
	for (int i = 0, g = 0; i < Strlength(expr); i++)
	{
		if (expr[i] != ' ')
			expr_temp[g++] = expr[i];
	}
	expr = expr_temp;
	for (int i = 0; expr[i] > 0; i++) if (!isdigit(expr[i]) && expr[i] != '+' && expr[i] != '-' && expr[i] != '/' && expr[i] != '*' && expr[i] != '(' && expr[i] != ')')
	{
		cout << "Incorrect Input!" << endl;
		return 0;
	}
	Areph expression(expr);
	int result = expression.Expression();
	return result;
}

int Areph::Number()
{
	int result = get() - '0';
	while (peek() >= '0' && peek() <= '9')
	{
		result = 10 * result + get() - '0';
	}
	return result;
}

int Areph::Factor()
{
	if (peek() >= '0' && peek() <= '9')
		return Number();
	else if (peek() == '(')
	{
		get(); // '('
		int result = Expression();
		get(); // ')'
		return result;
	}
	else if (peek() == '-')
	{
		get();
		return -Factor();
	}
	return 0; // error
}

int Areph::Term()
{
	int result = Factor();
	while (peek() == '*' || peek() == '/')
		if (get() == '*')
			result *= Factor();
		else
			result /= Factor();
	return result;
}

int Areph::Expression()
{
	int result = Term();
	while (peek() == '+' || peek() == '-')
		if (get() == '+')
			result += Term();
		else
			result -= Term();
	return result;
}
