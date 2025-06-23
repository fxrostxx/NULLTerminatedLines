#include <iostream>
#include <Windows.h>
using namespace std;

int StringLength(const char* str);
char* ToUpper(char* str);
char* ToLower(char* str);
char* Shrink(char* str); // ???
char* DeleteSpaces(char* str);
bool IsPalindrome(char* str);
bool IsIntNumber(char* str);
int ToIntNumber(char* str);
bool IsBinNumber(char* str);
int BinToDec(char* str);
bool IsHexNumber(char* str);
int HexToDec(char* str);


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
	int count{ 0 };

	while (*str != '\0')
	{
		++count;
		++str;
	}

	return count;
}

char* ToUpper(char* str)
{
	for (char* ptrStr = str; *ptrStr != '\0'; ++ptrStr)
	{
		if ((*ptrStr >= 'a' && *ptrStr <= 'z') || (*ptrStr >= 'а' && *ptrStr <= 'я')) *ptrStr -= 32;
		else if (*ptrStr == 'ё') *ptrStr -= 16;
	}

	return str;
}

char* ToLower(char* str)
{
	for (char* ptrStr = str; *ptrStr != '\0'; ++ptrStr)
	{
		if ((*ptrStr >= 'A' && *ptrStr <= 'Z') || (*ptrStr >= 'А' && *ptrStr <= 'Я')) *ptrStr += 32;
		else if (*ptrStr == 'Ё') *ptrStr += 16;
	}

	return str;
}

char* Shrink(char* str) // ???
{
	char* temp = str;

	for (char* ptrStr = str; *ptrStr != '\0'; ++ptrStr)
	{
		if (*ptrStr != ' ')
		{
			*temp = *ptrStr;

			++temp;
		}
	}

	*temp = '\0';

	return str;
}

char* DeleteSpaces(char* str)
{
	char* temp = str;

	for (char* ptrStr = str; *ptrStr != '\0'; ++ptrStr)
	{
		if (*ptrStr != ' ')
		{
			*temp = *ptrStr;

			++temp;
		}
	}

	*temp = '\0';

	return str;
}

bool IsPalindrome(char* str)
{
	char* temp = ToLower(DeleteSpaces(str));
	int len = StringLength(temp);
	bool IsPal{ true };

	for (int i = 0, j = len - 1; i < len / 2; ++i, --j)
	{
		if (temp[i] != temp[j])
		{
			IsPal = false;
			break;
		}
	}

	return IsPal;
}

bool IsIntNumber(char* str)
{
	bool IsInt{ true };

	if (*str == '+' || *str == '-') ++str;

	for (char* ptrStr = str; *ptrStr != '\0'; ++ptrStr)
	{
		if (*ptrStr < '0' || *ptrStr > '9')
		{
			IsInt = false;

			break;
		}
	}

	return IsInt;
}

int ToIntNumber(char* str)
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

bool IsBinNumber(char* str)
{
	bool IsBin{ true };

	if (*str == '+' || *str == '-') ++str;

	for (char* ptrStr = str; *ptrStr != '\0'; ++ptrStr)
	{
		if (*ptrStr < '0' || *ptrStr > '1')
		{
			IsBin = false;

			break;
		}
	}

	return IsBin;
}

int BinToDec(char* str)
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

bool IsHexNumber(char* str)
{
	bool IsHex{ true };

	if (*str == '+' || *str == '-') ++str;

	for (char* ptrStr = str; *ptrStr != '\0'; ++ptrStr)
	{
		if ((*ptrStr < '0' || *ptrStr > '9') && (*ptrStr < 'a' || *ptrStr > 'f') && (*ptrStr < 'A' || *ptrStr > 'F'))
		{
			IsHex = false;

			break;
		}
	}

	return IsHex;
}

int HexToDec(char* str)
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