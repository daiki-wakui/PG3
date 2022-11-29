#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <list>

using namespace std;

typedef struct cell
{
	char str[8];
	struct cell* prev;
	struct cell* next;
}CELL;

void create(CELL* head, const char* val);
void index(CELL* head);
CELL* getInsertListAddress(CELL* head, int iterator);

int main() {
	int iterator;
	char str[8];
	CELL* insertCell;
	
	CELL head;
	head.next = nullptr;
	head.prev = nullptr;

	while (true)
	{
		printf("‰½”Ô–Ú‚ÌƒZƒ‹‚ÌŒã‚ë‚É‘}“ü‚µ‚Ü‚·‚©\n");
		scanf_s("%d", &iterator);

		printf("‘}“ü‚·‚é•¶Žš—ñ‚Í\n");
		scanf_s("%s", str, 8);

		insertCell = getInsertListAddress(&head, iterator);
		create(insertCell, str);
		printf("-----------------\n");
		printf("ƒŠƒXƒg‚Ì•\Ž¦\n");
		index(&head);
		printf("-----------------\n");
	}

	return 0;
}

void create(CELL* currentCell, const char* str)
{
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));

	strcpy_s(newCell->str, 8, str);

	newCell->prev = currentCell;
	newCell->next = currentCell->next;

	if(currentCell->next)
	{
		CELL* nextCell = currentCell->next;
		nextCell->prev = newCell;
	}
	currentCell->next = newCell;
}

void index(CELL * head)
{
	while (head->next != nullptr)
	{
		head = head->next;
		printf("%s\n", head->str);
	}
}

CELL* getInsertListAddress(CELL* head, int iterator)
{
	for (int i = 0; i < iterator; i++)
	{
		if (head->next)
		{
			head = head->next;
		}
		else
		{
			break;
		}
	}
	return head;
}
