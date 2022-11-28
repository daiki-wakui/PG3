#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <list>

using namespace std;

int main() {
	int state = 0;
	int isDraw[3] = {};
	int userInput = 0;

	while (true)
	{
		
		if (state == 0) {
			system("cls");
			printf("[要素の操作]\n");
			printf("1.要素の表示\n");
			printf("2.要素の挿入\n");
			printf("3.要素の編集\n");
			printf("4.要素の削除\n");
			printf("5.要素の並び替え(オプション)\n");
			printf("-------------------------------\n");
			printf("操作を選択して下さい\n");
			scanf_s("%d", &userInput);
			state = userInput;
		}

		if (state == 1) {
			
			if (isDraw[0] == 0) {
				system("cls");
				userInput = 0;
				printf("[要素の表示]\n");
				printf("1.要素の一覧表示\n");
				printf("2.順番を指定して要素を表示\n");
				printf("9.要素操作に戻る\n");
				printf("\n操作を選択して下さい\n");
				scanf_s("%d", &userInput);
				isDraw[0] = 1;
			}
			
			if (userInput == 1) {
				if (isDraw[1] == 0) {
					system("cls");
					printf("[要素の一覧表示]\n");
					isDraw[1] = 1;
				}

				scanf_s("%d", &userInput);
			}

			if (userInput == 2) {
				if (isDraw[2] == 0) {
					system("cls");
					printf("[順番を指定して要素を表示]\n");
					isDraw[2] = 1;
				}

			}

			if (userInput == 9) {
				isDraw[0] = 0;
				isDraw[1] = 0;
				isDraw[2] = 0;
				state = 0;
			}
		}

		if (state == 2) {
			printf("要素の挿入\n");
		}

		if (state == 3) {
			printf("要素の表示\n");
		}

		if (state == 4) {
			printf("要素の表示\n");
		}

		if (state == 5) {
			printf("要素の表示\n");
		}
	}
	

	return 0;
}