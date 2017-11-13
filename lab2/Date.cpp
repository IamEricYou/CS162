#include "Date.h"

void date::SetMonth(int num)
{
	month = num;
}

void date::SetYear(int num)
{
	year = num;
}

void date::SetDay(int num)
{
	day = num;
}

int date::GetMonth()
{
	do
	{
	   cin.clear();
	   cin.ignore();
	    cout << "Month? :";
		cin >> month;
	}while((month<0) && (month >13));

	return month;
}

int date::GetYear()
{
    cout << "Year? :";
	cin >> year;

	return year;
}

int date::GetDay()
{
	do
	{
	   cin.clear();
	   cin.ignore();
	    cout << "day? :";
		cin >> day;
	}while(day<0 && day >31);

	return day;
}

date::date(int m,int d,int y)
{
	month = m;
	day = d;
	year = y;
}

date::date()
{
	month = 1;
	day = 1;
	year = 2001;
}

void date::print()
{
    switch(month)
	{
	case 1: name = "January";
			break;
	case 2: name = "Feb";
			break;
	case 3: name = "Mar";
			break;
	case 4: name = "April";
			break;
	case 5: name = "May";
			break;
	case 6: name = "June";
			break;
	case 7: name = "July";
			break;
	case 8: name = "August";
			break;
	case 9: name = "September";
			break;
defualt: name = "Wrong";
		 break;
	}
	cout << month <<"/"<< day <<"/" << year - 2000 << endl;
	cout << name << " " << day <<", "<< year << endl;
	cout << day << " " << name << " " << year << endl;

}

date::~date(){};
