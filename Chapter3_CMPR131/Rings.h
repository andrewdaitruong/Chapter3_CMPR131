#ifndef RING_H
#define RING_H



class Rings
{
private:
	int diameter;
public:
	Rings(); // constructor
	//mutators
	void setDiameter(int input);
	// accessers
	int getDiameter() const;

	void operator=(const Rings& other)
	{
		diameter = other.diameter;
	}
};

#endif // !RING_H