#include "Circle.h"

Circle::Circle()
{
}

Circle::~Circle()
{
}

void Circle::Size()
{
	size = r * r * 3.14;
}

void Circle::Draw()
{
	printf("�~�̖ʐ� %f\n",size);
}
