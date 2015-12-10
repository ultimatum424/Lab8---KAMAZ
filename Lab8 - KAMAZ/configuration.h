#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
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
const int WINDOW_SIZE_X = 1300;
const int WINDOW_SIZE_Y = 600;
const int RADIUS_WHEEL = 32;
const float CIRCUMFERENCE = RADIUS_WHEEL * 2 * M_PI;
const float ACSLERATION = 0.001;

