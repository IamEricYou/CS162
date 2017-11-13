#ifndef Date.h
#include <iostream>
#include <string>
#define Date.h

using namespace std;

class date
{
   private:
   int month;
   int day;
   int year;
   string name; 
   public:
   date();
   ~date();
   date(int month,int day,int year);
	void SetMonth(int num);
	void SetYear(int num);
	void SetDay(int num);
    int GetMonth();
	int GetYear();
	int GetDay();
//	void SetMonth(int &num);
	void print();
};

#endif
