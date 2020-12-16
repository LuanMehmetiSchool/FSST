/*
name: Calculates the int sqrt of the given arguments
author: Luan Mehmeti
version: 1.0
*/

#include <stdio.h>
#include <stdlib.h>




int multiply(number1, number2){
    int value = 0;
    
    /*to setup 1 as star value for the following loops*/
    int ivalue = 0;
    ++ivalue;
    int jvalue = 0;
    ++jvalue;

    /*
    This function returns a multiplication value of 2 numbers.
    To multiply 2 numbers without the usage of operation *, the function uses 2 loops.
    For example:
    You want to multiply 5 by 2.
    The first loop will count till 5 and the secound until 2.
    And in the secound loop there is a nincreasement of 2, because the loop counts 2 times and does 2 times an increasement.
    So the first loop counts 5 times, and does 5 times 2 increasements, so the value after the loop would be 10.
    */
    for(int i = ivalue; i <= number1; ++i){
        for(int j = jvalue; j <= number2; ++j){
            value++;
        }
    }

    return value;
}

int my_sqrt(number){
    int value = 0;
    int multiplication;
    // Counting till the size of the number
    for(int i = 0; i <= number; ++i){

        multiplication = multiply(i, i);
        // After some trys, the multiplication value must have the value of the given number or higher
        if(number <= multiplication){
            // And here is the check, if the value of the multiplication equals or is higher than the number

            if(number != multiplication){
                    /*
                 In this case the value is higher than the number, but the factor is only 1 too high.
                 It's only one the high, because the check is already valid, if it's 1 too high.
                 So to explain that, if you enter 15. I = 3 (3*3) is too small for the check.
                 I = 4 would be valid for the check.
                 But if you multply 4 by 4, the value would be 16, and not 15.
                 So i must be by 1 smaller.
                 To subtract i by 1 without the usage of --, there will be a loop used for.

                */
                // the subtraction by one will be done with a start value of -1, and will be counted up till the i value
                int j = -1;
                
                /*to setup 1 as start value for the following loop*/
                int kold = 0;
                ++kold;
                for(int k = kold; k <= i; ++k){
                    ++j;
                }
                value = j;
                return value;
            }else{
                // in this case the value of the multiplication equals the value of the number, there would be no residual value
                value = i;
                return value;
            }
        }
    }


}

int main()
{
    // Printing out the results till 25
    for(int i = 0; i <= 25; ++i){
        int ergebnis = my_sqrt(i);
        printf("For %d the sqrt-Value would be %d\n",i, ergebnis);
    }

    return 0;
}
