#include <stdio.h>
#include <stdlib.h>
#include <iostream>

typedef struct cell
{
	char str[8];
	struct cell* prev;
	struct cell* next;
}CELL;

//���샊�X�g�̊֐�
void Create(CELL* head, const char* val);				//�v�f�̐���
void Index(CELL* head);									//�ꗗ�\��
int Count(CELL* head,int &listSize);					//�v�f���J�E���g
void Choice(CELL* head, CELL* insert);					//�v�f���I��ŕ\��
void Edit(CELL* head,CELL* insert, const char* str);	//�v�f�̕ҏW
void Delete(CELL* head, int itr, int& listSize);	//�v�f�̍폜
void Replace(CELL* head,int itr1, int itr2, int& listSize);	//�v�f�̕��ёւ�
CELL* getInsertListAddress(CELL* head, int iterator);	//�C�ӂ̈ʒu�܂ł̃A�h���X��H��

int main() {
	int windowState = 0;
	int iterator;
	int listSize = 0;
	char str[8];
	CELL* insertCell;
	CELL head;
	head.next = nullptr;
	head.prev = nullptr;

	int userInput[3] = {};
	
	while (true)
	{
		//�����\�����
		if (windowState == 0) {
			Count(&head, listSize);

			system("cls");
			printf("[�v�f�̑���]\n");
			printf("1.�v�f�̕\��\n");
			printf("2.�v�f�̑}��\n");

			//�v�f����0�̎��͕\�����Ȃ�
			if (listSize != 0) {
				printf("3.�v�f�̕ҏW\n");
				printf("4.�v�f�̍폜\n");
				printf("5.�v�f�̕��ёւ�(�I�v�V����)\n");
			}
			
			printf("-------------------------------\n");
			printf("�����I�����ĉ�����\n");
			scanf_s("%d", &userInput[0]);
			windowState = userInput[0];	//���͂����l�ɑJ��
		}

		//�v�f�̕\��
		if (windowState == 1) {

			system("cls");
			userInput[0] = 0;
			printf("[�v�f�̕\��]\n");
			printf("1.�v�f�̈ꗗ�\��\n");
			printf("2.���Ԃ��w�肵�ėv�f��\��\n");
			printf("9.�v�f����ɖ߂�\n");
			printf("\n�����I�����ĉ�����\n");
			scanf_s("%d", &userInput[0]);

			//�v�f�̈ꗗ�\��
			if (userInput[0] == 1) {
				system("cls");
				printf("[�v�f�̈ꗗ�\��]\n");
				printf("�v�f�ꗗ : {\n");

				//�����ŕ\��
				Index(&head);

				printf("}\n");

				//�v�f���̕\��
				Count(&head, listSize);
				printf("�v�f�� : %d\n", listSize);

				printf("\n-------------------------------\n");
				printf("1.�v�f�̕\���ɖ߂�\n");
				printf("2.�v�f�̑���ɖ߂�\n");

				scanf_s("%d", &userInput[1]);
			}

			//���Ԃ��w�肵�ėv�f��\��
			if (userInput[0] == 2) {
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
			}

			//������ʂɖ߂�
			if (userInput[0] == 9 || userInput[1] == 2) {
				windowState = 0;
			}
		}

		//�v�f�̑}��
		if (windowState == 2) {

			system("cls");
			printf("[���X�g�v�f�̑}��]\n");

			//�Ō�����擾
			Count(&head, iterator);

			//�v�f�ԍ��̎w��
			printf("�ꏊ���w�肵�Ă��������B�w�肵�Ȃ��ŕ��������͂���ƍŌ���ɑ}������܂��B\n");
			scanf_s("%d", &iterator);

			//�v�f�̑}��
			printf("�ǉ�����v�f�̕��������͂��Ă��������B\n");
			scanf_s("%s", str, 8);
			insertCell = getInsertListAddress(&head, iterator);
			Create(insertCell, str);

			printf("�v�f %s �� %d �Ԗڂɒǉ�����܂����B\n", str, iterator);


			printf("\n9.�v�f����ɖ߂�\n");
			scanf_s("%d", &userInput[2]);
			
			//������ʂɖ߂�
			if (userInput[2] == 9) {
				windowState = 0;
			}
		}

		//�v�f�̕ҏW
		if (windowState == 3) {

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

			//������ʂɖ߂�
			if (userInput[0] == 9) {
				windowState = 0;
			}
		}

		//�v�f�̍폜
		if (windowState == 4) {

			system("cls");
			printf("[�v�f�̍폜]\n");

			//�폜����ꏊ�̎w��
			printf("�폜����v�f�̏ꏊ���w�肵�Ă��������B\n");
			scanf_s("%d", &iterator);

			//�w�肳�ꂽ�ꏊ�̂܂ŒH���č폜
			Delete(&head, iterator, listSize);

			printf("\n-------------------------------\n");
			printf("9.�v�f����ɖ߂�\n");
			scanf_s("%d", &userInput[0]);
			
			//������ʂɖ߂�
			if (userInput[0] == 9) {
				windowState = 0;
			}
		}

		//�v�f�̕��ёւ�
		if (windowState == 5) {

			system("cls");
			printf("�v�f�̕��ёւ�\n");

			printf("���ѕς������v�f�ԍ����w�肵�Ă��������B\n");
			printf("��� ");
			scanf_s("%d", &userInput[0]);

			printf("��� ");
			scanf_s("%d", &userInput[1]);

			//���͂��ꂽ�����ёւ���
			Replace(&head, userInput[0], userInput[1], listSize);

			printf("\n-------------------------------\n");
			printf("9.�v�f����ɖ߂�\n");
			scanf_s("%d", &userInput[2]);
			
			//������ʂɖ߂�
			if (userInput[2] == 9) {
				windowState = 0;
			}
		}
	}

	return 0;
}

