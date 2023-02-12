#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <list>

#include "User.h"
#include "Task.h"

using namespace std;

int main() {

	int inputInfo = 0;
	int id = 1000;
	int userInput;
	int windowState = 0;

	//�O�l�`�[��
	User* user[3];
	for (int i = 0; i < 3; i++) {
		user[i] = User::Create(id);
	}

	while (true) {

		//�������
		if (windowState == 0) {
			system("cls");
			printf("�����I�����Ă��������B\n");
			printf("1:�S���҂̕\��\n");
			printf("2:�S���҂̐V�K�쐬\n");
			scanf_s("%d", &inputInfo);
			windowState = inputInfo;
		}
		
		//�S���ҏ��
		if (windowState == 1) {
			system("cls");
			//���O�̕\��
			for (int i = 0; i < 3; i++) {
				if (user[i]->GetInfo() == true) {
					user[i]->Name();
				}
			}

			printf("\n-------------------------------\n");

			printf("0:�^�X�N�̒ǉ�\n");
			printf("1:�^�X�N�̕\��\n");
			printf("9:�߂�\n");

			scanf_s("%d", &inputInfo);

			//������ʂɖ߂�
			if (inputInfo == 9) {
				windowState = 0;
			}

			//�^�X�N�̒ǉ�
			if (inputInfo == 0) {
				printf("�N�Ƀ^�X�N���ӂ�܂����H\n");
				
				for (int i = 0; i < 3; i++) {
					printf("%d :", i);
					user[i]->Name();
				}

				//���͂��ēo�^
				scanf_s("%d", &userInput);
				user[userInput]->AddTask();
			}
			
			//�^�X�N�̕\��
			if (inputInfo == 1) {

				for (int i = 0; i < 3; i++) {
					printf("�S���� 100%d\n",i);
					user[i]->TaskView();
				}

				printf("9:�߂�\n");
				scanf_s("%d", &userInput);
				inputInfo = userInput;
			}

			printf("\n-------------------------------\n");
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
	}

	system("pause");
	return 0;
}