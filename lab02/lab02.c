/* EE231002 Lab02 Currency Exchange, II
   104061210, 鄭弘得
   Date:2015/10/5
*/

#include <stdio.h>

int main(void)
{
	int USD, r;														// USD refers to USD amount and r refers to the remainder after calculating

	printf("Enter USD amount: ");									// show "Enter USD amount: "
	scanf("%d", &USD);												// read USD amount that you imput
	if ((USD/1000) != 0) {											// tests whether USD/1000 isn't equal to 0
		if ((USD/1000) == 1) 										// tests whether USD/1000 is equal to 1 		
			printf("  1 $1000 bill\n");								// print out how many $1000 bills that you need
		else 														// if the condition((USD/1000) == 1) above doesn't correspond
			printf("  %d $1000 bills\n", (USD/1000));				// print out how many $1000 bills that you need
		}
	r = USD % 1000;													// redeclare remainder r = USD % 1000
	if ((r/100) != 0) {												// tests whether r/100 isn't equal to 0
		if ((r/100) == 1)											// tests whether r/100 is equal to 1
			printf("  1 $100 bill\n");								// print out how many $100 bills that you need
		else														// if the condition((r/100) == 1) above doesn't correspond
			printf("  %d $100 bills\n", (r/100));					// print out how many $100 bills that you need
		}
	r = USD % 100;													// redeclare remainder r = USD % 100
	if ((r/50) != 0) {												// tests whether r/50 isn't equal to 0
		if ((r/50) == 1)											// tests whether r/50 is equal to 1
			printf("  1 $50 bill\n");								// print out how many $50 bills that you need
		else														// if the condition((r/50) == 0) above doesn't correspond
			printf("  %d $50 bills\n", (r/50));						// print out how many $50 bills that you need
		}
	r = USD % 50;													// redeclare remainder r = USD % 50
	if ((r/20) >= 1) {												// tests whether r/20 is equal or greater than 1
		if ((r/20) == 1) {											// tests whether r/20 is equal to 1
			printf("  1 $20 bill\n");								// print out how many $20 bills that you need
			if ((r % 20) > 10)										// tests whether r%20 is greater than 10
				printf("  1 $10 bill\n");							// print out how many $10 bills that you need
			}
		else {														// if the condition((r/20) == 1) above doesn't correspond
			printf("  %d $20 bills\n", (r/20));						// print out how many $20 bills that you need
			if ((r % 20) > 10)										// tests whether r%20 is greater than 10
				printf("  1 $10 bill\n");							// print out how many $10 bills that you need
			}
	}
	r = USD % 10;													// redeclare remainder r = USD % 10
	if ((r/5) == 1) {												// tests whether r/5 is equal to 1
		printf("  1 $5 bill\n");									// print out how many $5 bills that you need
		switch ((USD % 5)) {										// tests USD%5 by the condition below
			case 4: printf("  2 $2 bills\n"); break;				// if USD%5 = 4,print out how many $2 bills that you need,if don't,keep going
			case 3: printf("  1 $2 bill\n  1 $1 bill\n"); break;	// if USD%5 = 3,print out how many $2 and $1 bills that you need,if don't,keep going
			case 2: printf("  1 $2 bill\n"); break;					// if USD%5 = 2,print out how many $2 bills that you need,if don't,keep going
			case 1: printf("  1 $1 bill\n"); break; 				// if USD%5 = 1,print out how many $1 bills that you need,if don't,keep going
		}
	}
	else {															// if the condition((r/5) == 1) above doesn't correspond
		switch ((USD % 5)) {										// tests USD%5 by the condition below
			case 4: printf("  2 $2 bills\n"); break;				// if USD%5 = 4,print out how many $2 bills that you need,if don't,keep going
			case 3: printf("  1 $2 bill\n  1 $1 bill\n"); break;	// if USD%5 = 3,print out how many $2 and $1 bills that you need,if don't,keep going
			case 2: printf("  1 $2 bill\n"); break;					// if USD%5 = 2,print out how many $2 bills that you need,if don't,keep going
			case 1: printf("  1 $1 bill\n"); break;					// if USD%5 = 1,print out how many $1 bills that you need,if don't,keep going
		}
	}
	return 0;
}
