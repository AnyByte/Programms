#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct I_print{	//данные для печати результатов интегрирования
	char *name;//название функции
	double i_sum;	//значение интегральной суммы
	double i_toch;	//точное значение интеграла
	int n;	//число разбиений области интегрирования 
	//при котором достигнута требуемая точность
};

void PrintTabl(I_print i_prn[], int k)
{
	const int m = 4;//число столбцов таблицы
	int wn[m] = { 13, 25, 25, 11 };//ширина столбцов таблицы
	char *title[m] = { "Function ", " Integral  ", "   IntSum  ", "  N  " };
	int size[m];
	for (int i = 0; i < m; i++)
		size[i] = strlen(title[i]);
	//шапка таблицы
	cout << char(218) << setfill(char(196));
	for (int j = 0; j < m - 1; j++)
		cout << setw(wn[j]) << char(194);
	cout << setw(wn[m - 1]) << char(191) << endl;

	cout << char(179);
	for (int j = 0; j < m; j++)
		cout << setw((wn[j] - size[j]) / 2) << setfill(' ') << ' ' << title[j]
		<< setw((wn[j] - size[j]) / 2) << char(179);
	cout << endl;
	for (int i = 0; i < k; i++)
	{//заполнение таблицы
		cout << char(195) << fixed;
		for (int j = 0; j < m - 1; j++)
			cout << setfill(char(196)) << setw(wn[j]) << char(197);
		cout << setw(wn[m - 1]) << char(180) << setfill(' ') << endl;

		cout << char(179) << setw((wn[0] - strlen(i_prn[i].name)) / 2) << ' ' << i_prn[i].name
			<< setw((wn[0] - strlen(i_prn[i].name)) / 2) << char(179);
		cout << setw(wn[1] - 1) << setprecision(10) << i_prn[i].i_toch << char(179)
			<< setw(wn[2] - 1) << i_prn[i].i_sum << setprecision(6) << char(179)
			<< setw(wn[3] - 1) << i_prn[i].n << char(179) << endl;
	}
	//низ таблицы
	cout << char(192) << setfill(char(196));
	for (int j = 0; j < m - 1; j++)
		cout << setw(wn[j]) << char(193);
	cout << setw(wn[m - 1]) << char(217) << setfill(' ') << endl;
}


double if1(double a, double b){
	return (b*b - a*a) / 2.0;
}

double if2(double a, double b){
	return (cos(a*22.0) - cos(b*22.0)) / 22.0;
}

double if3(double a, double b){
	return (b*b*b*b*b - a*a*a*a*a) / 5.0;
}

double if4(double a, double b){
	return b*atan(b) - a*atan(a) - (log(b*b + 1) - log(a*a + 1)) / 2.0;
}

double f1(double x){
	return x;
}

double f2(double x){
	return sin(22 * x);
}

double f3(double x){
	return x*x*x*x;
}

double f4(double x){
	return atan(x);
}

void IntRect(double(*f)(double), double a, double b, double precision, int &amount, double &sum)
{
	double sum1 = 0;
	double sum2 = 0;
	double a1;
	int k = 1;
	double h;
	do
	{
		sum1 = sum2;
		sum2 = 0;
		a1 = a;
		if (k == 1)
		{
			k *= 2;
			h = (b - a1) / k;
			for (int i = 0; i < k; i++)
			{
				sum1 += (f(a1 + h / 2)) * h;
				a1 += h;
			}
		}
		a1 = a;
		k *= 2;
		h = (b - a1) / k;
		for (int i = 0; i < k; i++)
		{
			sum2 += (f(a1 + h / 2)) * h;
			a1 += h;
		}
	} while (abs(sum1 - sum2) >= precision);
	amount = k;
	sum = sum2;
}

void IntTrap(double(*f)(double), double a, double b, double precision,int &amount,double &sum)
{
	double sum1 = 0;
	double sum2 = 0;
	double a1;
	int k = 1;
	double h;
	do
	{
		sum1 = sum2;
		sum2 = 0;
		a1 = a;
		if (k == 1)
		{
			k *= 2;
			h = (b - a1) / k;
			for (int i = 0; i < k; i++)
			{
				sum1 += ((f(a1) + f(a1 + h)) / 2) * h;
				a1 += h;
			}
		}
		a1 = a;
		k *= 2;
		h = (b - a1) / k;
		for (int i = 0; i < k; i++)
		{
			sum2 += ((f(a1) + f(a1 + h)) / 2) * h;
			a1 += h;
		}
	} while (abs(sum1 - sum2) >= precision);
	amount = k;
	sum = sum2;
}

int main()
{
	I_print *i_prn = new I_print[40];
	double a, b, sum, precision = 0.1;
	int amount,i=0;
	cout << "Integration by the method of rectangles and trapezoids\n";
	cout << "Enter the interval: ";
	cin >> a >> b;
	for (int k = 0; k < 5; k++)
	{
		precision /= 10;
		IntRect(f1, a, b, precision,amount,sum);
		i_prn[i].name = "x";
		i_prn[i].i_sum = sum;
		i_prn[i].i_toch = if1(a,b);
		i_prn[i].n = amount;
		i++;
		IntRect(f2, a, b, precision,amount,sum);
		i_prn[i].name = "sin(22 * x)";
		i_prn[i].i_sum = sum;
		i_prn[i].i_toch = if2(a, b);
		i_prn[i].n = amount;
		i++;
		IntRect(f3, a, b, precision,amount,sum);
		i_prn[i].name = "x*x*x*x";
		i_prn[i].i_sum = sum;
		i_prn[i].i_toch = if3(a, b);
		i_prn[i].n = amount;
		i++;
		IntRect(f4, a, b, precision,amount,sum);
		i_prn[i].name = "atan(x)";
		i_prn[i].i_sum = sum;
		i_prn[i].i_toch = if4(a, b);
		i_prn[i].n = amount;
		i++;
		IntTrap(f1, a, b, precision,amount,sum);
		i_prn[i].name = "x";
		i_prn[i].i_sum = sum;
		i_prn[i].i_toch = if1(a, b);
		i_prn[i].n = amount;
		i++;
		IntTrap(f2, a, b, precision,amount,sum);
		i_prn[i].name = "sin(22 * x)";
		i_prn[i].i_sum = sum;
		i_prn[i].i_toch = if2(a, b);
		i_prn[i].n = amount;
		i++;
		IntTrap(f3, a, b, precision,amount,sum);
		i_prn[i].name = "x*x*x*x";
		i_prn[i].i_sum = sum;
		i_prn[i].i_toch = if3(a, b);
		i_prn[i].n = amount;
		i++;
		IntTrap(f4, a, b, precision,amount,sum);
		i_prn[i].name = "atan(x)";
		i_prn[i].i_sum = sum;
		i_prn[i].i_toch = if4(a, b);
		i_prn[i].n = amount;
		i = 0;
		cout << "Precision: " << precision << endl;
		PrintTabl(i_prn, 8);
		cout << endl;
	}
	cout << ". . . DONE! . . ." << endl;
	return 0;
}
