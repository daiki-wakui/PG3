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
			printf("[�v�f�̑���]\n");
			printf("1.�v�f�̕\��\n");
			printf("2.�v�f�̑}��\n");
			printf("3.�v�f�̕ҏW\n");
			printf("4.�v�f�̍폜\n");
			printf("5.�v�f�̕��ёւ�(�I�v�V����)\n");
			printf("-------------------------------\n");
			printf("�����I�����ĉ�����\n");
			scanf_s("%d", &userInput);
			state = userInput;
		}

		if (state == 1) {
			
			if (isDraw[0] == 0) {
				system("cls");
				userInput = 0;
				printf("[�v�f�̕\��]\n");
				printf("1.�v�f�̈ꗗ�\��\n");
				printf("2.���Ԃ��w�肵�ėv�f��\��\n");
				printf("9.�v�f����ɖ߂�\n");
				printf("\n�����I�����ĉ�����\n");
				scanf_s("%d", &userInput);
				isDraw[0] = 1;
			}
			
			if (userInput == 1) {
				if (isDraw[1] == 0) {
					system("cls");
					printf("[�v�f�̈ꗗ�\��]\n");
					isDraw[1] = 1;
				}

				scanf_s("%d", &userInput);
			}

			if (userInput == 2) {
				if (isDraw[2] == 0) {
					system("cls");
					printf("[���Ԃ��w�肵�ėv�f��\��]\n");
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
			printf("�v�f�̑}��\n");
		}

		if (state == 3) {
			printf("�v�f�̕\��\n");
		}

		if (state == 4) {
			printf("�v�f�̕\��\n");
		}

		if (state == 5) {
			printf("�v�f�̕\��\n");
		}
	}
	

	return 0;
}