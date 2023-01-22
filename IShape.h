#pragma once
#include <stdio.h>

//Šî’êƒNƒ‰ƒX
class IShape
{
private:

public:

	IShape();
	virtual ~IShape();

	virtual void Size() = 0;
	virtual void Draw() = 0;
};

