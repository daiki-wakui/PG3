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

	user1.Initaize("aio",1001);
	user2.Initaize("ƒƒNƒC",1002);
	
	user1.Name();
	user2.Name();

	system("pause");
	return 0;
}