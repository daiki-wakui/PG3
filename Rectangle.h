#pragma once
#include "IShape.h"

//�h���N���X
class Rectangle : public IShape
{
private:

	int x = 3;	//�c
	int y = 4;	//��
	int size;	//�ʐ�

public:

	Rectangle();
	~Rectangle();

	void Size() override;
	void Draw() override;

};

