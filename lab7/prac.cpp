#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

int main()
{
	int SIZE = 5, last_size = 5;
	int **mat = NULL;
	int **mat2 = NULL;
	int count = 1, arr_count =0;

	mat = new int*[SIZE];	 

	for (int i = 0; i < SIZE;i++)
 	{
 	  mat[i] = new int[SIZE];
  	}
	 
 	for (int i = 0; i < SIZE; i++)
 	{
 		  for (int j = 0; j < SIZE; j++)
  		  {
				mat[i][j] = count;
				count++;
   		  }
  	 }
	
 	 for (int i = 0; i < SIZE; i++)
 	 {
 		  for (int j = 0; j < SIZE; j++)
  		  {
  			   cout << mat[i][j] << " ";
   		  }
  		  cout << endl;
  	 }
	
	 for(int i=0;i<SIZE;i++)
	 {
		delete[] mat[i];
	 }
	 delete[] mat;

	 cout << " Add more elements" << endl;
	 count = 1;
	 last_size = SIZE + 2;

	 mat2 = new int*[last_size];
	 for(int i=0;i<last_size;i++)
	 {
		mat2[i] = new int[last_size];
	 }

	 for (int i=0; i< last_size;i++)
	 {
		for(int j=0;j<last_size;j++)
		{
			mat2[i][j] = count;
			count ++;
		}
	 }

	 for(int i=0;i < last_size;i++)
	 {
		 for(int j=0;j<last_size;j++)
		 {
			cout << mat2[i][j] << " ";
		 }
		 cout << endl;
	 }
 	 for (int i = 0; i < last_size; i++)
 	 {
 		  delete[] mat2[i];
  	 }
 	 delete[] mat2;
	 return 0;
}
