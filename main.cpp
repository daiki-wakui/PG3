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

void Create(CELL* head, const char* val);
void Index(CELL* head);
void Count(CELL* head);
void Choice(CELL* head, CELL* insert);
void Edit(CELL* head,CELL* insert, const char* str);
void Delete(CELL* head, CELL* insert,int itr);
CELL* getInsertListAddress(CELL* head, int iterator);

int main() {
	int iterator;
	char str[8];
	CELL* insertCell;

	CELL head;
	head.next = nullptr;
	head.prev = nullptr;

	int state = 0;

	int isDraw[3] = {};
	int userInput[3] = {};
	//char str[16] = {};

	while (true)
	{
		
		if (state == 0) {
			system("cls");
			printf("[�v�f�̑���]\n");
			printf("1.�v�f�̕\��\n");
			printf("2.�v�f�̑}��\n");
			printf("3.�v�f�̕ҏW\n");
			printf("4.�v�f�̍폜\n");
			printf("5.�v�f�̕��ёւ�(�I�v�V����)\n");
			printf("-------------------------------\n");
			printf("�����I�����ĉ�����\n");
			scanf_s("%d", &userInput[0]);
			state = userInput[0];
		}


		if (state == 1) {
			//�v�f�̕\��
			if (isDraw[0] == 0) {
				system("cls");
				userInput[0] = 0;
				printf("[�v�f�̕\��]\n");
				printf("1.�v�f�̈ꗗ�\��\n");
				printf("2.���Ԃ��w�肵�ėv�f��\��\n");
				printf("9.�v�f����ɖ߂�\n");
				printf("\n�����I�����ĉ�����\n");
				scanf_s("%d", &userInput[0]);
				isDraw[0] = 1;
			}

			//�v�f�̈ꗗ�\��
			if (userInput[0] == 1 && isDraw[1] == 0) {
				system("cls");
				printf("[�v�f�̈ꗗ�\��]\n");
				printf("�v�f�ꗗ : {\n");

				//�����ŕ\��
				Index(&head);

				printf("}\n");

				Count(&head);

				printf("\n-------------------------------\n");
				printf("1.�v�f�̕\���ɖ߂�\n");
				printf("2.�v�f�̑���ɖ߂�\n");

				scanf_s("%d", &userInput[1]);

				isDraw[1] = 1;
			}

			//���Ԃ��w�肵�ėv�f��\��
			if (userInput[0] == 2&& isDraw[2] == 0) {
				system("cls");
				printf("[���Ԃ��w�肵�ėv�f��\��]\n");

				printf("�\���������v�f�̏��Ԃ��w�肵�Ă��������B\n");

				//�����ɓ��͂��ꂽ�v�f�̏o��
				scanf_s("%d", &iterator);
				printf("�v�f�ԍ� %d : ", iterator);
				insertCell = getInsertListAddress(&head, iterator);
				Choice(&head, insertCell);


				printf("\n-------------------------------\n");
				printf("1.�v�f�̕\���ɖ߂�\n");
				printf("2.�v�f�̑���ɖ߂�\n");

				scanf_s("%d", &userInput[1]);

				isDraw[2] = 1;
			}

			if (userInput[1] == 1) {
				isDraw[0] = 0;
				isDraw[1] = 0;
				isDraw[2] = 0;
			}

			//�v�f����ɖ߂�
			if (userInput[0] == 9 || userInput[1] == 2) {
				isDraw[0] = 0;
				isDraw[1] = 0;
				isDraw[2] = 0;
				state = 0;
			}
		}

		//�v�f�̑}��
		if (state == 2) {

			if (isDraw[0] == 0) {
				system("cls");
				printf("[���X�g�v�f�̑}��]\n");

				/*while (head.next != nullptr) {
					head.prev->next = head.next;
					++iterator;
				}*/

				printf("�v�f��ǉ�����ꏊ���w�肵�Ă��������B\n");
				scanf_s("%d", &iterator);
				

				printf("�ǉ�����v�f�̒l����͂��Ă��������B\n");
				scanf_s("%s", str, 8);
				insertCell = getInsertListAddress(&head, iterator);
				Create(insertCell, str);

				printf("�v�f %s �� %d �Ԗڂɒǉ�����܂����B\n", str, iterator);


				printf("\n9.�v�f����ɖ߂�\n");
				scanf_s("%d", &userInput[2]);
				isDraw[0] = 1;
			}
			
			if (userInput[2] == 9) {
				isDraw[0] = 0;
				state = 0;
			}
		}

		//�v�f�̕ҏW
		if (state == 3) {

			if (isDraw[0] == 0) {

				system("cls");
				printf("[�v�f�̕ҏW]\n");
				printf("�ҏW����v�f�̏ꏊ���w�肵�Ă��������B\n");
				scanf_s("%d", &iterator);
				insertCell = getInsertListAddress(&head, iterator);

				printf("�ҏW��̒l����͂��Ă��������B\n");
				scanf_s("%s", str, 8);

				Edit(&head, insertCell, str);

				printf("\n-------------------------------\n");
				printf("9.�v�f����ɖ߂�\n");
				scanf_s("%d", &userInput[0]);

				isDraw[0] = 1;
			}

			if (userInput[0] == 9) {
				isDraw[0] = 0;
				state = 0;
			}
		}

		//�v�f�̍폜
		if (state == 4) {

			if (isDraw[0] == 0) {
				system("cls");
				printf("[�v�f�̍폜]\n");


				printf("�폜����v�f�̏ꏊ���w�肵�Ă��������B\n");
				scanf_s("%d", &iterator);
				insertCell = getInsertListAddress(&head, iterator);

				Delete(&head, insertCell, iterator);

				printf("\n-------------------------------\n");
				printf("9.�v�f����ɖ߂�\n");
				scanf_s("%d", &userInput[0]);

				isDraw[0] = 1;
			}
			
			if (userInput[0] == 9) {
				isDraw[0] = 0;
				state = 0;
			}
		}

		if (state == 5) {
			printf("�v�f�̕��ёւ�\n");
		}
	}

	return 0;
}

