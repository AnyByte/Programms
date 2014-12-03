#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int x = 1;
	double n = (log(x) + sin(x)) / (x * x + log(x));
	double s = n;
	x++;
	cout << "Цикл FOR" << endl << endl;
	for (; n >= 0.0002; x++)
	{
		n = (log(x) + sin(x)) / (x * x + log(x));
		s += n;
		if (x == 20) cout << "Сумма первых 20 элементов: " << s << endl;
		if (x == 50) cout << "Сумма первых 50 элементов: " << s << endl;
		if (x == 90) cout << "Сумма первых 90 элементов: " << s << endl;
	}
	cout << endl;
	cout << "Сумма с заданной точностью: " << s << " При кол-ве элементов:" << x-1 << endl;
	cin.get();
	x = 1;
	n = (log(x) + sin(x)) / (x * x + log(x));
	s = n;
	x++;
	cout << "Цикл WHILE" << endl << endl;
	while (n >= 0.0002 )
	{
		n = (log(x) + sin(x)) / (x * x + log(x));
		s += n;
		if (x == 20) cout << "Сумма первых 20 элементов: " << s << endl;
		if (x == 50) cout << "Сумма первых 50 элементов: " << s << endl;
		if (x == 90) cout << "Сумма первых 90 элементов: " << s << endl;
		x++;
	}
	cout << endl;
	cout << "Сумма с заданной точностью: " << s << " При кол-ве элементов:" << x-1 << endl;
	cin.get();
	x = 1;
	s = (log(x) + sin(x)) / (x * x + log(x));
	x++;
	cout << "Цикл DO WHILE" << endl << endl;
	do
	{
		n = (log(x) + sin(x)) / (x * x + log(x));
		s += n;
		if (x == 20) cout << "Сумма первых 20 элементов: " << s << endl;
		if (x == 50) cout << "Сумма первых 50 элементов: " << s << endl;
		if (x == 90) cout << "Сумма первых 90 элементов: " << s << endl;
		x++;
	} while (n >= 0.0002);
	cout << endl;
	cout << "Сумма с заданной точностью: " << s << " При кол-ве элементов:" << x-1 << endl;
	cin.get();
	return 0;
}
