#pragma once
class Subject;
class Observer
{
public:
	virtual void update(Subject *sub) = 0;
};
