////Реализовать работу динамической структуры: ОЧЕРЕДЬ
//Добавление элемента·Удаление·Сортировка : В работе использовать два метода
//сортировки : быструю и вставками.Сравнить эффективность.


#include "pch.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* prev;
};

struct Queue
{
	int Size;
	Node* Head;
	Node* Tail;
};

Queue* CreateEmpty()
{
	Queue* result = new Queue;
	result->Head = NULL;
	result->Tail = NULL;
	result->Size = 0;
	return result;
}


void Push(Queue* someQueue, int data)
{
	Node* toPush = new Node;
	toPush->data = data;
	toPush->prev = NULL;
	if (someQueue->Size > 0) 
	{
		someQueue->Tail->prev = toPush;
		toPush->next = someQueue->Tail;
	}
	else
	{
		toPush->next = NULL;
		someQueue->Head = toPush;
	}
	someQueue->Tail = toPush;
	someQueue->Size++;
}

Queue* CreateRandomQueue(int length)
{
	Queue* result = CreateEmpty();
	for (int i = 0; i < length; i++)
	{
		Push(result, rand() % 100);
	}
	return result;
}



Node* Remove(Queue* someQueue)
{
	if (someQueue->Size > 0)
	{
		Node* toRemove = someQueue->Head;
		someQueue->Head = someQueue->Head->prev;
		someQueue->Head->next = NULL;
		toRemove->prev = NULL;
		someQueue->Size--;
		delete toRemove;
	}
	else
	{
		return NULL;
	}
}



int enterLength()
{
	int l;
	cout << "Enter the length of your queue: ";
	do
	{

		cin >> l;
		if (l <= 0)
		{
			cout << "It should be positive, try again: ";
		}
	} while (l <= 0);

	return l;
}

int enterNumberofElementsToDelete(int length)
{
	cout << "How many elements do you want to remove from the queue?: ";
	int n;
	do
	{
		cin >> n;
		if (n < 0)
		{
			cout << "It should be positive, try again: ";
		}
		else if(n>=length)
		{
			cout << "It shouldn't be greater than length, try again.";
		}
		else if (n == 0)
		{
			cout << "There is nothing to delete. " << endl;
			return 0;
		}
	} while (n <= 0 || n >= length);
	return n;
}

int enterNumberOfElementsToAdd()
{
	cout << "How many elements do you want to add to the queue?: ";
	int n;
	do
	{
		cin >> n;
		if (n < 0)
		{
			cout << "It should be positive, try again: ";
		}
		if (n == 0)
		{
			cout << "There is nothing to add. " << endl;
			return 0;
		}
	} while (n <= 0);
	return n;
}




void ShowQueue(Queue* queueToShow)
{
	cout << "[";
	Node* current = queueToShow->Tail;
	while (current)
	{
		cout << current->data;
		if (current->next != NULL)
		{
			cout << ", ";
		}
		current = current->next;
	}
	cout << "]" << endl;
}


void InsertionSort(Queue* queueToSort)//двигает вправо пока справа от него элемент больше
{
	Node* current = queueToSort->Head;
	while (current)// проходится по элементам справа налево
	{
		Node* innerCurrent = current;
		while (innerCurrent->next && innerCurrent->data > innerCurrent->next->data) // каждый элемент сдвигает вправо пока надо
		{
			swap(innerCurrent->data, innerCurrent->next->data);
			innerCurrent = innerCurrent->next;
		}
		current = current->prev;
	}
}

Node* At(Queue* someQueue, int number)//получить элемент под номером, нумерация с нуля
{
	Node* result = someQueue->Tail;
	int counter = 0;
	while (counter < number)
	{
		counter++;
		result = result->next;
	}
	return result;
}

