#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <string>
#include "Point2D.h"

class Creature {
private:
	std::string m_name;
	Point2D m_location;

public:
	Creature(const std::string &name, const Point2D &location)
		:m_name(name), m_location(location) {}

	friend std::ostream &operator<<(std::ostream &out, const Creature &creture) {
		out << creture.m_name << "is at" << creture.m_location;
		return out;
	}

	void moveTo(int x, int y) {
		m_location.setPoint(x, y);
	}
};


#endif