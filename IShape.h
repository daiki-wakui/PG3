#pragma once
#include <stdio.h>

//���N���X
class IShape
{
private:

public:

	IShape();
	virtual ~IShape();

	virtual void Size() = 0;
	virtual void Draw() = 0;
};