void Create(CELL* currentCell, const char* str)
{
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));

	strcpy_s(newCell->str, 8, str);

	newCell->prev = currentCell;
	newCell->next = currentCell->next;

	if (currentCell->next)
	{
		CELL* nextCell = currentCell->next;
		nextCell->prev = newCell;
	}
	currentCell->next = newCell;
}

void Index(CELL* head)
{
	int num = 0;
	int isVoid = true;
	while (head->next != nullptr)
	{
		head = head->next;
		printf(" %d : %s\n", num, head->str);
		isVoid = false;
		++num;
	}

	if (isVoid == true)
	{
		printf("�v�f������܂���B\n");
	}
}

void Count(CELL* head)
{
	int num = 0;

	while (head->next != nullptr)
	{
		head = head->next;
		++num;
	}

	printf("�v�f�� : %d\n", num);
}

void Choice(CELL* head, CELL* insert)
{
	head = insert->next;

	if (head != nullptr) {
		printf("%s \n", head->str);
	}
	else {
		printf("�w�肳�ꂽ�ԍ��ɗv�f�͂���܂���B\n");
	}
}

void Edit(CELL* head, CELL* insert, const char* str)
{
	head = insert->next;

	if (head != nullptr){
		strcpy_s(head->str, 8, str);

		printf("%s �ɕύX����܂����B\n", head->str);
	}
	else {
		printf("�w�肳�ꂽ�ԍ��ɗv�f�͂���܂���B\n");
	}

	
}

void Delete(CELL* head, CELL* insert, int itr)
{
	//head = insert->next;
	////insert->next = nullptr;

	//while (head->next != nullptr) {
	//	strcpy_s(head->str, 8, head->next->str);
	//	head = head->next;
	//}

	CELL* p = head;

	if (itr == 0) {
		head = p->next;
		p->next->prev = nullptr;
		p->next = nullptr;
	}
	else {
		for (int i = 0; i <= itr; i++) {
			p = p->next;
		}

		if (p->next == nullptr) {
			/*insert = p->prev;
			p->prev->next = nullptr;
			p->prev = nullptr;*/
		}
		else {
			p->prev->next = p->next;
			p->next->prev = p->prev;
			p->next = nullptr;
			p->prev = nullptr;
		}
	}


	printf("�폜���܂����B\n");
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