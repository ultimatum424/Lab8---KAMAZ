#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

struct CarStruct
{
	Sprite carcase;
	Sprite wheel1;
	Sprite wheel2;
	float speed;
	float acseleration;
	int direction;
};
struct StructImage
{
	Image image;
	Texture texture;
	Sprite sprite;
};

CarStruct car;
StructImage car1;
StructImage wheel;
int WINDOW_SIZE_X = 1300;
int WINDOW_SIZE_Y = 600;
float ACSLERATION = 0.001;

