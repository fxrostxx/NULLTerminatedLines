#include <iostream>
#include <Windows.h>
using namespace std;

int StringLength(const char* str);
char* ToUpper(char* str);
char* ToLower(char* str);
char* Shrink(char* str);
char* DeleteSpaces(char* str);
bool IsPalindrome(const char* str);
bool IsIntNumber(const char* str);
int ToIntNumber(const char* str);
bool IsBinNumber(const char* str);
int BinToDec(const char* str);
bool IsHexNumber(const char* str);
int HexToDec(const char* str);


int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	
	int SIZE{ 256 };
	char* str = new char[SIZE] {};

	cout << "Введите строку: "; cin.getline(str, SIZE);

	cout << "Длина строки: " << StringLength(str) << endl;

	cout << "Верхний регистр: " << ToUpper(str) << endl;

	cout << "Нижний регистр:  " << ToLower(str) << endl;

	cout << "Удаление лишних пробелов: " << Shrink(str) << endl;

	cout << "Введите строку: "; cin.getline(str, SIZE);

	cout << (IsPalindrome(str) ? "Строка - палиндром" : "Строка - не палиндром") << endl;

	cout << "Введите строку (число): "; cin.getline(str, SIZE);

	cout << (IsIntNumber(str) ? "Строка - целое десятичное число" : "Строка - не целое десятичное число") << endl;

	cout << "Числовое значение строки: " << ToIntNumber(str) << endl;

	cout << "Введите строку (число): "; cin.getline(str, SIZE);

	cout << (IsBinNumber(str) ? "Строка - двоичное число" : "Строка - не двоичное число") << endl;

	cout << "Десятичное значение строки: " << BinToDec(str) << endl;

	cout << "Введите строку (число): "; cin.getline(str, SIZE);

	cout << (IsHexNumber(str) ? "Строка - шестнадцатеричное число" : "Строка - не шестнадцатеричное число") << endl;

	cout << "Десятичное значение строки: " << HexToDec(str) << endl;

	delete[] str;

	SetConsoleCP(866);

	return 0;
}

int StringLength(const char* str)
{
	int i = 0;

	for (; str[i]; ++i);

	return i;
}

char* ToUpper(char* str)
{
	for (int i = 0; str[i]; ++i)
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'а' && str[i] <= 'я')) str[i] -= 32;
		else if (str[i] == 'ё') str[i] -= 16;
	}

	return str;
}

char* ToLower(char* str)
{
	for (int i = 0; str[i]; ++i)
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'А' && str[i] <= 'Я')) str[i] += 32;
		else if (str[i] == 'Ё') str[i] += 16;
	}

	return str;
}

char* Shrink(char* str)
{
	for (int i = 0; str[i]; ++i)
	{
		while (str[i] == ' ' && (str[i + 1] == ' '))
		{
			for (int j = i + 1; str[j]; ++j) str[j] = str[j + 1];
		}
	}

	return str;
}

char* DeleteSpaces(char* str)
{
	char* temp = str;

	for (int i = 0; str[i]; ++i)
	{
		if (str[i] != ' ')
		{
			*temp = str[i];

			++temp;
		}
	}

	*temp = '\0';

	return str;
}

bool IsPalindrome(const char* str)
{
	int len = StringLength(str);

	char* temp = new char[len + 1];
	for (int i = 0; str[i]; ++i) temp[i] = str[i];
	temp[len] = '\0';

	DeleteSpaces(temp);
	ToLower(temp);

	len = StringLength(temp);

	for (int i = 0, j = len - 1; i < len / 2; ++i, --j)
	{
		if (temp[i] != temp[j])
		{
			delete[] temp;

			return false;
		}
	}

	delete[] temp;

	return true;
}

bool IsIntNumber(const char* str)
{
	if (*str == '+' || *str == '-') ++str;

	for (int i = 0; str[i]; ++i)
	{
		if (str[i] < '0' || str[i] > '9') return false;
	}

	return true;
}

int ToIntNumber(const char* str)
{
	if (!IsIntNumber(str)) return 0;

	int number{ 0 };
	int sign{ 1 };

	if (*str == '-')
	{
		sign = -1;

		++str;
	}
	else if (*str == '+') ++str;

	while (*str != '\0')
	{
		number = number * 10 + (*str - '0');

		++str;
	}

	return number * sign;
}

bool IsBinNumber(const char* str)
{
	if (*str == '+' || *str == '-') ++str;

	for (int i = 0; str[i]; ++i)
	{
		if (str[i] < '0' || str[i] > '1') return false;
	}

	return true;
}

int BinToDec(const char* str)
{
	if (!IsBinNumber(str)) return 0;

	int number{ 0 };
	int sign{ 1 };

	if (*str == '-')
	{
		sign = -1;

		++str;
	}
	else if (*str == '+') ++str;

	while (*str != '\0')
	{
		number = number * 2 + (*str - '0');

		++str;
	}

	return number * sign;
}

bool IsHexNumber(const char* str)
{
	if (*str == '+' || *str == '-') ++str;

	for (int i = 0; str[i]; ++i)
	{
		if ((str[i] < '0' || str[i] > '9') && (str[i] < 'a' || str[i] > 'f') && (str[i] < 'A' || str[i] > 'F'))
			return false;
	}

	return true;
}

int HexToDec(const char* str)
{
	if (!IsHexNumber(str)) return 0;

	int number{ 0 };
	int sign{ 1 };

	if (*str == '-')
	{
		sign = -1;

		++str;
	}
	else if (*str == '+') ++str;

	while (*str != '\0')
	{
		char symbol = *str;
		int digit;

		if (symbol >= '0' && symbol <= '9') digit = symbol - '0';
		else if (symbol >= 'a' && symbol <= 'f') digit = 10 + (symbol - 'a');
		else if (symbol >= 'A' && symbol <= 'F') digit = 10 + (symbol - 'A');

		number = number * 16 + digit;

		++str;
	}

	return number * sign;
}