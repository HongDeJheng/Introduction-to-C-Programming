/* EE231002 Lab03 Pythagorean Triples
   104061210, 鄭弘得
   Date:2015/10/12
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
	
	int a, b, n = 0, m;						// a,b,n,m refers to int
	double c;								// c refers to double

		for ( b = 4 ; b <= 20000; b++)		// first loop,with b in it
		{
			for ( a = 3; a <= b; a++)		// second loop with a in it
			{
				c = sqrt(a*a+b*b);			// declare c=sqrt(a*a+b*b)
				m = c/1;					// declare m=c/1(m is an integer)
				if (c == m && c <= 20000)	// test the expr whether correspond 
				{
					n++;					// n+1
					printf("Pythagorean Triple #%d is (%d,%d,%d)\n", n, a, b, m);
				}	// print out the sentence in double quotes
			}	
		}
	printf("Total number of Pythagorean triples found is %d\n", n); 
	// print out the sentence in double quotes
	return 0;								
}
