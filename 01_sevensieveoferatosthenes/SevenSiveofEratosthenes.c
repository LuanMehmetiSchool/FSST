/*
name: SevenSieveofEratosthenes
author: Luan Mehmeti
version: 1.0
*/

#include <stdio.h>


// primeNumberArray (length is unknown, there is a max of 500 numbers, so the length was set to 500)
int primeNumbers[500];
// validation Var needed to check, with how many numbers a number can be divided without residual value
int validationVar = 0;
// counter Var was set for the primeNumbers Array
int counter = 0;

void findPrimeNumbers(){
	
	// Counting up to 500
	for(int i = 1;i <= 500; ++i){
		// And each number till 500 will be divided with the numbers 1-500
		for(int j = 1;j <= 500; ++j){
			// If there is no residual value, the validation Var increases
			if((i%j) == 0){
				++validationVar;
			}
		}
			/*
			 After a division cycle, a.e for 2 / 1, 2 / 2, 2 / 3, 2 / ...
			The validation Var will be checked, if there are execatly 2 numbers which can be used
			for a division without a residual value, it 's a primeNumber and has to be added into
			the primeNumbersArray.
			*/
			if(validationVar == 2){
				/*
				The counter var was set to be independent from the foor-loops, so the
				array starts with entry 0 and goes on with 1,2,3,....
				And here the primeNumbersArray gets his entrys.
				*/
				primeNumbers[counter] = i;				
				++counter;
			}
		/* it's important to reset the validation Var after a divsion cycle, 
		otherwise the check above won't work */
		validationVar = 0;
	}

	/*
	Printout of the primeNumbers array
	The counter var is used as maximum entry-number.
	*/
	for(int i = 0; i < counter; ++i){
		printf("%d, ", primeNumbers[i]);
	}

}


int main(){
	findPrimeNumbers();
	return 0;
}
