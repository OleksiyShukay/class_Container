#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>

class Point2D {
private:
	int m_x;
	int m_y;

public:
	//конструктор по умолчанию
	Point2D() :m_x(0), m_y(0) {
	
	}

	//Специфический конструктор
	Point2D(int x, int y) :m_x(x), m_y(y) {
	
	}

	//Перегрузка оператора вывода
	friend std::ostream &operator << (std::ostream &out, const Point2D &point) {
		out << "(" << point.m_x << ", " << point.m_y << ")";
		return out;
	}

	//функции доступа
	void setPoint(int x, int y) {
		m_x = x;
		m_y = y;
	}

};

#endif