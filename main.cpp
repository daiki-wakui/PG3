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
int Count(CELL* head,int &listSize);
void Choice(CELL* head, CELL* insert);
void Edit(CELL* head,CELL* insert, const char* str);
void Delete(CELL* head, CELL* insert, int itr, int& listSize);
void Replace(CELL* head,int itr1, int itr2, int& listSize);
CELL* getInsertListAddress(CELL* head, int iterator);

int main() {
	int iterator;
	char str[8];
	CELL* insertCell;
	int listSize = 0;

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
			Count(&head, listSize);

			system("cls");
			printf("[要素の操作]\n");
			printf("1.要素の表示\n");
			printf("2.要素の挿入\n");

			if (listSize != 0) {
				printf("3.要素の編集\n");
				printf("4.要素の削除\n");
			}
		
			printf("5.要素の並び替え(オプション)\n");
			printf("-------------------------------\n");
			printf("操作を選択して下さい\n");
			scanf_s("%d", &userInput[0]);
			state = userInput[0];
		}


		if (state == 1) {
			//要素の表示
			if (isDraw[0] == 0) {
				system("cls");
				userInput[0] = 0;
				printf("[要素の表示]\n");
				printf("1.要素の一覧表示\n");
				printf("2.順番を指定して要素を表示\n");
				printf("9.要素操作に戻る\n");
				printf("\n操作を選択して下さい\n");
				scanf_s("%d", &userInput[0]);
				isDraw[0] = 1;
			}

			//要素の一覧表示
			if (userInput[0] == 1 && isDraw[1] == 0) {
				system("cls");
				printf("[要素の一覧表示]\n");
				printf("要素一覧 : {\n");

				//ここで表示
				Index(&head);

				printf("}\n");

				Count(&head, listSize);
				printf("要素数 : %d\n", listSize);

				printf("\n-------------------------------\n");
				printf("1.要素の表示に戻る\n");
				printf("2.要素の操作に戻る\n");

				scanf_s("%d", &userInput[1]);

				isDraw[1] = 1;
			}

			//順番を指定して要素を表示
			if (userInput[0] == 2&& isDraw[2] == 0) {
				system("cls");
				printf("[順番を指定して要素を表示]\n");

				printf("表示したい要素の順番を指定してください。\n");

				//ここに入力された要素の出力
				scanf_s("%d", &iterator);
				printf("要素番号 %d : ", iterator);
				insertCell = getInsertListAddress(&head, iterator);
				Choice(&head, insertCell);


				printf("\n-------------------------------\n");
				printf("1.要素の表示に戻る\n");
				printf("2.要素の操作に戻る\n");

				scanf_s("%d", &userInput[1]);

				isDraw[2] = 1;
			}

			if (userInput[1] == 1) {
				isDraw[0] = 0;
				isDraw[1] = 0;
				isDraw[2] = 0;
			}

			//要素操作に戻る
			if (userInput[0] == 9 || userInput[1] == 2) {
				isDraw[0] = 0;
				isDraw[1] = 0;
				isDraw[2] = 0;
				state = 0;
			}
		}

		//要素の挿入
		if (state == 2) {

			if (isDraw[0] == 0) {
				system("cls");
				printf("[リスト要素の挿入]\n");

				Count(&head, iterator);
				
				printf("場所を指定してください。指定しないで文字列を入力すると最後尾に挿入されます。\n");
				scanf_s("%d", &iterator);
				
				printf("追加する要素の文字列を入力してください。\n");
				scanf_s("%s", str, 8);
				insertCell = getInsertListAddress(&head, iterator);
				Create(insertCell, str);

				printf("要素 %s が %d 番目に追加されました。\n", str, iterator);


				printf("\n9.要素操作に戻る\n");
				scanf_s("%d", &userInput[2]);
				isDraw[0] = 1;
			}
			
			if (userInput[2] == 9) {
				isDraw[0] = 0;
				state = 0;
			}
		}

		//要素の編集
		if (state == 3) {

			if (isDraw[0] == 0) {

				system("cls");
				printf("[要素の編集]\n");
				printf("編集する要素の場所を指定してください。\n");
				scanf_s("%d", &iterator);
				insertCell = getInsertListAddress(&head, iterator);

				printf("編集後の値を入力してください。\n");
				scanf_s("%s", str, 8);

				Edit(&head, insertCell, str);

				printf("\n-------------------------------\n");
				printf("9.要素操作に戻る\n");
				scanf_s("%d", &userInput[0]);

				isDraw[0] = 1;
			}

			if (userInput[0] == 9) {
				isDraw[0] = 0;
				state = 0;
			}
		}

		//要素の削除
		if (state == 4) {

			if (isDraw[0] == 0) {
				system("cls");
				printf("[要素の削除]\n");
				

				printf("削除する要素の場所を指定してください。\n");
				scanf_s("%d", &iterator);
				insertCell = getInsertListAddress(&head, iterator);

				Delete(&head, insertCell, iterator, listSize);

				printf("\n-------------------------------\n");
				printf("9.要素操作に戻る\n");
				scanf_s("%d", &userInput[0]);

				isDraw[0] = 1;
			}
			
			if (userInput[0] == 9) {
				isDraw[0] = 0;
				state = 0;
			}
		}

		if (state == 5) {
			if (isDraw[0] == 0){
				system("cls");
				printf("要素の並び替え\n");

				printf("並び変えたい要素番号を指定してください。\n");
				printf("一つ目 ");
				scanf_s("%d", &userInput[0]);

				printf("二つ目 ");
				scanf_s("%d", &userInput[1]);

				Replace(&head, userInput[0], userInput[1], listSize);

				printf("\n-------------------------------\n");
				printf("9.要素操作に戻る\n");
				scanf_s("%d", &userInput[2]);

				isDraw[0] = 1;
			}
			
			if (userInput[2] == 9) {
				isDraw[0] = 0;
				state = 0;
			}
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
		printf("要素がありません。\n");
	}
}

