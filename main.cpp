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
			printf("�����I�����Ă��������B\n");
			printf("1:�S���҂̕\��\n");
			printf("2:�S���҂̐V�K�쐬\n");
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

		//���[�U�[�̐V�K�쐬
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