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

				int i = 0;

				for (auto itr = lst.begin(); itr != lst.end(); ++itr) {
					printf(" %d : ", i);
					cout << *itr << "\n";
					i++;
				}

				printf("}\n");

				printf("�v�f�� : ");
				cout << lst.size() << "\n";

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
				scanf_s("%d", &userInput[2]);
				printf("�v�f�ԍ� %d : ", userInput[2]);
				itr = lst.begin();
				for (int i = 0; i < userInput[2]; i++) {
					++itr;
				}
				cout << *itr << "\n";

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
				printf("�v�f��ǉ�����ꏊ���w�肵�Ă��������B\n");
				scanf_s("%d", &userInput[0]);

				printf("�ǉ�����v�f�̒l����͂��Ă��������B\n");
				scanf_s("%s", str, 16);
				const char* newstr;
				newstr = str;

				printf("�v�f %s �� %d �Ԗڂɑ}������܂����B\n", str, userInput[0]);


				printf("\n9.�v�f����ɖ߂�\n");
				scanf_s("%d", &userInput[2]);
				isDraw[0] = 1;
			}
			
			if (userInput[2] == 9) {
				isDraw[0] = 0;
				state = 0;
			}
		}

		if (state == 3) {
			printf("�v�f�̕ҏW\n");
		}

		if (state == 4) {
			printf("�v�f�̍폜\n");
		}

		if (state == 5) {
			printf("�v�f�̕��ёւ�\n");
		}
	}
	

	return 0;
}