#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

struct translation
{
	string english;
	string russian;
};

bool sort_sorter(translation i, translation j){
	return i.english < j.english;
}

int compare_en(string search_word, vector<translation> dictionary, int mid)
{
	int m = 0, lenght;
	if (dictionary[mid].english.size() > search_word.size())
	{
		lenght = search_word.size();
		m = 2;
	}
	else if (search_word.size() > dictionary[mid].english.size())
	{
		lenght = dictionary[mid].english.size();
		m = 1;
	}
	else lenght = search_word.size();
	int stop = 0, direction = 0;
	for (int i = 0; i < lenght; i++)
	{
		if (stop == 1) break;
		if (int(search_word[i]) < int(dictionary[mid].english[i]))
		{
			direction = 1;
			stop = 1;
		}
		if (int(dictionary[mid].english[i]) < int(search_word[i]))
		{
			direction = 2;
			stop = 1;
		}
	}
	if (direction != 0) return (direction);
	else return (m);
}

int compare_ru(string search_word, vector<translation> dictionary, int mid)
{
	int lenght1 = dictionary[mid].russian.size() - 1;
	int lenght2 = search_word.size() - 1;
	if (lenght1 = lenght2)
	{
		for (int i = 0; i < lenght1; i++)
		{
			if (search_word[i] != dictionary[mid].russian[i]) return -1;
		}
		return 0;
	}
}

void search_word_en(vector<translation> dictionary)
{
	string search_word;
	cin >> search_word;
	int left = 0, right = dictionary.size() - 1, mid = 0;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (compare_en(search_word, dictionary, mid) == 1) right = mid - 1;
		else if (compare_en(search_word, dictionary, mid) == 2) left = mid + 1;
		else if ((compare_en(search_word, dictionary, mid) == 0) && (dictionary[mid].english.size() == search_word.size()))
		{
			cout << "Найдено слово и его перевод" << endl << dictionary[mid].english << endl << dictionary[mid].russian << endl;
			break;
		}
	}

}

void search_word_ru(vector<translation> dictionary)
{
	string search_word;
	cin >> search_word;
	int right = dictionary.size() - 1, mid = 0;
	for (; mid <= right;mid++)
	{
		if (0 == compare_ru(search_word, dictionary, mid))
		{
			cout << "Найдено слово и его перевод" << endl << dictionary[mid].russian << endl << dictionary[mid].english << endl;
			break;
		}
	}
}

void dictionary_update(vector<translation> &dictionary, translation buffer)
{
	int z;
	next:
	cout << "Вводите EN - RU, или пустую строку, если закончили: " << endl;
	while ((!cin.eof()) && (cin.good()))
	{
		getline(cin, buffer.english);
		if (buffer.english.size() > 0)
		{
			for (int i = 0; i < buffer.english.size(); i++)
			{
				if (int(buffer.english[i]) < 97) buffer.english[i] = int(buffer.english[i])+ 32;
			}
			for (int i = 0; i < dictionary.size(); i++)
			{
				if (dictionary[i].english == buffer.english)
				{
					cout << "Это слово уже есть в словаре!" << endl;
					cout << "Добавить синоним? 1/0: ";
					cin >> z;
					cin.get();
					if (z == 0) goto next;
				}
			}
		}
		if (buffer.english.size() == 0) break;
		getline(cin, buffer.russian);
		if (buffer.russian.size() > 0)
		{
			for (int i = 0; i < buffer.russian.size(); i++)
			{
				if (int(buffer.russian[i]) < -32) buffer.russian[i] = int(buffer.russian[i])+32;
			}
			for (int i = 0; i < dictionary.size(); i++)
			{
				if (dictionary[i].russian == buffer.russian)
				{
					cout << "Это слово уже есть в словаре!" << endl;
					cout << "Добавить синоним? 1/0: ";
					cin >> z;
					cin.get();
					if (z == 0) goto next;
				}
			}
		}
		dictionary.push_back(buffer);
	};
	sort(dictionary.begin(), dictionary.end(), sort_sorter);
	ofstream dict1("dict.txt", ofstream::out | ofstream::binary | ofstream::trunc);
	for (int i = 0; i < dictionary.size(); i++)
	{
		dict1 << dictionary[i].english;
		dict1 << endl;
		dict1 << dictionary[i].russian;
		if (i + 1 == dictionary.size()) break;
		dict1 << endl;
	}
	for (int i = 0; i < dictionary.size(); i++)
	{
		cout << dictionary[i].english;
		cout << " - ";
		cout << dictionary[i].russian;
		//if (i + 1 == dictionary.size()) break;
		cout << endl;
	}
	dict1.close();
}

