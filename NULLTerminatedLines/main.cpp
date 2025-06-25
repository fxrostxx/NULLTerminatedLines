#include <iostream>
#include <Windows.h>
using namespace std;

int StringLength(const char* str);
char* ToUpper(char* str);
char* ToLower(char* str);
char* Shrink(char* str);
char* RemoveSymbol(char* str, const char symbol);
bool IsPalindrome(const char* str);
bool IsIntNumber(const char* str);
int ToIntNumber(const char* str);
bool IsBinNumber(const char* str);
int BinToDec(const char* str);
bool IsHexNumber(const char* str);
int HexToDec(const char* str);
bool IsIPaddress(const char* str);
bool IsIPaddressV2(const char* str);
bool IsMACaddress(const char* str);
bool IsMACaddressV2(const char* str);


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

	cout << "Введите строку (IP-адрес): "; cin.getline(str, SIZE);

	cout << (IsIPaddress(str) ? "Строка - IP-адрес" : "Строка - не IP-адрес") << endl;
	cout << (IsIPaddressV2(str) ? "Строка - IP-адрес (IsIPaddressV2)" : "Строка - не IP-адрес (IsIPaddressV2)") << endl;

	cout << "Введите строку (MAC-адрес): "; cin.getline(str, SIZE);

	cout << (IsMACaddress(str) ? "Строка - MAC-адрес" : "Строка - не MAC-адрес") << endl;
	cout << (IsMACaddressV2(str) ? "Строка - MAC-адрес (IsMACaddressV2)" : "Строка - не MAC-адрес (IsMACaddressV2)") << endl;

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

char* RemoveSymbol(char* str, const char symbol)
{
	char* temp = str;

	for (int i = 0; str[i]; ++i)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; ++j) str[j] = str[j + 1];
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

	RemoveSymbol(temp, ' ');
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

bool IsIPaddress(const char* str)
{
	int len = StringLength(str);

	if (len < 7 || len > 15) return false;

	int segments{ 0 };
	int digits{ 0 };
	int number{ 0 };

	while (*str != '\0')
	{
		if (isdigit(*str))
		{
			number = number * 10 + (*str - '0');
			++digits;

			if (number > 255 || digits > 3) return false;
		}
		else if (*str == '.')
		{
			if (digits == 0) return false;

			number = 0;
			digits = 0;
			++segments;

			if (segments > 3) return false;
		}
		else return false;

		++str;
	}

	if (segments != 3 || digits == 0) return false;

	return true;
}

bool IsIPaddressV2(const char* str)
{
	int len = StringLength(str);

	if (len < 7 || len > 15) return false;

	char byte[4]{};

	for (int i = 0, j = 0, dots = 0; str[i]; ++i)
	{
		if (str[i] == '.')
		{
			j = 0;
			dots++;

			if (dots > 3 || ToIntNumber(byte) > 255) return false;

			continue;
		}

		byte[j++] = str[i];

		if (j > 3) return false;
	}

	return true;
}

bool IsMACaddress(const char* str)
{
	if (StringLength(str) != 17) return false;

	int number{ 0 };

	for (int i = 0; i < 17; ++i)
	{
		if (i % 3 == 2)
		{
			if (str[i] != ':' && str[i] != '-') return false;

			number = 0;
		}
		else
		{
			char symbol = str[i];
			int digit;

			if (symbol >= '0' && symbol <= '9') digit = symbol - '0';
			else if (symbol >= 'a' && symbol <= 'f') digit = 10 + (symbol - 'a');
			else if (symbol >= 'A' && symbol <= 'F') digit = 10 + (symbol - 'A');
			else return false;

			number = number * 16 + digit;

			if (number > 255) return false;
		}
	}

	return true;
}

bool IsMACaddressV2(const char* str)
{
	if (StringLength(str) != 17) return false;

	char byte[4]{};

	for (int i = 0, j = 0, separators = 0; str[i]; ++i)
	{
		if (str[i] == ':' || str[i] == '-')
		{
			j = 0;
			separators++;

			if (separators > 5 || HexToDec(byte) > 255) return false;

			continue;
		}

		if (!isxdigit(str[i])) return false;

		byte[j++] = str[i];

		if (j > 2) return false;
	}

	return true;
}