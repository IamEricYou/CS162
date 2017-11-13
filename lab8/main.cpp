#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <string>

using namespace std;

int fib_R(int num)
{
	if(num ==0)
		return 0;
	else if(num == 1)
		return 1;
	return fib_R(num-1) + fib_R(num-2);
}

int fib_NR(int num)
{
	int first = 0;
	int second =1;
	int counter = 2;
	while(counter <num)
	{
		int temp = second;
		second = first + second;
		first = temp;
		++counter;
	}
	if(num==0)
		return 0;
	else
		return first+second;
}
int main()
{
	int input;
	clock_t t1,t2;
	cout << " how many number you want to see ? : ";
	cin >> input;

	cout << " Fibo number with Recursion : ";
	t1 = clock();
	for(int i=1;i<input;i++)
	{
		cout << fib_R(i) << " ";
	}
	t1= clock() -t1;
	cout << endl;
	cout << "it took " << t1 << " clicks and " << ((double)t1/CLOCKS_PER_SEC) << " sec"<< endl;
	cout << endl;
	cout << endl;
	cout << " Fibo number with non-recursion : ";
	t2 = clock();
	for(int i=1;i<input;i++)
	{
		cout << fib_NR(i) << " ";
	}
	t2 = clock() -t2;
	cout << endl;
	cout << " it took " << t2 << " clicks and " << ((double)t2/CLOCKS_PER_SEC) << " sec" << endl;
	cout << endl;

	return 0;
}
