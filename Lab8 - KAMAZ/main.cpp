#include "configuration.h"
#include <iostream>

void InicializationCar(StructImage& car1, StructImage& wheel, CarStruct& car)
{
	car1.image.loadFromFile("D:/������/��� � ����/Lab8 - KAMAZ/KAMAZ2.png");
	car1.texture.loadFromImage(car1.image);
	car1.sprite.setTexture(car1.texture);

	wheel.image.loadFromFile("D:/������/��� � ����/Lab8 - KAMAZ/wheel.png");
	wheel.texture.loadFromImage(wheel.image);
	wheel.sprite.setTexture(wheel.texture);

	car.carcase = car1.sprite;
	car.carcase.setPosition(900, 200);
	car.wheel1 = wheel.sprite;
	car.wheel2 = wheel.sprite;
	car.wheel1.setOrigin(32, 32);
	car.wheel2.setOrigin(32, 32);
	car.wheel1.setPosition(car.carcase.getPosition().x + 71, car.carcase.getPosition().y + 125);
	car.wheel2.setPosition(car.carcase.getPosition().x + 281, car.carcase.getPosition().y + 124);

	car.speed = 0;
	car.acseleration = 0;
	car.direction = 0;
}
void MoveCar(CarStruct& car)
{
	if (car.direction == 1)
	{
		car.speed = car.speed + car.acseleration;
		car.carcase.setPosition(car.carcase.getPosition().x + car.speed, car.carcase.getPosition().y);
		car.wheel1.setPosition(car.wheel1.getPosition().x + car.speed, car.wheel1.getPosition().y);
		car.wheel2.setPosition(car.wheel2.getPosition().x + car.speed, car.wheel2.getPosition().y);
	}
	else if (car.direction == -1)
	{
		car.speed += car.acseleration;
		car.carcase.setPosition(car.carcase.getPosition().x - car.speed, car.carcase.getPosition().y);
		car.wheel1.setPosition(car.wheel1.getPosition().x - car.speed, car.wheel1.getPosition().y);
		car.wheel2.setPosition(car.wheel2.getPosition().x - car.speed, car.wheel2.getPosition().y);
	}
}
void BreakCar(CarStruct& car)
{
	if ((car.direction == 1) && (car.speed > 0.001))
	{
		car.speed = car.speed + car.acseleration;
		car.carcase.setPosition(car.carcase.getPosition().x + car.speed, car.carcase.getPosition().y);
		car.wheel1.setPosition(car.wheel1.getPosition().x + car.speed, car.wheel1.getPosition().y);
		car.wheel2.setPosition(car.wheel2.getPosition().x + car.speed, car.wheel2.getPosition().y);
	}
	else if ((car.direction == -1) && (car.speed > 0.001))
	{
		car.speed = car.speed + car.acseleration;
		car.carcase.setPosition(car.carcase.getPosition().x - car.speed, car.carcase.getPosition().y);
		car.wheel1.setPosition(car.wheel1.getPosition().x - car.speed, car.wheel1.getPosition().y);
		car.wheel2.setPosition(car.wheel2.getPosition().x - car.speed, car.wheel2.getPosition().y);
	}
}
void SetDirection(CarStruct& car)
{
	if (car.speed < 0.0001)
	{
		car.direction = 0;
		car.speed = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		if (car.speed == 0)
		{
			car.direction = 1;
			car.acseleration = ACSLERATION;
		}
		if (car.direction == 1)
		{
			car.acseleration = ACSLERATION;
		}
		if (car.direction == -1)
		{
			car.acseleration = -ACSLERATION;
		}
		MoveCar(car);
	}
	else if (Keyboard::isKeyPressed(Keyboard::A))
	{
		if (car.speed == 0)
		{
			car.direction = -1;
			car.acseleration = ACSLERATION;
		}
		if (car.direction == -1)
		{
			car.acseleration = ACSLERATION;
		}
		if (car.direction == 1)
		{
			car.acseleration = -ACSLERATION;
		}
		MoveCar(car);
	}
	else
	{
		car.acseleration = -ACSLERATION;
		BreakCar(car);
	}
}

void Display(CarStruct car, RenderWindow& window)
{
	window.clear(Color::White);
	window.draw(car.carcase);
	window.draw(car.wheel1);
	window.draw(car.wheel2);
	window.display();
}
int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "CLOCK", sf::Style::Default, settings);
	InicializationCar(car1, wheel, car);
	while (window.isOpen())
	{
		if (Keyboard::isKeyPressed(Keyboard::Space)) system("pause");
		sf::Event event;
		SetDirection(car);
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		Display(car, window);
	}
	
	return 0;
}