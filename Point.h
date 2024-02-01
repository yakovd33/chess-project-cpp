#pragma once
#include <string>
#define X 0
#define Y 1
#define FIRST_X 97
#define FIRST_Y 49
#define MAX_Y 7
using std::string;

class Point {
public:
	Point(string place);
	Point(const Point& other);
	Point(int x, int y);
	~Point();
	bool operator==(Point other);
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);

private:
	int _x;
	int _y;

};