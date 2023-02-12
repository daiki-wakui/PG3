#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <list>

#include "User.h"
#include "Task.h"

using namespace std;

int main() {

	int i = 0;
	int info = 0;
	int id = 1000;

	int userInput;

	User* user[3];
	for (int i = 0; i < 3; i++) {
		user[i] = User::Create(id);
	}

	int windowState = 0;

	while (true) {

		//初期画面
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

			printf("0:タスクの追加\n");
			printf("1:タスクの表示\n");
			printf("9:戻る\n");

			scanf_s("%d", &i);

			if (i == 9) {
				windowState = 0;
			}

			if (i == 0) {
				printf("誰にタスクをふる？\n");
				
				for (int i = 0; i < 3; i++) {
					printf("%d :", i);
					user[i]->Name();
				}

				scanf_s("%d", &userInput);
				user[userInput]->AddTask();


			}
			
			if (i == 1) {
				for (int i = 0; i < 3; i++) {
					printf("担当者 100%d\n",i);
					user[i]->TaskView();
				}

				printf("9:戻る\n");
				scanf_s("%d", &userInput);
				i = userInput;
			}

			printf("\n-------------------------------\n");
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
	}

	system("pause");
	return 0;
}