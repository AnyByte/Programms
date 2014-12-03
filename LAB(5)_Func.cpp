#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x)
{
	double s, n;
	n = x;
	s = n;
	for (int i = 2; i <= 7; i++)
	{
		n = n*x / i;
		s += n;
	}
	return 1 + s - exp(x);
}

int main()
{
	cout << std::fixed << std::showpos << std::left;
	double x = -2;
	cout << setw(3) << "x" << "	" << setw(16) << "f(x)" << endl << endl;
	for (; x < 2.1; x = x + 0.1)
	{
		cout << setprecision(2) << setw(3) << x << "	" << setw(16) << setprecision(15) << f(x) << endl;
	}
	return 0;
}
