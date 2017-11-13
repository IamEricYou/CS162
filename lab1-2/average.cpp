
#include <iostream>
#define SIZE 4

   double average(int* valueArray, double size);

   int main(){
	  	int array[SIZE] = {1, 2, 3, 4};
			double average_answer;
				average_answer = average(array, SIZE);
					std::cout << average_answer << std::endl;
   }

/**
 *  * Function to calculate average of 
 *   * @param valueArray (populated array of values)
 *    * @param size (number of values inside array)
 *     * @return the average value of the array contents
 *      **/ 

double average(int* valueArray, double size){
     int i;
	   double average=0;
	   double result=0;

		   /* average calculation*/
		   for(i = 0; i < size; i++){
			      average = average + double(valueArray[i]);
				    }

		     result = average / size;
			   return result;
}

