#pragma once
#include "IShape.h"

//�h���N���X
class Circle : public IShape
{
private:

	int r = 3;	//���a
	float PI = 3.14f;	//�~����
	float size;	//�ʐ�

public:

	Circle();
	~Circle();

	void Size() override;
	void Draw() override;

};

