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
	printf("‹éŒ`‚Ì–ÊÏ %d\n",size);
}
