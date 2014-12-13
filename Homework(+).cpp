#include <iostream>

using namespace std;

struct words
{
	char word[80] = { 0 };
	int lenght;
};

int main()
{
	words mas[40];
	char n;
	bool equal;
	int z = 0, d = 0;
	for (int i = 0; i < 40; i++)
	{
		for (int k = 0; k < 40; k++)
		{
			n = cin.get();
			if ((n >= 'a') && (n <= 'z'))
			{
				mas[i].word[z++] = n;
			}
			else if (n == ' ' || n == '\n')
			{
				mas[i].lenght = z;
				break;
			}
			else if (n == '.')
			{
				mas[i].lenght = z;
				break;
			}
		}
		d++;
		z = 0;
		if (n == '.')
			break;
	}
	for (int i = 0; i < d; i++)
	{
		for (int k = i + 1; k < d; k++)
		{
			if (mas[i].lenght == mas[k].lenght)
			{
				equal = true;
				 for (int s = 0; s < mas[i].lenght; s++)
				{
					if (mas[i].word[s] != mas[k].word[s])
					{
						equal = false;
						break;
					}
				}
				if (equal)
					mas[k].lenght = 0;
			}
		}
	}
	for (int i = 0; i < d; i++)
	{
		for (int k = 0; k < mas[i].lenght; k++)
		{
			cout << mas[i].word[k];
		}
		if (mas[i].lenght != 0) cout << ' ';
	}
}
