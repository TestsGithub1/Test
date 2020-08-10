#include <iostream>
using namespace std;
class Matrix
{
public:
//Это непонятная строка для проверки коммита создателя
	int razm_str;
	int razm_stolb;
	int** Table;
	Matrix()
	{
		razm_stolb = 3;
		razm_str = 3;
		Table = new int* [razm_str];
		for (int i = 0; i < razm_str; i++)
			Table[i] = new int[razm_stolb];
		for (int i = 0; i < razm_stolb; i++)
			for (int j = 0; j < razm_str; j++)
				Table[i][j] = 10;
	}
};
ostream& operator <<(ostream& t, Matrix a)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			t << a.Table[i][j] << " ";
		t << "\n";
	}
	return t;
}
Matrix& operator /=(Matrix& a, int num)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			a.Table[i][j] /= num;
	return a;
}
Matrix& operator -(Matrix& a, int empty)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			a.Table[i][j] = -a.Table[i][j];
	return a;
}
Matrix& operator +(Matrix& a, Matrix b)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			a.Table[i][j] += b.Table[i][j];
	return a;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	Matrix Example;
	Matrix Example1;
	while (true)
	{
		int l;
		cout << "1 - Чтобы отобразить матрицу\n";
		cout << "2 - Чтобы изменить знак матрицы\n";
		cout << "3 - Чтобы сложить две матрицы\n";
		cout << "4 - Чтобы поделить матрицу на число\n";
		cout << "5 - Чтобы выйти из программы\n";
		cin >> l;
		if (l == 1)
		{
			int k;
			cout << "Какую матрицу вы хотите отобразить (1 или 2)?\n";
			cin >> k;
			if (k == 1)
				cout << Example;
			else
				cout << Example1;
		}
		if (l == 2)
		{
			int k;
			cout << "Знак какой матрицы вы хотите изменить? (1 или 2)?\n";
			cin >> k;
			if (k == 1)
				Example - 1;
			else
				Example1 - 1;
		}
		if (l == 3)
			Example + Example1;
		if (l == 4)
		{
			int k, u;
			cout << "Какую матрицу вы хотите изменить? (1 или 2)?\n";
			cin >> k;
			cout << "На сколько вы хотите её поделить?\n";
			cin >> u;
			if (k == 1)
				Example /= u;
			else
				Example1 /= u;
		}
		if (l == 5)
			break;
	}
}
