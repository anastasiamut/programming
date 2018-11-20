//Даны две строки a и b, вывести строку х максимальной длины, состоящую из,
//букв, таких, что существует перестановка х, являющаяся подстрокой
//перестановки a и одновременно являющаяся подстрокой перестановки b.


#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

const int lettersCount = 52; //there are 26 letters in English alphabet; multiplying by 2 to include upper case

void InputString(string &str)
{
	cout << "Input string: ";
	getline(cin, str);
}

int* CountLetters(string str)
{
	int* result = new int[lettersCount];
	for (int i = 0; i < lettersCount; i++)
	{
		result[i] = 0;
	}
	for (int i = 0; i < str.size(); i++)
	{
		int index = str.at(i) - 'a';//если отнять от символа код буквы а то если это буква получим число от 0 до 25
		if (0 <= index && index < 26)//если это буква то в соотв ячейку в массиве добавляем 1
		{
			result[index]++;
		}
		else
		{
			index = str.at(i) - 'A';
			if (0 <= index && index < 26)
			{
				result[index + 26]++;
			}
		}

	}
	return result;
}

int main()
{
	string firstString;
	string secondString;
	InputString(firstString);
	InputString(secondString);
	int* countOfLettersInFirstString = CountLetters(firstString);
	int* countOfLettersInSecondString = CountLetters(secondString);


	int* countOfLettersInMaxSubstring = new int[lettersCount];
	cout << "Maximal Substring is: ";
	for (int i = 0; i < lettersCount; i++)
	{
		countOfLettersInMaxSubstring[i] = min(countOfLettersInFirstString[i], countOfLettersInSecondString[i]);
		for (int j = 0; j < countOfLettersInMaxSubstring[i]; j++)
		{
			if (i < 26)
			{
				cout << char(int('a') + i);//к коду буквы а добавляем номер ячейки
			}
			else
			{
				cout << char(int('A') + i - 26);
			}
		}
	}
}
