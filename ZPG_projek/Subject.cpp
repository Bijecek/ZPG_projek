#include "Subject.h"

void Subject::attach(Observer* obs)
{
	this->observers.push_back(obs);
}

void Subject::notify()
{
	for (Observer* o : observers) {
		o->update(this);
	}
	std::cout << "-------" << std::endl;
	std::cout << "Camera moved" << std::endl;
}