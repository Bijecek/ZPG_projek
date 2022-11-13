#pragma once
#include <vector>
#include "Observer.h"
class Subject
{
public:
	virtual void attach(Observer *obs);
	virtual void notify();
private:
	std::vector<Observer*> observers;
};

