#include <iostream> 
#include <fstream> 
#include <cstdlib> // для exit()
#include <Windows.h>
using namespace std;

void Key()
{
	ifstream dict("dict.txt", ifstream::in | ifstream::binary);
	ofstream key("key.txt", ifstream::out | ifstream::binary | ifstream::trunc);
	unsigned char sum = 0;
	unsigned char data;
	data = dict.get();
	while (dict.good())
	{
		while ((data != ' ') && (dict.good()))
		{
			sum += data;
			data = dict.get();
		}
		key << int(sum) % 256 << ' ';
		sum = 0;
		data = dict.get();
	};
	dict.close();
	key.close();
}

void Encrypt()
{
	ifstream key("key.txt", ifstream::in | ifstream::binary);
	ofstream encrypt("encrypted.txt", ifstream::out | ifstream::binary | ifstream::trunc);
	unsigned char input;
	unsigned int sum = 0;
	input = cin.get();
	while (input != '.')
	{
		if (key.eof()) {
			key.clear();
			key.seekg(0);
			key >> sum;
		}
		key >> sum;
		encrypt << char(int(input) + sum);
		input = cin.get();
	};
	key.close();
	encrypt.close();
}

void show_encrypt()
{
	ifstream encrypt("encrypted.txt", ifstream::in | ifstream::binary);
	unsigned char n;
	do
	{
		n = encrypt.get();
		if (encrypt.eof()) break;
		cout << n;
	} while (!encrypt.eof());
}

void Decrypt()
{
	ifstream encrypt("encrypted.txt", ifstream::in | ifstream::binary);
	ifstream key("key.txt", ifstream::in | ifstream::binary);
	ofstream decrypt("decrypted.txt", ifstream::out | ifstream::binary | ifstream::trunc);
	unsigned char input;
	unsigned int sum = 0;
	input = encrypt.get();
	while (!encrypt.eof())
	{
		if (key.eof())
		{
			key.clear();
			key.seekg(0);
			key >> sum;
		}
		key >> sum;
		decrypt << char(int(input) - sum);
		cout << char(int(input) - sum);
		input = encrypt.get();
	};
	key.close();
	encrypt.close();
	decrypt.close();
}

void Statistics(bool choice)
{
	ifstream encrypt("encrypted.txt", ifstream::in | ifstream::binary);
	ifstream decrypt("decrypted.txt", ifstream::in | ifstream::binary);
	ofstream stats_file("statistics.txt", ifstream::out | ifstream::binary | ifstream::trunc);
	bool file;
	unsigned int stats[256][256] = { 0 };
	unsigned int i, k;
	do
	{
		i = decrypt.get();
		k = encrypt.get();
		if ((k >= 256) || (i >= 256)) break;
		stats[i][k]++;
	} while (!decrypt.eof());
	if (choice == false)
	{
		for (int m = 0; m < 256; m++)
		{
			for (int z = 0; z < 256; z++)
			{
				if (stats[m][z] != 0) cout << "Символ: " << char(m) << "(" << int(m) << ")" << " закодировался в символ: " << char(z) << "(" << int(z) << ")" << " " << stats[m][z] << " раз(а)" << endl;
			}
		}
	}
	if (choice == true)
	{
		for (int m = 0; m < 256; m++)
		{
			for (int z = 0; z < 256; z++)
			{
				if (stats[m][z] != 0) stats_file << "Символ: " << char(m) << "(" << int(m) << ")" << " закодировался в символ: " << char(z) << "(" << int(z) << ")" << " " << stats[m][z] << " раз(а)" << endl;
			}
		}
	}
	encrypt.close();
	decrypt.close();
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n = 0;

	while (true)
	{
		while (n == 0){
			cout << "Что вы хотите сделать?\n" << endl;
			cout << "0. Показать меню\n"
				<< "1. Создать/обновить ключ\n"
				<< "2. Зашифровать текст\n"
				<< "3. Расшифровать текст\n"
				<< "4. Вывести статистику на экран\n"
				<< "5. Вывести статистику в файл\n"
				<< "6. выйти\n" << endl;
			cin >> n;
		}
		while (n == 1){
			Key();
			cout << "Ключ создан/обновлён..." << endl;
			cin.get();
			cin >> n;
		}
		while (n == 2){
			cout << "Введите текст для шифровки:" << endl;
			cin.get();
			Encrypt();
			cout << "Зашифрованный текст сохранён в encrypted.txt" << endl;
			show_encrypt();
			cin.get();
			cin >> n;
		}
		while (n == 3){
			cout << "Расшифровка текста из файла encrypted.txt..." << endl;
			Decrypt();
			cout << endl;
			cin.get();
			cin >> n;
		}
		while (n == 4){
			cout << "Вывод статистики на экран..." << endl;
			Statistics(0);
			cin >> n;
		}
		while (n == 5){
			cout << "Статистика сохранена в файл statistics.txt" << endl;
			Statistics(1);
			cin.get();
			cin >> n;
		}
		if (n == 6){
			cout << "Выход из программы..." << endl;
			break;
		}
		while ((n > 6) || (n < 0)) {
			cout << "Вы ввели неправильное число" << endl;
			cin >> n;
		}
	}
	return 0;
}
