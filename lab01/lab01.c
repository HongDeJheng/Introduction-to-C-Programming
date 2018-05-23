/* EE231002 Lab01 Currency Exchange
   104061210, 鄭弘得
   Date:2015/9/21
*/

#include<stdio.h>                                                                                 

int main(void)                                                                               
{
    int x;                                    // x refers to Amount of USD to buy	             
    float y;                                  // y refers to Total needs to pay               
	
    printf("Amount of USD to buy: ");         // show "Amount of USD to buy:"	 
    scanf ("%d", &x);                         // read Amount of USD to buy that you input	 
	y = 32.57 * x + 100;                      // a formula calculates "Total needs to pay"		 
	printf("Total needs to pay: %.2f\n", y);  // print out "Total needs to pay:"      
	return 0;                                 
}
