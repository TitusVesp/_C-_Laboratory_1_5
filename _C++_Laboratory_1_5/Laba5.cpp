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
	cout << "Imput your expression(with space!!!!): " << endl;
	char* expr = new char[256];
	cin.getline(expr, 256);

	for (int i = 0; expr[i] > 0; i++) 
		if (!isdigit(expr[i]) && expr[i] != '+' && expr[i] != '-' && expr[i] != '/' && expr[i] != '*' && expr[i] != '(' && expr[i] != ')' && expr[i] != ' ')
	{
		cout << "Incorrect Input!" << endl;
		return;
	}
	Stack *st = new Stack();
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

