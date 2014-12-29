#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


void matrix_output(double **mas, int N, int M)
{
	int k = 79 / M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << showpos << setprecision(int(k) - 9) << setw(int(k)) << mas[i][j];
			if (j == M - 1)
			{
				cout << endl;
			}
		}
	}
}

void matrix_create(double **mas, int N, int x)
{
	double k = double(x), m;
	mas[0][0] = x;
	for (int i = 1; i <= N; i++)
	{
		if (i == 1)
		{
			for (int j = 2; j <= N; j++)
			{
				mas[i - 1][j - 1] = mas[i - 1][j - 2] / j;
			}
		}
		else
		{
			for (int j = 1; j <= N; j++)
			{
				mas[i - 1][j - 1] = mas[i - 2][j - 1] * mas[0][j - 1];
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		mas[i][i] = 1;
	}
	for (int i = 3; i <= N; i += 2)
	{
		for (int j = 1; j < i; j++)
		{
			mas[i - 1][j - 1] *= (-1);
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout.flags(ios::scientific);
	int number = 0, x;
	do
	{
		if (number > 7) cout << "Введите число: N < 8: ";
		else cout << "Введите число: N < 8: ";
		cin >> number;
	} while (number > 7);
	double **mas = new double *[number];
	for (int i = 0; i < number; i++)
		mas[i] = new double[number];
	cout << "Введите число х: ";
	cin >> x;
	matrix_create(mas, number, x);
	cout << endl << "Вывод матрицы:" << endl << endl;
	matrix_output(mas, number, number);
	delete[]mas;
	cout << endl;
	return 0;
}
