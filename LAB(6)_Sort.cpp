#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void zero_plz(int &comp, int &change)
{
	comp = 0;
	change = 0;
}

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

void showme(int change, int comp, int n, int *y)
{
	for (int i = 0; i < n; i++) cout << y[i] << "  ";//вывод упорядоченного массива
	cout << "\n\n" << "Количество Перестановок: " << change << "\n" << "Количество Сравнений: " << comp;
}

void choicesSort(int* y, int n) // сортировка выбором
{
	int comp = 0;
	int change = 0;
	int b = 0;
	int k = 1;
	for (int j = 0; j < n; j++)
	{
		b = j;
		for (int i = j + 1; i < n; i++)
		{
			if (y[b] > y[i]) b = i;
			comp++;
		}
		if (b != j)
		{
			swap(y[b], y[j]);
			change++;
		}

	}
	showme(change, comp, n, y);
	zero_plz(comp, change);
}

void antimas(int* y, int n)
{
	for (int i = 0; i < n / 2; i++)
	{
		swap(y[i], y[n - 1 - i]);
	}
}

void bubble(int n)
{
	srand(time(NULL));

	int change = 0;
	int comp = 0;

	int *y = new int[n]; // одномерный динамический массив
	cout << "Сортировка данного массива по возрастанию пузырьком: " << "\n\n";
	for (int i = 0; i < n; i++)
	{
		y[i] = rand() % 100; // заполняем массив случайными числами
		cout << setw(2) << y[i] << "  "; // вывод массива на экран
	}
	cout << "\n\n";

	//упорядочивание элементов в массиве по возрастанию их значений
	for (int j = 1; j < n; j++)
	{
		bool sorted = true;
		for (int i = 0; i<n - j; i++)
			if (y[i]>y[i + 1]) //если текущий элемент больше следущего, то
			{
				change++;
				comp++;
				swap(y[i], y[i + 1]); //поменять их местами
				sorted = false;
			}
			else comp++;
			if (sorted) break;
	}
	showme(change, comp, n, y);
	zero_plz(comp, change);
	cout << "\n\n";
	antimas(y, n);
	cout << "Сортировка перевёрнутого массива по возрастанию: " << "\n\n";
	for (int i = 0; i < n; i++)
	{
		cout << setw(2) << y[i] << "  "; // вывод массива на экран
	}
	cout << "\n\n";
	for (int j = 1; j < n; j++)
	{
		bool sorted = true;
		for (int i = 0; i<n - j; i++)
			if (y[i]>y[i + 1]) //если текущий элемент больше следущего, то
			{
				change++;
				comp++;
				swap(y[i], y[i + 1]); //поменять их местами
				sorted = false;
			}
			else comp++;
			if (sorted) break;
	}
	showme(change, comp, n, y);
	zero_plz(comp, change);
	cout << "\n\n";
	cout << "Сортировка отсортированного массива по возрастанию: " << "\n\n";
	for (int i = 0; i < n; i++)
	{
		cout << setw(2) << y[i] << "  "; // вывод массива на экран
	}
	cout << "\n\n";
	for (int j = 1; j < n; j++)
	{
		bool sorted = true;
		for (int i = 0; i<n - j; i++)
		{
			if (y[i]>y[i + 1]) //если текущий элемент больше следущего, то
			{
				change++;
				comp++;
				swap(y[i], y[i + 1]); //поменять их местами
				sorted = false;
			}
			else comp++;
			if (sorted) break;
		}
	}
	showme(change, comp, n, y);
	cout << "\n";
	delete []y;
	cin.get();
}

void choice(int n)
{
	srand(time(NULL));

	int *y = new int[n]; // одномерный динамический массив
	cout << "Сортировка данного массива по возрастанию выбором: " << "\n\n";
	for (int i = 0; i < n; i++)
	{
		y[i] = rand() % 100; // заполняем массив случайными числами
		cout << setw(2) << y[i] << "  "; // вывод массива на экран
	}
	cout << "\n\n";
	choicesSort(y, n); // вызов функции сортировки выбором

	cout << "\n\n";

	cout << "Сортировка перевёрнутого массива по возрастанию: " << "\n\n";
	antimas(y, n);
	for (int i = 0; i < n; i++)
	{
		cout << setw(2) << y[i] << "  "; // вывод массива на экран
	}
	cout << "\n\n";
	choicesSort(y, n); // вызов функции сортировки выбором

	cout << "\n\n";

	cout << "Сортировка отсортированного массива по возрастанию: " << "\n\n";
	for (int i = 0; i < n; i++)
	{
		cout << setw(2) << y[i] << "  "; // вывод массива на экран
	}
	cout << "\n\n";
	choicesSort(y, n); // вызов функции сортировки выбором
	delete[]y;
	cin.get();
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "\nВведите размер массива: ";
	int n; // длинна массива
	cin >> n;
	bubble(n);
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
	choice(n);
	return 0;
}
