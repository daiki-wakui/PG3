#pragma once
#include "IShape.h"

//”h¶ƒNƒ‰ƒX
class Rectangle : public IShape
{
private:

	int x = 3;	//c
	int y = 4;	//‰¡
	int size;	//–ÊÏ

public:

	Rectangle();
	~Rectangle();

	void Size() override;
	void Draw() override;

};

