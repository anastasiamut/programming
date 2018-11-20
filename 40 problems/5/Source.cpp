/*Создать односвязный линейный список (у каждого узла 1 информ. поле типа
Integer), с возможностью добавлять и удалять узлы.
После завершения редактирования списка запросить число N и разбить список на
два других, не меняя расположения элементов в памяти, следующим образом:
если значение информ. поля узла > N, включить его в 1 список, иначе включить
его во 2 список.
После завершения работы все списки разрушить.*/

#include "pch.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Node
{
	double data;
	Node* next;
};

struct List
{
	Node* Begin;
	Node* End;
	int length;
};


Node* CreateNode(double data)
{
	Node* result = new Node;
	result->data = data;
	result->next = NULL;
	return result;
}

List* CreateEmptyList()
{
	List* result = new List;
	result->Begin = NULL;
	result->End = NULL;
	result->length = 0;
	return result;
}

void AddNode(List* list, Node* nodeToAdd)
{
	if (list->Begin == NULL)
	{
		list->Begin = nodeToAdd;
		list->End = nodeToAdd;
	}
	else
	{
		list->End->next = nodeToAdd;
		list->End = nodeToAdd;
	}
	nodeToAdd->next = NULL;
	list->length++;
}

double enterNumber()
{
	double number;
	cout << "Enter the number you want to insert: ";
	cin >> number;
	return number;
}

int enterNumber1(int length)
{

	int n;
	cout << "Enter number of position where you want to insert your element to: ";
	do
	{
		cin >> n;
		if (n <= 0|| n>length)
		{
			cout << "It should be positive and not grater than the list's length, try again: " << endl;
		}

	} while (n <= 0||n>length);
	return n;
}

int enterNumber2(int length)
{
	int n;
	cout << "Enter number of position from which you want to remove an element: ";
	do
	{
		cin >> n;
		if (n <= 0||n>length)
		{
			cout << "It should be positive and not grater than the list's length, try again: " << endl;
		}

	} while (n <= 0||n>length);
	return n;
}

void insertNode(List* list, Node* nodeToAdd)
{
	double n = enterNumber1(list->length);
	if ((list->length == 0)&&(n==1))
	{
		list->Begin = nodeToAdd;
		list->End = nodeToAdd;
	}
	else if((n==1)&&(list->length > 0))
	{
		nodeToAdd->next = list->Begin;
		list->Begin = nodeToAdd;
	}
	else if (n == list->length + 1)
	{
		list->End->next = nodeToAdd;
		list->End = nodeToAdd;
	}
	else
	{
		Node* current = list->Begin;
		for (int i = 0; i < n-2; i++)
		{
			current = current->next;
		}
		nodeToAdd->next = current->next;
		current->next = nodeToAdd;
	}
	list->length++;
}

void AddData(List* list, double data)
{
	Node* nodeToAdd = CreateNode(data);
	AddNode(list, nodeToAdd);
}

void ShowList(List* list)
{
	cout << "[";
	Node* current = list->Begin;
	while (current != NULL)
	{
		cout << current->data;
		if (current->next)
		{
			cout << ", ";
		}
		current = current->next;
	}
	cout << "]" << endl;
}

int enterLength()
{
	int l;
	cout << "Enter the length of the list: ";
	do
	{
		cin >> l;
		cout << endl;
		if (l <= 0)
		{
			cout << "It should be positive, try again: ";
		}
		
	} while (l <= 0);
	return l;
}

List* CreateRandomList()
{
	List* result = CreateEmptyList();
	int l = enterLength();
	for (int i = 0; i < l; i++)
	{
		double data = (double(rand()) / RAND_MAX)*200-100;
		AddData(result, data);
	}
	return result;
}


void deleteViaNumber(List* list)
{
	int numberToDelete = enterNumber2(list->length);
	Node* nodeToDelete;
	if (list->length <= 0)
	{
		return;
	}
	if ((list->length == 1)&&(numberToDelete==1))
	{
		nodeToDelete = list->Begin;
		list->Begin = NULL;
		list->End = nullptr;
	}
	else if ((list->length > 1) && (numberToDelete == 1))
	{
		nodeToDelete = list->Begin;
		list->Begin = list->Begin->next;
	}
	else
	{
		Node* current = list->Begin;
		for (int i = 0; i < numberToDelete - 2; i++)
		{
			current = current->next;
		}
		nodeToDelete = current->next;

		if (numberToDelete == list->length)
		{
			list->End = current;
			list->End->next = NULL;
		}
		else
		{
			current->next = nodeToDelete->next;
		}
	}
	

	list->length--;
	delete nodeToDelete;
}

void DeleteNode(List* list, Node* toDelete)
{
	Node* current = list->Begin;
	if (list->Begin == toDelete)
	{
		list->Begin = list->Begin->next;
	}
	while (current->next != toDelete)
	{
		current = current->next;
	}

	if (toDelete->next)
	{
		current->next = toDelete->next;
	}
	else
	{
		list->End = current;
		current->next = NULL;
	}
	list->length--;
	delete toDelete;

}

void DeleteList(List* listToDelete)
{
	if (listToDelete->length==0)
	{
		return;
	}

	Node* current = listToDelete->Begin->next;
	Node* previous = listToDelete->Begin;
	while (current)
	{
		delete previous;
		previous = current;
		current = current->next;
	}
	delete listToDelete;
}

void DivideListInto2Sublists(List* someList)
{
	int divider;
	cout << "Enter N: ";
	cin >> divider;
	Node* current = someList->Begin;
	List* sublist1 = CreateEmptyList();
	List* sublist2 = CreateEmptyList();
	while (current)
	{
		Node* next = current->next;
		if (current->data < divider)
		{
			AddNode(sublist1, current);
		}
		else
		{
			AddNode(sublist2, current);
		}
		current = next;
		someList->length--;
	}
	cout << "First sublist:";
	ShowList(sublist1);

	cout << "Second sublist:";
	ShowList(sublist2);

	DeleteList(sublist1);
	DeleteList(sublist2);
}

void SolveTask()
{

	List* randomList = CreateRandomList();
	cout << "Randomly generated list is: " << endl;
	ShowList(randomList);
	cout <<endl<< "**************************************************" << endl<<endl;


	cout << "Inserting: " << endl<<endl;
	int n = enterNumber();
	insertNode(randomList, CreateNode(n));
	cout << "Here is your list now: ";
	ShowList(randomList);
	cout << endl << "**************************************************" << endl << endl;


	cout << "Removing: " << endl << endl;
	deleteViaNumber(randomList);
	cout << "Here is your list now: ";
	ShowList(randomList);
	cout << endl << "**************************************************" << endl << endl;

	//cout << "Adding number 100 to the end of the list: " << endl;
	//AddData(randomList, 100);
	//ShowList(randomList);

	/*cout << "Removing last element: " << endl;
	DeleteNode(randomList, randomList->End);
	ShowList(randomList);*/

	cout << "Dividing list into 2 sublists: " << endl;
	DivideListInto2Sublists(randomList);
	DeleteList(randomList);
}

int main()
{
	srand(time(0));
	SolveTask();
}
