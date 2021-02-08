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