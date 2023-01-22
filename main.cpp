#include <stdio.h>
#include <stdlib.h>
#include "IShape.h"
#include "Circle.h"
#include "Rectangle.h"

using namespace std;

int main() {

	IShape* shape[2];

	//¶¬
	shape[0] = new Circle;
	shape[1] = new Rectangle;

	//–ÊÏ‚ğŒvZ
	shape[0]->Size();
	shape[1]->Size();

	//–ÊÏ‚Ì’l‚ğ•`‰æ
	shape[0]->Draw();
	shape[1]->Draw();

	//íœ
	delete shape[0];
	delete shape[1];

	system("pause");

	return 0;
}