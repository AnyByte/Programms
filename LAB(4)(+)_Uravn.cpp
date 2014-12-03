#include <iostream>
#include <cmath>

using namespace std;

double fun2(double x)
{
	return x - (x - cos(x)) / (1 + sin(x));
}

double fun(double x)
{
	return (x - cos(x));
}

int main()
{
	setlocale(LC_ALL, "Russian");
	const double e = 0.000001;
	double x0, x, a, b, t;
	int n = 0;
	cout << "Метод простой итерации" << endl;
	cout << "Введите переменную X: ";
	cin >> x;
	x0 = x - 1;
	while (abs(x - x0) > e)
	{
		x0 = x;
		x = cos(x0);
		n = n + 1;

	}
	cout << "Корень: " << x << ' ' << "Кол-во шагов: " << n << endl << endl;
	n = 0;
	cout << "Метод половинного деления" << endl;
	cout << "Введите переменные A и B: " << endl;
	cin >> a >> b;
	do
	{
		n++;
		t = (b + a) / 2;
		if (fun(a)*fun(t) > 0) a = t;
		else b = t;
	} while (abs(a - b) >= e);
	x = (a + b) / 2;
	cout << "Корень: " << x << ' ' << "Кол-во шагов: " << n << endl << endl;
	n = 0;
	cout << "Метод Ньютона" << endl;
	cout << "Введите переменную X: ";
	cin >> x;
	do
	{
		n++;
		x0 = x;
		x = fun2(x0);
	} while (abs(x - x0) >= e);
	cout << "Корень: " << x << ' ' << "Кол-во шагов: " << n << endl << endl;
	return 0;
}
