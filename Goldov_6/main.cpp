#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void divide_files(fstream& f1, fstream& f2)
{
	int count = 0;
	while (!f1.eof())
	{
		char c;
		f1 >> c;
		f2 << c;
		if (c == '.' || count == 20)
		{
			f2 << "\n";
			count = -1;
		}
		count++;
	}
}

void open_file(fstream& f, const char* def_file)
{
	int k;
	cout << "Использовать свой файл(1) или исходный(любое число)?: ";
	cin >> k;
	if (k == 1)
	{
		cin.ignore();
		char file[50];
		cout << "Введите название файла: ";
		cin.getline(file, 50);

		f.open(file);
	}
	else
	{
		f.open(def_file);
	}
}

int main()
{
	setlocale(LC_ALL, "russian");

	fstream f1;

	cout << "Инициализация файла ввода\n";
	open_file(f1, "f1.txt");

	fstream f2;

	cout << "Инициализация файла вывода\n";
	open_file(f2, "f2.txt");

	divide_files(f1, f2);

	cout << "Разделение выполнено\n";

	f1.close();
	f2.close();

	system("pause");
}
