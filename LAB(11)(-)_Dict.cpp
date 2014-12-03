#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
//#include <Windows.h>

using namespace std;

struct translation
{
	string english;
	string russian;
};

bool sort_sorter(translation i, translation j){
    return i.english < j.english;
}

void read_dict()
{
	translation buffer;
	ifstream dict("dict.txt",ifstream::in | ifstream::binary);
	vector<translation> dictionary;
	while ((!dict.eof())&&(dict.good()))
	{
		getline(dict, buffer.english);
		getline(dict, buffer.russian);
		dictionary.push_back(buffer);
	};
	
	dict.close();
	
	sort(dictionary.begin(),dictionary.end(),sort_sorter);
	ofstream dict1("dict.txt",ofstream::out | ofstream::binary | ofstream::trunc);
	for (int i = 0; i < dictionary.size(); i++)
	{
		dict1 << dictionary[i].english;
		dict1 << endl;
		dict1 << dictionary[i].russian; 
		if (i+1 == dictionary.size()) break;
		dict1 << endl;
	}
	for (int i = 0; i < dictionary.size(); i++)
	{
		cout << dictionary[i].english;
		cout << endl;
		cout << dictionary[i].russian;
		if (i+1 == dictionary.size()) break;
		cout << endl;
	}
	
	dict1.close();
}

int main()
{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
    
	read_dict();
	return 0;
}
