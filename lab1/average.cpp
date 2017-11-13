#include <iostream>
#include "average.h"

using namespace std;

double avg(int size, double num[])
{
  	double result =0;
	for(int i=0;i<size;i++)
	{
		result += num[i];
	}
	return ((result)/(size));
}

/*
int main()
{
	double arr[3] = {1,2,3};
	cout << avg(3,arr);

   return 0;
}*/

