#include "Rectangle.h"

Rectangle::Rectangle()
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::Size()
{
	size = x * y;
}

void Rectangle::Draw()
{
	printf("��`�̖ʐ� %d\n",size);
}
