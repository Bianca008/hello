#pragma once
#include <iostream>
#include <string>

struct MyStringStack
{
	MyStringStack();
	MyStringStack(int dim);
	int dimensiune;
	int varf = -1;
	char date[100];
	bool isEmpty(MyStringStack stack);
	bool isFull(MyStringStack stack);
	void push(MyStringStack &stack, char x);
	void pop(MyStringStack &stack);
	char top(MyStringStack stack);
	void clear(MyStringStack &stack);
	void printStack(MyStringStack stack);
};
