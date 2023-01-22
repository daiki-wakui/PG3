#pragma once
#include "IShape.h"

//”h¶ƒNƒ‰ƒX
class Circle : public IShape
{
private:

	int r = 3;	//”¼Œa
	float PI = 3.14f;	//‰~ü—¦
	float size;	//–ÊÏ

public:

	Circle();
	~Circle();

	void Size() override;
	void Draw() override;

};

