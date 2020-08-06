#include "StackType.h"

StackType::StackType()
{
	top = -1;
}

bool StackType::IsEmpty() const
{
	return(top == -1);
}

bool StackType::IsFull() const
{
	return (top == MAX_ITEMS - 1);
}

void StackType::Push(char newItem)
{
	if (IsFull())
		throw FullStack();
	top++;
	items[top] = newItem;
}

void StackType::Pop()
{
	if (IsEmpty())
		throw EmptyStack();
	top--;
}

char StackType::Top()
{
	if (IsEmpty())
		throw EmptyStack();
	return items[top];
}