void QuickSort(Queue* queueToSort, int low, int high)//слева от опорного меньше справа больше
{
	int l = low;//границы в которыхт сортируем
	int h = high;
	Node* currentLow = At(queueToSort, l);//под номером л
	Node* currentHigh = At(queueToSort, h);
	int pivot = At(queueToSort, (low + high) / 2)->data;//опорный эл-центральный
	do// после завершения цикла на место поставится опорный 
	{
		while (currentLow->data < pivot)//двигаем л вправо пока элементы меньше чем опорный
		{
			l++;//когда находим не на своем месте останавливаемся
			currentLow = currentLow->next;
			if (l == high)
			{
				break;
			}
		}
		while (currentHigh->data > pivot)
		{
			h--;
			currentHigh = currentHigh->prev;
			if (h == low)
			{
				break;
			}
		}
		if (l <= h)
		{
			swap(currentHigh->data, currentLow->data);
			l++;
			currentLow = currentLow->next;
			h--;
			currentHigh = currentHigh->prev;
		}
	} while (l < h);
	if (low < h)//
	{
		QuickSort(queueToSort, low, h);
	}
	if (l < high)
	{
		QuickSort(queueToSort, l, high);
	}

}

Queue* copyQueue(Queue* queueToCopy)
{
	Queue* newQueue = CreateEmpty();
	Node* current = queueToCopy->Head;
	for (int i = 0; i < queueToCopy->Size; i++)
	{
		Push(newQueue, current->data);
		current = current->prev;
	}
	return newQueue;
}

void CompareEfficiency()
{
	Queue* veryLongQueue = CreateRandomQueue(10000);
	Queue* veryLongQueue2 = copyQueue(veryLongQueue);
	/*ShowQueue(veryLongQueue);
	ShowQueue(veryLongQueue2);*/
	clock_t startTime = clock();
	InsertionSort(veryLongQueue);
	//ShowQueue(veryLongQueue2);
	clock_t endTime = clock();
	double deltaTime = double(endTime - startTime) / CLOCKS_PER_SEC;
	cout << "Time of InsertionSort: " << deltaTime << endl;
	startTime = clock();
	QuickSort(veryLongQueue2, 0, veryLongQueue2->Size - 1);
	//ShowQueue(veryLongQueue);
	endTime = clock();
	deltaTime = double(endTime - startTime) / CLOCKS_PER_SEC;
	cout << "Time of QuickSort: " << deltaTime << endl;
}






void TestFunction()
{
	int length = enterLength();
	Queue* randomQueue = CreateRandomQueue(length);
	cout << "Here is your randomly generated queue: ";
	ShowQueue(randomQueue);
	cout << endl << "*********************************************************************************************" << endl << endl;


	int n = enterNumberofElementsToDelete(length);
	for (int i = 0; i < n; i++)
	{
		Remove(randomQueue);
	}
	if (n != 0)
	{
		cout << "Here is your queue now: ";
		ShowQueue(randomQueue);
	}
	cout << endl << "*********************************************************************************************" << endl << endl;

	int n2 = enterNumberOfElementsToAdd();

	if (n2 != 0)
	{
		cout << "Enter the element (s) you want to add: ";
		for (int i = 0; i < n2; i++)
		{
			int element;
			cin >> element;
			Push(randomQueue, element);
		}
		cout << "Here is you queue now: ";
		ShowQueue(randomQueue);
	}
	cout << endl << "*********************************************************************************************" << endl << endl;


	cout << "Here is the qeue after the insertion sort: ";
	InsertionSort(randomQueue);
	ShowQueue(randomQueue);
	cout << endl << "*********************************************************************************************" << endl << endl;

	cout << "Here is the queue after the quick sort: ";
	QuickSort(randomQueue, 0, randomQueue->Size - 1);
	ShowQueue(randomQueue);
	cout << endl << "*********************************************************************************************" << endl << endl;


	cout << "Comparing their efficiency: " << endl << endl;
	CompareEfficiency();
}

int main()
{
	srand(time(0));
	TestFunction();
}
