// №147_Composition_of_object. КОМПОЗИЦИЯ ОБЕКТОВ


//Point2D.h
#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>
class Point2D {
private:
	int m_x;
	int m_y:
public:
	Point2D() :m_x(0), m_y(0) {}
	Point2D(int x, int y) :m_x(x), m_y(y) {}
	friend std::ostream &operator << (std::ostream &out, const Point2D &point) {
		out << "(" << point.m_x << ", " << point.m_y << ")";
		return out;
	}

	void setPoint(int x, int y) {
		m_x = x;
		m_y = y;
	}
};

#endif

//Creature.h
#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <string>
#include "Point2D.h"
class Creature {
private:
	std::string m_name;//продолжительность жизни зависит от жизни Creature
	Point2D m_location;//продолжительность жизни зависит от жизни Creature
public:
	Creature(const std::string &name, const Point2D &location) :
		m_name(name), m_location(location) {}

	friend std::ostream &operator << (std::ostream &out, const Creature &creature) {
		out << creature.m_name << " is at " << creature.m_location;
		return out;
	}

	void moveTo(int x, int y) {
		m_location.setPoint(x, y);
	}
};
#endif

 //main.cpp
#include <iostream>
#include <string>
#include "Creature.h"
#include "Point2D.h"

int main() {
	std::cout << " Enter a name for your creature: ";
	std::string name;
	std::cin >> name;
	Creature creature(name, Point2D(5, 6));
	while (1) {
	    //Выводим  имя существа и его месторасположение
		std::cout << creature << '\n';
		std::cout << " Enter new X location for creature (-1 to quite): ";
		int x = 0;
		std::cin >> x;
		if (x == -1)
			break;
		std::cout << " Enter new X location for creature (-1 to quite): ";
		int y = 0;
		std::cin >> y;
		if (y == -1)
			break;
		creature.moveTo(x, y);
	}
	return 0;
}