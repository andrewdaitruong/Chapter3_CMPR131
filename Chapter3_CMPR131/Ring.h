#pragma once

class Ring
{
private:
	int diameter;
public:
	Ring(); // constructor
	//mutators
	void setDiameter(int input);
	// accessers
	int getDiameter() const;

	void operator=(const Ring& other)
	{
		diameter = other.diameter;
	}
};