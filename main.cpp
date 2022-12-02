#include <stdio.h>
#include <stdlib.h>
#include <iostream>

typedef struct cell
{
	char str[8];
	struct cell* prev;
	struct cell* next;
}CELL;

//自作リストの関数
void Create(CELL* head, const char* val);				//要素の生成
void Index(CELL* head);									//一覧表示
int Count(CELL* head,int &listSize);					//要素数カウント
void Choice(CELL* head, CELL* insert);					//要素一つを選んで表示
void Edit(CELL* head,CELL* insert, const char* str);	//要素の編集
void Delete(CELL* head, int itr, int& listSize);	//要素の削除
void Replace(CELL* head,int itr1, int itr2, int& listSize);	//要素の並び替え
CELL* getInsertListAddress(CELL* head, int iterator);	//任意の位置までのアドレスを辿る

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
		//初期表示画面
		if (windowState == 0) {
			Count(&head, listSize);

			system("cls");
			printf("[要素の操作]\n");
			printf("1.要素の表示\n");
			printf("2.要素の挿入\n");

			//要素数が0の時は表示しない
			if (listSize != 0) {
				printf("3.要素の編集\n");
				printf("4.要素の削除\n");
				printf("5.要素の並び替え(オプション)\n");
			}
			
			printf("-------------------------------\n");
			printf("操作を選択して下さい\n");
			scanf_s("%d", &userInput[0]);
			windowState = userInput[0];	//入力した値に遷移
		}

		//要素の表示
		if (windowState == 1) {

			system("cls");
			userInput[0] = 0;
			printf("[要素の表示]\n");
			printf("1.要素の一覧表示\n");
			printf("2.順番を指定して要素を表示\n");
			printf("9.要素操作に戻る\n");
			printf("\n操作を選択して下さい\n");
			scanf_s("%d", &userInput[0]);

			//要素の一覧表示
			if (userInput[0] == 1) {
				system("cls");
				printf("[要素の一覧表示]\n");
				printf("要素一覧 : {\n");

				//ここで表示
				Index(&head);

				printf("}\n");

				//要素数の表示
				Count(&head, listSize);
				printf("要素数 : %d\n", listSize);

				printf("\n-------------------------------\n");
				printf("1.要素の表示に戻る\n");
				printf("2.要素の操作に戻る\n");

				scanf_s("%d", &userInput[1]);
			}

			//順番を指定して要素を表示
			if (userInput[0] == 2) {
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
			}

			//初期画面に戻る
			if (userInput[0] == 9 || userInput[1] == 2) {
				windowState = 0;
			}
		}

		//要素の挿入
		if (windowState == 2) {

			system("cls");
			printf("[リスト要素の挿入]\n");

			//最後尾を取得
			Count(&head, iterator);

			//要素番号の指定
			printf("場所を指定してください。指定しないで文字列を入力すると最後尾に挿入されます。\n");
			scanf_s("%d", &iterator);

			//要素の挿入
			printf("追加する要素の文字列を入力してください。\n");
			scanf_s("%s", str, 8);
			insertCell = getInsertListAddress(&head, iterator);
			Create(insertCell, str);

			printf("要素 %s が %d 番目に追加されました。\n", str, iterator);


			printf("\n9.要素操作に戻る\n");
			scanf_s("%d", &userInput[2]);
			
			//初期画面に戻る
			if (userInput[2] == 9) {
				windowState = 0;
			}
		}

		//要素の編集
		if (windowState == 3) {

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

			//初期画面に戻る
			if (userInput[0] == 9) {
				windowState = 0;
			}
		}

		//要素の削除
		if (windowState == 4) {

			system("cls");
			printf("[要素の削除]\n");

			//削除する場所の指定
			printf("削除する要素の場所を指定してください。\n");
			scanf_s("%d", &iterator);

			//指定された場所のまで辿って削除
			Delete(&head, iterator, listSize);

			printf("\n-------------------------------\n");
			printf("9.要素操作に戻る\n");
			scanf_s("%d", &userInput[0]);
			
			//初期画面に戻る
			if (userInput[0] == 9) {
				windowState = 0;
			}
		}

		//要素の並び替え
		if (windowState == 5) {

			system("cls");
			printf("要素の並び替え\n");

			printf("並び変えたい要素番号を指定してください。\n");
			printf("一つ目 ");
			scanf_s("%d", &userInput[0]);

			printf("二つ目 ");
			scanf_s("%d", &userInput[1]);

			//入力された二つを並び替える
			Replace(&head, userInput[0], userInput[1], listSize);

			printf("\n-------------------------------\n");
			printf("9.要素操作に戻る\n");
			scanf_s("%d", &userInput[2]);
			
			//初期画面に戻る
			if (userInput[2] == 9) {
				windowState = 0;
			}
		}
	}

	return 0;
}

