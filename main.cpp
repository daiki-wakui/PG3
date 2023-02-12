#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <list>

#include "User.h"

using namespace std;

int main() {

	

	int i = 0;
	int info = 0;
	int id = 1000;

	User* user[3];
	for (int i = 0; i < 3; i++) {
		user[i] = User::Create(id);
	}
	

	int windowState = 0;

	while (true) {

		if (windowState == 0) {
			system("cls");
			printf("操作を選択してください。\n");
			printf("1:担当者の表示\n");
			printf("2:担当者の新規作成\n");
			scanf_s("%d", &i);
			windowState = i;
		}
		
		if (windowState == 1) {
			system("cls");
			for (int i = 0; i < 3; i++) {
				if (user[i]->GetInfo() == true) {
					user[i]->Name();
				}
			}

			printf("\n-------------------------------\n");

			scanf_s("%d", &i);

			windowState = i;
		}

		//ユーザーの新規作成
		if (windowState == 2) {
			system("cls");
			for (int i = 0; i < 3; i++) {

				if (user[i]->GetInfo() == false) {
					user[i]->Initaize(id);
					id++;
					break;
				}
				else {
					continue;
				}
			}

			windowState = 0;
		}


		
		//user[1]->Name();
	}



	system("pause");
	return 0;
}