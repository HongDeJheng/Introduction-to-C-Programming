/* EE231002 Lab04. Deciphering Roman Numerals 
 * 104061210, Hong-De Jheng
 * Date:2015/10/19
 */

#include <stdio.h>

int main(void)
{

	char ch, pre; 
	// ch represents input character,pre represents previous character input
	int v=0, cor, pre_cor = 0;
	/* v represents total value,cor represents ch's correspondence value,pre_cor
	   represents pre's correspondence value */

	printf("Input a Roman Numeral: ");	// print out "Input a Roman Numeral: "
	while ((ch=getchar()) != '\n') {	
	// when (ch=getchar()) != '\n',run the bellowing statement 
		switch (ch) {	// tests ch by the conditions bellow
			case 'M': cor = 1000; pre = 'M'; break;
			//when ch = 'M',declare cor = 1000 and pre = 'M',if don't,keep going
			case 'D': cor = 500; pre = 'D'; break;
			//when ch = 'D',declare cor = 500 and pre = 'D',if don't,keep going
			case 'C': cor = 100; pre = 'C'; break;
			//when ch = 'C',declare cor = 100 and pre = 'C',if don't,keep going
			case 'L': cor = 50; pre = 'L'; break;
			//when ch = 'L',declare cor = 50 and pre = 'L',if don't,keep going
			case 'X': cor = 10; pre = 'X'; break;
			//when ch = 'X',declare cor = 10 and pre = 'X',if don't,keep going
			case 'V': cor = 5; pre = 'V'; break;
			//when ch = 'V',declare cor = 5 and pre = 'V',if don't,keep going
			case 'I': cor = 1; pre = 'I'; break;
		}	//when ch = 'I',declare cor = 1 and pre = 'I',if don't,keep going
		if (cor <= pre_cor) { 
		// tests whether cor is smaller than or equal to pre_cor
			v += cor; // declare v = v + cor
			pre_cor = cor; // declare pre_cor = cor
		}
		else {	// if cor > pre_cor
			v += (cor - pre_cor*2); //declare v = v = (cor - pre_cor*2)
			/* because the ch on the right is bigger than on the right you 
			   should subtract the value(pre_cor) you add at the first loop 
			   before you add the new one(cor - pre_cor) */
			pre_cor = (v + pre_cor); //declare pre_cor = (v + pre_cor)
			/* you subtract pre_cor twice at the statement above,but it doesn't
			   represents the pre_cor correctly,so you need to add it back */
		}
	}
	printf("The value is: %d\n", v); // print out the total value
	return 0;
}
