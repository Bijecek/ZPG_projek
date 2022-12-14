#pragma once
#include <vector>
#include <iostream>
#include "Observer.h"
class Subject
{
public:
	virtual void attach(Observer *obs);
	virtual void notify();
private:
	std::vector<Observer*> observers;
};

