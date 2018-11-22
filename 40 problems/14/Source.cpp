/// Написать программу, которая осуществляет пирамидальную сортировку массива
//с использованием рекурсии.


#include "pch.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class Heap
{
private:
	int heapSize;
	vector<int> heapVector;
	void maxHeapify(int index);
	void swap(int* a, int* b)
	{
		int c = *a;
		*a = *b;
		*b = c;
	}

public:
	Heap(vector<int> newVector)//
	{
		heapVector = newVector;
		heapSize = newVector.size();
		for (int i=(heapSize - 2) / 2; i >= 0; i--)//для всех не листков справа налево делаем норм пирам
		{
			maxHeapify(i);
		}
	}
	Heap(int* newArray)
	{
		heapSize = sizeof(newArray) / sizeof(int);
		for (int i(0); i < heapSize; i++)
		{
			heapVector.push_back(newArray[i]);
		}
		for (int i=(heapSize - 2) / 2; i >= 0; i--)
		{
			maxHeapify(i);
		}
	}
	void heapSort();
	void printVector();
};

void Heap::maxHeapify(int parent)//возобновление свойства пирамиды проверяем батю и 2х сынов и максимум меняем с батей

{
	int max = parent;
	int leftChild = 2 * parent + 1;
	int rightChild = 2 * parent + 2;

	if (leftChild < heapSize && heapVector[leftChild] > heapVector[max])
	{
		max = leftChild;
	}

	if (rightChild < heapSize && heapVector[rightChild] > heapVector[max])
	{
		max = rightChild;
	}

	// change root, put max into the root
	if (max != parent)//меняем батю и макс запускаем для бати который стал сыном
	{
		swap(&heapVector[max], &heapVector[parent]);
		maxHeapify(max);
	}
}

void Heap::heapSort()
{
	while (heapSize > 1)//меняем1 с ласт и отрезаем
	{
		swap(&heapVector[0], &heapVector[heapSize - 1]);
		heapSize--;
		maxHeapify(0);//возобновляем пирамиду для нового корня
	}
}

void Heap::printVector()
{
	cout << "<";
	for (int i(0); i < heapVector.size(); i++)
	{
		cout << heapVector[i];
		if (i == heapVector.size()-1)
		{
			cout << "";
		}
		else 
		{
			cout<< ", ";
		}

	}

	cout << ">";
	cout << endl;
}

int enterLength()
{
	int l = 0;
	cout << "Enter your vector's length: ";
	do
	{
		cin >> l;
		if (l < 0)
		{
			cout << "It should be positive, try again: ";
		}
		else if (l == 0)
		{
			cout << "There's nothing to create,try again: ";
		}
	} while (l <= 0);
	return l;
}

int main()
{
	srand(time(NULL));
	vector<int> newVector1;
	int l = enterLength();
	cout << endl;
	cout << "************************************************" << endl << endl;
	if (l > 0)
	{
		cout << "Your randomly generated vector is: " << endl;
	}
	cout << "<";
	for (int i(0); i < l; i++)
	{
		newVector1.push_back(rand() % 100 + 1);
		cout << newVector1[i];
		if (i == l - 1)
		{
			cout << "";
		}
		else
		{
			cout << ", ";
		}
	}
	cout << ">";
	cout << endl << endl;
	cout << "************************************************" << endl << endl;


	Heap heap1(newVector1);
	cout << "Turning it into heap: " << endl;
	heap1.printVector();
	heap1.heapSort();
	cout <<endl<< "************************************************" << endl << endl;


	cout << "Sorted vector (using the HeapSort) : " << endl;
	heap1.printVector();
}
