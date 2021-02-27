#include "LinkedList.h"
void LinkedList::add(int value)
{
	if (head == NULL)
	{
		head = new LinkedListNode(value);
		tail = head;
		return;
	}
	LinkedListNode* newNode = new LinkedListNode(value);
	tail->next = newNode;
	tail = tail->next;
}

void LinkedList::remove(int value)
{
	if (value == head->value)
	{
		head = head->next;
		return;
	}
	
	LinkedListNode* iterator = head;
	while (iterator->next != NULL)
	{
		if (iterator->next->value == value)
		{
			if (iterator->next == tail)
			{
				tail = iterator;
			}
			LinkedListNode* temp = iterator->next;
			iterator->next = iterator->next->next;
			delete(temp);
			break;
		}
		iterator = iterator->next;
	}
}

void LinkedList::printList()
{
	LinkedListNode* iterator = head;
	while (iterator != nullptr)
	{
		cout << iterator->value << " ";
		iterator = iterator->next;
	}
	cout << "\n";
}

bool LinkedList::isCircular()
{
	auto it = head->next;
	while(it != NULL || it != head)
	{
		it = it->next;
	}
	return it == head;
}

void LinkedList::reverse(LinkedListNode* current , LinkedListNode* prev)
{
	if (current == NULL)
		return;
	if (current->next == NULL)
	{
		head = current;
	}
	reverse(current->next, current);
	current->next = prev;
	if (prev == NULL)
		tail = current;
}

int LinkedList::getLength()
{
	int length = 0;
	auto it = head;
	while (it)
	{
		length++;
		it = it->next;
	}
	return length;
}

void LinkedList::clear()
{
	if (getLength() < 2)
	{
		head = NULL;
	}
	clearUtility(head, NULL);
	head = NULL;
	tail = NULL;
}

void LinkedList::clearUtility(LinkedListNode* current, LinkedListNode* prev)
{
	if (current == NULL)
		return;
	clearUtility(current->next, current);
	if(prev)
		prev->next = NULL;
	delete(current);
}