void delete_en(vector<translation> &dictionary)
{
	string search_word;
	cin >> search_word;
	int right = dictionary.size() - 1, mid = 0;
	for (; mid <= right; mid++)
	{
		if ((compare_en(search_word, dictionary, mid) == 0) && (dictionary[mid].english.size() == search_word.size())) break;
	}
	dictionary.erase(dictionary.begin() + mid);
	sort(dictionary.begin(), dictionary.end(), sort_sorter);
	ofstream dict1("dict.txt", ofstream::out | ofstream::binary | ofstream::trunc);
	for (int i = 0; i < dictionary.size(); i++)
	{
		dict1 << dictionary[i].english;
		dict1 << endl;
		dict1 << dictionary[i].russian;
		if (i + 1 == dictionary.size()) break;
		dict1 << endl;
	}
	dict1.close();
	cout << "Слово удалено!" << endl;
}

void delete_ru(vector<translation> &dictionary)
{
	string search_word;
	cin >> search_word;
	int right = dictionary.size() - 1, mid = 0;
	for (; mid <= right; mid++)
	{
		if (0 == compare_ru(search_word, dictionary, mid)) break;
	}
	dictionary.erase(dictionary.begin() + mid);
	sort(dictionary.begin(), dictionary.end(), sort_sorter);
	ofstream dict1("dict.txt", ofstream::out | ofstream::binary | ofstream::trunc);
	for (int i = 0; i < dictionary.size(); i++)
	{
		dict1 << dictionary[i].english;
		dict1 << endl;
		dict1 << dictionary[i].russian;
		if (i + 1 == dictionary.size()) break;
		dict1 << endl;
	}
	dict1.close();
	cout << "Слово удалено!" << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector<translation> dictionary;
	
	translation buffer;
	ifstream dict("dict.txt", ifstream::in | ifstream::binary);
	while ((!dict.eof()) && (dict.good()))
	{
		getline(dict, buffer.english);
		getline(dict, buffer.russian);
		dictionary.push_back(buffer);
	};
	dict.close();
	sort(dictionary.begin(), dictionary.end(), sort_sorter);
	ofstream dict1("dict.txt", ofstream::out | ofstream::binary | ofstream::trunc);
	for (int i = 0; i < dictionary.size(); i++)
	{
		dict1 << dictionary[i].english;
		dict1 << endl;
		dict1 << dictionary[i].russian;
		if (i + 1 == dictionary.size()) break;
		dict1 << endl;
	}
	dict1.close();
	
	int n = 0;

	while (true)
	{
		while (n == 0){
			cout << "Что вы хотите сделать?\n" << endl;
			cout << "0. Показать меню\n"
				<< "1. Добавить слова\n"
				<< "2. Найти слово на английском\n"
				<< "3. Найти слово на русском\n"
				<< "4. Показать словарь\n"
				<< "5. Удалить слово EN\n"
				<< "6. Удалить слово RU\n"
				<< "7. выйти\n" << endl;
			cin >> n;
		}
		while (n == 1){
			cin.get();
			cout << "Добавьте слово и его перевод EN - RU: " << endl;
			dictionary_update(dictionary, buffer);
			cin >> n;
		}
		while (n == 2){
			cout << "Введите слово на английском:" << endl;
			cin.get();
			search_word_en(dictionary);
			cin.get();
			cin >> n;
		}
		while (n == 3){
			cout << "Введите слово на русском:" << endl;
			cin.get();
			search_word_ru(dictionary);
			cin.get();
			cin >> n;
		}
		while (n == 4){
			cout << "Вывод словаря на экран..." << endl;
			for (int i = 0; i < dictionary.size(); i++)
			{
				cout << dictionary[i].english;
				cout << " - ";
				cout << dictionary[i].russian;
				//if (i + 1 == dictionary.size()) break;
				cout << endl;
			}
			cin >> n;
		}
		while (n == 5){
			cout << "Введите слово на Английском: " << endl;
			delete_en(dictionary);
			cin.get();
			cin >> n;
		}
		if (n == 6){
			cout << "Введите слово на Русском: " << endl;
			delete_ru(dictionary);
			cin.get();
			cin >> n;
		}
		while ((n > 6) || (n < 0)) {
			cout << "Вы ввели неправильное число" << endl;
			cin >> n;
		}
	}
	return 0;
}