//要素の生成
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

//一覧表示
void Index(CELL* head)
{
	int num = 0;	//要素の数
	int isVoid = true;	//まだ何も表示してない

	while (head->next != nullptr)
	{
		head = head->next;
		printf(" %d : %s\n", num, head->str);
		isVoid = false;
		++num;
	}

	//要素がなかった場合
	if (isVoid == true)
	{
		printf("要素がありません。\n");
	}
}

//最後尾までの要素数を数える
int Count(CELL* head, int &listSize)
{
	listSize = 0;

	//最後尾までの要素数を数える
	while (head->next != nullptr)
	{
		head = head->next;
		++listSize;
	}

	return listSize;
}

//リストの一部表示
void Choice(CELL* head, CELL* insert)
{
	//指定された場所の要素を代入
	head = insert->next;

	if (head != nullptr) {
		printf("%s \n", head->str);
	}
	else {
		printf("指定された番号に要素はありません。\n");
	}
}

//要素の編集
void Edit(CELL* head, CELL* insert, const char* str)
{
	//指定された場所の要素を代入
	head = insert->next;

	if (head != nullptr){

		//指定された場所に変更後の文字列をコピー
		strcpy_s(head->str, 8, str);

		printf("%s に変更されました。\n", head->str);
	}
	else {
		printf("指定された番号に要素はありません。\n");
	}
}

//要素の削除
void Delete(CELL* head, int itr, int& listSize){

	//要素数のカウント
	Count(head, listSize);

	CELL* deleteCell = head;

	//先頭の要素だった時
	if (itr == 0) {
		CELL* newheadCell;
		//先頭の繋ぎ変え
		newheadCell = deleteCell->next->next;
		deleteCell->next = newheadCell;	
		printf("要素番号 %d番 の削除が完了しました。\n",itr);
	}
	//先頭以外の場合
	else {

		//指定した要素番号がリストにあるか確認
		if (itr < listSize) {

			//指定した部分まで辿る
			for (int i = 0; i <= itr; i++) {
				deleteCell = deleteCell->next;
			}

			//最後尾を削除する場合
			if (deleteCell->next == nullptr) {
				deleteCell->prev->next = nullptr;
				deleteCell->prev = nullptr;
			}
			//途中の間にある要素を削除する場合
			else {
				deleteCell->prev->next = deleteCell->next;
				deleteCell->next->prev = deleteCell->prev;
				deleteCell->next = nullptr;
				deleteCell->prev = nullptr;
			}
			printf("要素番号 %d番 の削除が完了しました。\n",itr);
		}
		//なかった場合
		else {
			printf("指定された場所に要素はありません\n");
		}
	}
}

//要素の並び替え
void Replace(CELL* head,int itr1, int itr2, int& listSize){

	//要素数のカウント
	Count(head, listSize);

	//1つ目に指定したセル
	CELL* changeSetCellOne;
	char setCellDataOne[8];

	//2つ目に指定したセル
	CELL* changeSetCellTwo;
	char setCellDataTwo[8];

	//指定した要素番号がリストにあるか確認
	if (itr1 < listSize && itr2 < listSize) {

		//それぞれの番号まで辿る
		changeSetCellOne = getInsertListAddress(head, itr1);
		changeSetCellTwo = getInsertListAddress(head, itr2);

		//並び替えるデータをコピー
		strcpy_s(setCellDataOne, 8, changeSetCellOne->next->str);
		strcpy_s(setCellDataTwo, 8, changeSetCellTwo->next->str);

		//1つ目のデータを2つ目の場所にコピー
		head = changeSetCellOne->next;
		strcpy_s(head->str, 8, setCellDataTwo);

		//2つ目のデータを1つ目の場所にコピー
		head = changeSetCellTwo->next;
		strcpy_s(head->str, 8, setCellDataOne);

		printf("%d番 %s と %d番 %s を並び替えました\n", itr1, setCellDataOne, itr2, setCellDataTwo);
	}
	//なかった場合
	else {
		printf("指定した要素番号に要素が入ってないものが含まれています。\n");
	}
}

//指定された要素番号を辿る
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