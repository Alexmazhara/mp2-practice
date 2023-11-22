#pragma once
#include <iostream>

using namespace std;
template<class A1>
class Stack
{
public:
	//Конструктор по умолчанию
	Stack()
	{
		Array = 0;
		size = 0;
		first = 0;
		last = -1;
		DataCount = 0;
		
	}
	//Конструктор с параметром
	Stack(int _size)
	{
		if (_size < 0)throw logic_error("negative size");
		Array = new const A1*[_size];
		size = _size;
		first = 0;
		last = -1;
		DataCount = 0;
		
	}
	//Конструктор копирования
	Stack(Stack& lhs)
	{
		Array = new const A1*[lhs.size];
		size = lhs.size;
		first = lhs.first;
		last = lhs.last;
		DataCount = lhs.DataCount;
		
	}
	//Деструктор
	virtual ~Stack()
	{
		delete[] Array;
	}
	//Пуст ли стек
	bool IsEmpty()
	{
		return(DataCount==0);
	}
	//Полон ли стек
	bool IsFull()
	{
		return(DataCount==size);
	}
	//Возврат указателя на массив
	const A1** GetMemory()
	{
		return Array;
	}
	//Добавляет элемент в стек
	 void push (const A1& lhs)
	{
		if ((*this).IsFull()) 
			throw logic_error("Container is overflow");
		if (Array == 0) 
			throw logic_error("memory error");
		last++;
		Array[last] = &lhs;
		DataCount++;
	}
	 //Поиск элемента в стеке
	 bool find(const A1& lhs)
	 {
		 if ((*this).IsEmpty())
			 throw logic_error("Container is empty");
		 if (Array == 0) 
			 throw logic_error("memory error");
		 for (int i = first; i < DataCount; i++)
		 {
			 if (lhs == (*Array[i]))return 1;
		 }
		 return 0;
	 }
	 //Находит минимальный элемент в стеке
	 const A1& min()
	 {
		 if ((*this).IsEmpty()) 
			 throw logic_error("Container is empty");
		 if (Array == 0) 
			 throw logic_error("memory error");
		const A1* tmp = Array[first];
		 for (int i = first+1; i < DataCount; i++)
		 {
			 if ((*tmp) > (*Array[i])) tmp=Array[i];
		 }
		 return (*tmp);
	 }
	 //Удаляет и возвращает верхний элемент стека
	virtual const A1& pop()
	{
		if (this->IsEmpty()) 
			throw logic_error("Stack is empty");
		if (Array == 0) 
			throw logic_error("memory error");
		const A1* tmp = Array[last];
		Array[last] = 0;
		last--;
		DataCount--;
		return (*tmp);
	}
	//Возвращает размер стека
	int GetSize()
	{
		return size;
	}
	//Возвращает индекс первого элемента в стеке
	int GetFirst()
	{
		return first;
	}
protected:

const A1** Array;
int size;
int first;
int last;
int DataCount;
};