int Count(CELL* head, int &listSize)
{
	listSize = 0;

	while (head->next != nullptr)
	{
		head = head->next;
		++listSize;
	}

	return listSize;
}

void Choice(CELL* head, CELL* insert)
{
	head = insert->next;

	if (head != nullptr) {
		printf("%s \n", head->str);
	}
	else {
		printf("指定された番号に要素はありません。\n");
	}
}

void Edit(CELL* head, CELL* insert, const char* str)
{
	head = insert->next;

	if (head != nullptr){
		strcpy_s(head->str, 8, str);

		printf("%s に変更されました。\n", head->str);
	}
	else {
		printf("指定された番号に要素はありません。\n");
	}

	
}

void Delete(CELL* head, CELL* insert, int itr, int& listSize)
{	
	//要素数のカウント
	Count(head, listSize);

	CELL* p = head;

	if (itr == 0) {
		CELL* q;
		q = p->next->next;
		p->next = q;
		printf("要素番号 %d番 の削除が完了しました。\n",itr);
	}
	else {

		if (itr < listSize) {
			for (int i = 0; i <= itr; i++) {
				p = p->next;
			}

			if (p->next == nullptr) {
				p->prev->next = nullptr;
				p->prev = nullptr;
			}
			else {
				p->prev->next = p->next;
				p->next->prev = p->prev;
				p->next = nullptr;
				p->prev = nullptr;
			}
			printf("要素番号 %d番 の削除が完了しました。\n",itr);
		}
		else {
			printf("指定された場所に要素はありません\n");
		}
	}
}

void Replace(CELL* head,int itr1, int itr2, int& listSize)
{
	//要素数のカウント
	Count(head, listSize);

	CELL* changeCELL1;
	CELL* changeCELL2;

	char a[8];
	char b[8];

	if (itr1 < listSize && itr2 < listSize) {
		changeCELL1 = getInsertListAddress(head, itr1);
		changeCELL2 = getInsertListAddress(head, itr2);

		strcpy_s(a, 8, changeCELL1->next->str);
		strcpy_s(b, 8, changeCELL2->next->str);

		head = changeCELL1->next;
		strcpy_s(head->str, 8, b);

		head = changeCELL2->next;
		strcpy_s(head->str, 8, a);

		printf("%d番 %s と %d番 %s を並び替えました\n", itr1, a, itr2, b);
	}
	else {
		printf("指定した要素番号に要素が入ってないものが含まれています。\n");
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