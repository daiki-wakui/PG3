#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <list>

using namespace std;

typedef struct cell
{
	char str[8];
	struct cell* next;
}CELL;


void create(CELL* head, const char* val);
void index(CELL* head);

int main() {

	char str[8];
	CELL head;
	head.next = nullptr;

	while (true)
	{
		scanf_s("%s", str, 8);
		create(&head, str);
		printf("-----------------\n");
		printf("ƒŠƒXƒg‚Ì•\Ž¦\n");
		index(&head);
		printf("-----------------\n");
	}

	return 0;
}

void create(CELL* head, const char* str)
{
	CELL* newsel;
	newsel = (CELL*)malloc(sizeof(CELL));

	strcpy_s(newsel->str, 8, str);
	newsel->next = nullptr;

	while (head->next != nullptr)
	{
		head = head->next;
	}
	head->next = newsel;
}

void index(CELL * head)
{
	while (head->next != nullptr)
	{
		head = head->next;
		printf("%s\n", head->str);
	}
}