#include <iostream>
#include "summation.h"

using namespace std;

double sum(int size, double arr[])
{
	double result =0;
	for(int i=0;i <size;i++)
	{
		result += arr[i];
	}
	return result;
}
