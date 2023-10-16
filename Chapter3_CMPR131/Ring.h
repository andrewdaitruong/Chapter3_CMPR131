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

	// overloader =
	void operator=(const Ring& other);
};