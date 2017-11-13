#include <iostream>

using namespace std;

double avg(int size, double arr[]);
double sum(int size, double arr[]);

int main()
{
	int size;
	cin >> size;

	double arr[size];
	for(int i=0;i<size;i++)
	{
		cin >> arr[i];
	}

	cout << "avg : " << avg(size,arr) << endl;
	cout << "sum : " << sum(size,arr) << endl;
	
   return 0;
}