//�v�f�̐���
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

//�ꗗ�\��
void Index(CELL* head)
{
	int num = 0;	//�v�f�̐�
	int isVoid = true;	//�܂������\�����ĂȂ�

	while (head->next != nullptr)
	{
		head = head->next;
		printf(" %d : %s\n", num, head->str);
		isVoid = false;
		++num;
	}

	//�v�f���Ȃ������ꍇ
	if (isVoid == true)
	{
		printf("�v�f������܂���B\n");
	}
}

//�Ō���܂ł̗v�f���𐔂���
int Count(CELL* head, int &listSize)
{
	listSize = 0;

	//�Ō���܂ł̗v�f���𐔂���
	while (head->next != nullptr)
	{
		head = head->next;
		++listSize;
	}

	return listSize;
}

//���X�g�̈ꕔ�\��
void Choice(CELL* head, CELL* insert)
{
	//�w�肳�ꂽ�ꏊ�̗v�f����
	head = insert->next;

	if (head != nullptr) {
		printf("%s \n", head->str);
	}
	else {
		printf("�w�肳�ꂽ�ԍ��ɗv�f�͂���܂���B\n");
	}
}

//�v�f�̕ҏW
void Edit(CELL* head, CELL* insert, const char* str)
{
	//�w�肳�ꂽ�ꏊ�̗v�f����
	head = insert->next;

	if (head != nullptr){

		//�w�肳�ꂽ�ꏊ�ɕύX��̕�������R�s�[
		strcpy_s(head->str, 8, str);

		printf("%s �ɕύX����܂����B\n", head->str);
	}
	else {
		printf("�w�肳�ꂽ�ԍ��ɗv�f�͂���܂���B\n");
	}
}

//�v�f�̍폜
void Delete(CELL* head, int itr, int& listSize){

	//�v�f���̃J�E���g
	Count(head, listSize);

	CELL* deleteCell = head;

	//�擪�̗v�f��������
	if (itr == 0) {
		CELL* newheadCell;
		//�擪�̌q���ς�
		newheadCell = deleteCell->next->next;
		deleteCell->next = newheadCell;	
		printf("�v�f�ԍ� %d�� �̍폜���������܂����B\n",itr);
	}
	//�擪�ȊO�̏ꍇ
	else {

		//�w�肵���v�f�ԍ������X�g�ɂ��邩�m�F
		if (itr < listSize) {

			//�w�肵�������܂ŒH��
			for (int i = 0; i <= itr; i++) {
				deleteCell = deleteCell->next;
			}

			//�Ō�����폜����ꍇ
			if (deleteCell->next == nullptr) {
				deleteCell->prev->next = nullptr;
				deleteCell->prev = nullptr;
			}
			//�r���̊Ԃɂ���v�f���폜����ꍇ
			else {
				deleteCell->prev->next = deleteCell->next;
				deleteCell->next->prev = deleteCell->prev;
				deleteCell->next = nullptr;
				deleteCell->prev = nullptr;
			}
			printf("�v�f�ԍ� %d�� �̍폜���������܂����B\n",itr);
		}
		//�Ȃ������ꍇ
		else {
			printf("�w�肳�ꂽ�ꏊ�ɗv�f�͂���܂���\n");
		}
	}
}

//�v�f�̕��ёւ�
void Replace(CELL* head,int itr1, int itr2, int& listSize){

	//�v�f���̃J�E���g
	Count(head, listSize);

	//1�ڂɎw�肵���Z��
	CELL* changeSetCellOne;
	char setCellDataOne[8];

	//2�ڂɎw�肵���Z��
	CELL* changeSetCellTwo;
	char setCellDataTwo[8];

	//�w�肵���v�f�ԍ������X�g�ɂ��邩�m�F
	if (itr1 < listSize && itr2 < listSize) {

		//���ꂼ��̔ԍ��܂ŒH��
		changeSetCellOne = getInsertListAddress(head, itr1);
		changeSetCellTwo = getInsertListAddress(head, itr2);

		//���ёւ���f�[�^���R�s�[
		strcpy_s(setCellDataOne, 8, changeSetCellOne->next->str);
		strcpy_s(setCellDataTwo, 8, changeSetCellTwo->next->str);

		//1�ڂ̃f�[�^��2�ڂ̏ꏊ�ɃR�s�[
		head = changeSetCellOne->next;
		strcpy_s(head->str, 8, setCellDataTwo);

		//2�ڂ̃f�[�^��1�ڂ̏ꏊ�ɃR�s�[
		head = changeSetCellTwo->next;
		strcpy_s(head->str, 8, setCellDataOne);

		printf("%d�� %s �� %d�� %s ����ёւ��܂���\n", itr1, setCellDataOne, itr2, setCellDataTwo);
	}
	//�Ȃ������ꍇ
	else {
		printf("�w�肵���v�f�ԍ��ɗv�f�������ĂȂ����̂��܂܂�Ă��܂��B\n");
	}
}

//�w�肳�ꂽ�v�f�ԍ���H��
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