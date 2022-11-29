#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <list>

using namespace std;

typedef struct cell
{
	int vel;
	struct cell* next;
}CELL;


void create(CELL* head, int val);
void index(CELL* head);

int main() {

	int val;
	CELL head;
	head.next = nullptr;

	while (true)
	{
		scanf_s("%d", &val);
		create(&head, val);
		printf("-----------------\n");
		printf("ƒŠƒXƒg‚Ì•\Ž¦\n");
		index(&head);
		printf("-----------------\n");
	}

	return 0;
}

void create(CELL* head, int val)
{
	CELL* newsel;
	newsel = (CELL*)malloc(sizeof(CELL));

	newsel->vel = val;
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
		printf("%d\n", head->vel);
	}
}