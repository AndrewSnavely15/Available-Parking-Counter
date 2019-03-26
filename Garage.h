#ifndef GARAGE_H
#define GARAGE_H
#include <iostream>
#include <vector>
using namespace std;

class Garage
{
public:
	void display();
	void display2();
	void spaces();
	bool fillup();
	int numofOpenSpaces();
	int numofTakenSpaces();
private:
	int open;
	int taken;
	vector <int> garageSpaces;
	vector<bool> bs;
};
#endif
