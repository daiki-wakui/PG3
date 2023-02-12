#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <list>

#include "User.h"

using namespace std;

int main() {



	User user1;
	User user2;

	user1.Initaize(1001, "LE2A", "タロウ");
	user2.Initaize(1002, "LE2A", "ワクイ");
	
	user1.Name();
	user2.Name();

	system("pause");
	return 0;
}