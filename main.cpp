#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <list>

using namespace std;

int main() {
	list<const char*> lst(0);
	auto itr = lst.begin();
	itr = lst.insert(itr, "tuika");
	++itr;
	itr = lst.insert(itr, "tuika2");
	++itr;
	itr = lst.insert(itr, "tuika3");

	int state = 0;

	int isDraw[3] = {};
	int userInput[3] = {};
	char str[16] = {};

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

				int i = 0;

				for (auto itr = lst.begin(); itr != lst.end(); ++itr) {
					printf(" %d : ", i);
					cout << *itr << "\n";
					i++;
				}

				printf("}\n");

				printf("要素数 : ");
				cout << lst.size() << "\n";

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
				scanf_s("%d", &userInput[2]);
				printf("要素番号 %d : ", userInput[2]);
				itr = lst.begin();
				for (int i = 0; i < userInput[2]; i++) {
					++itr;
				}
				cout << *itr << "\n";

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
				printf("要素を追加する場所を指定してください。\n");
				scanf_s("%d", &userInput[0]);

				printf("追加する要素の値を入力してください。\n");
				scanf_s("%s", str, 16);
				const char* newstr;
				newstr = str;

				printf("要素 %s が %d 番目に挿入されました。\n", str, userInput[0]);


				printf("\n9.要素操作に戻る\n");
				scanf_s("%d", &userInput[2]);
				isDraw[0] = 1;
			}
			
			if (userInput[2] == 9) {
				isDraw[0] = 0;
				state = 0;
			}
		}

		if (state == 3) {
			printf("要素の編集\n");
		}

		if (state == 4) {
			printf("要素の削除\n");
		}

		if (state == 5) {
			printf("要素の並び替え\n");
		}
	}
	

	return 0;
}