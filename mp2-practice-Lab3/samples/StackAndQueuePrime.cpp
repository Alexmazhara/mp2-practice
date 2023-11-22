#include <iomanip>
#include "Stack.h"
#include "Queue.h"
#include <stack>

#ifndef USE_QUEUE
#define USE_QUEUE

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "simulat stack" << "\n";
	
	int size;
	cin >> size;
	int* ptr = new int[size];
	for (int i = 0; i < size; i++)
	{
		ptr[i] = (i + rand() % 100)*rand() % 12;
	}
	Stack<int>stack1(size);
	stack<int>stack2;

	for (int i = 0; i < size; i++)
	{
		cout << ptr[i] << " ";
		stack2.push(ptr[i]);
		stack1.push(ptr[i]);
	}
	
	cout << "\n";
	for (int i = stack1.GetFirst(); i < stack1.GetSize(); i++)
	{
		cout << stack1.pop() << " ";
	}
	cout << "\n";
	for (int i = 0; i < size; i++)
	{
		cout << stack2.top()<<" ";
		stack2.pop();
	}
	
}

#endif