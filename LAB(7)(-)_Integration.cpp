#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void showIteration(int itteration, double result){
	cout << "Itteration " << itteration << " = " << result << endl;
}

double getStep(double a, double b, int itterationCount){
	return (fabs(b) - fabs(a)) / itterationCount;
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

double central(double(*f)(double), double a, double b, double h){   //центральные
	double sum = 0;
	int count = 0;
	for (double i = a; i < b - h / 2; i += h) {
		sum += f(i + h / 2)*h;
		//showIteration(count++, sum);
	}
	return sum;
}

double trapezoidal(double(*f)(double), double a, double b, double h){  //трапеции
	double sum = 0;
	int count = 0;
	for (double i = a; i < b - h / 2; i += h) {
		sum += (f(i) + f(i + h))*h / 2;
		//showIteration(count++, sum);
	}
	return sum;
}

int main(){
	setlocale(LC_ALL, "rus");
	double a;
	double b;
	double c;
	cout << "Введите a, b и точность(шаг): ";
		cin >> a >> b >> c;
		c = (b - a) / c;
	double h = getStep(a, b, c);

	cout << c << " итераций" << endl;
	cout << "x" << endl;
	cout << central(f1, a, b, h) << endl;
	cout << trapezoidal(f1, a, b, h) << endl << endl;

	cout << "sin(22 * x)" << endl;
	cout << central(f2, a, b, h) << endl;
	cout << trapezoidal(f2, a, b, h) << endl << endl;

	cout << "x^4" << endl;
	cout << central(f3, a, b, h) << endl;
	cout << trapezoidal(f3, a, b, h) << endl << endl;

	cout << "arctg(x)" << endl;
	cout << central(f4, a, b, h) << endl;
	cout << trapezoidal(f4, a, b, h) << endl << endl;

	cin.get();
}
