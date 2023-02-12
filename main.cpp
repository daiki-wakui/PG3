#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <list>

#include "User.h"

using namespace std;

int main() {

	int i = 0;
	

	User user1;
	User user2;



	//scanf_s("%d", i);

	user1.Initaize(1001, "LE2A");
	user2.Initaize(1002, "LE2A");
	
	user1.Name();
	user2.Name();

	system("pause");
	return 0;
}