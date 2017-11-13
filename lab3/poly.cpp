#include <iostream>

using namespace std;

class Animal
{

public:
	//void id(){cout << "animal~~" <<endl;}
	virtual void id(){ cout << "animal~" << endl;}

};

class Cat: public Animal
{

public:
	//void id(){cout << "Cat~~" << endl;}
	virtual void id(){ cout << "Cat~~" <<endl;}
};

class Dog: public Animal
{

public:
	//void id(){ cout << "Dog~~" << endl;}
	virtual void id(){ cout << "Dog~~" << endl;}
};

int main()
{
	Animal *pA[] = {new Animal, new Dog, new Cat};
	for(int k=0; k<3; k++)
		pA[k]->id();
	
	return 0;
}
