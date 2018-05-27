/* EE231002 Lab08. Blackjack
 * 104061210, Hong-De Jheng
 * Date:2015/11/16
 */

#include <stdio.h>
#include <stdlib.h>
#define N 10000

int card;				// card that you get

double probability();	// function declaration

int main(void)
{
	double p=0, b=0;	// p represents point, b represents times of busted
	int i, k;			// i controls times of experiment, k controls point we 
						// need to calculate
	printf("Points  E(hit)  % Busted\n");	// print out words
	for (k=2; k<21; k++) {					// loop for control initial point
		for (i=0; i<N; i++) {				// loop for control experiment
			card = rand() % 13 + 1;			// card is a random number of
											// reminders of 13 and + 1
			if (card>10) {					// let J, Q, K become 10 points 
				p+=(k+10);					// total points + 10
				if ((k+10)>21)				// if the points we want to add is
					b++;					// over 21, b + 1
			}
			else if (card==1 && (k+11)<=21)	// A become 11 points when points we
				p+=(k+11);					// want to add is smaller than 21
			else {							// for other card just add the 
				p+=(k+card);				// points it represents
				if ((k+card)>21)			// if the points we want to add is
					b++;					// over 21, b + 1
			}
		}
	printf("%4d     %5.2lf    %6g\n", k, p/N, b/N*100); // print out result
	p=0;									// reinitialize p to 0
	b=0;									// reinitialize b to 0
	}
	printf("\n");							// new line
	printf("Probablility of getting 21 points is %.2lf%\n", probability());
											// print out result
	return 0;
}

double probability()
{
	int i, p=0, j, x=0;			// i controls times of experiment, p represents
								// points, j used to dealt first two cards, x
								// records # of 'A' which represents 11 points
	double s=0;					// s represents times of successfully getting 21
	
	for (i=0; i<N; i++) {					// loop for control experiment times
		for (j=0; j<2; j++) { 				// loop for deal first two cards
			card = rand() % 13 + 1;			// initialize card randomly
			if (card>10) {					// let J, Q, K become 10 points 
				p+=10;						// total points + 10
				if (p>21 && x!=0) {			// if total points is over 21 and
					p-=10;					// there's an A represents 11 points
					x--;					// total points - 10 and x - 1
				}
			}
			else if (card==1 && p<=10) {	// A represents 11 points when total
				p+=11;						// points is smaller or equal to 10,
				x++;						// and x + 1
			}
			else {							// for other card just add the 
				p+=card;					// points it represents
				if (p>21 && x!=0) {			// if total points is over 21 and
					p-=10;					// there's an A represents 11 points
					x--;					// total points - 10 and x - 1
				}
			}
		} 
		while (p<21) {			// loop for getting more cards when sum of first
								// two cards is smaller than 21
			card = rand() % 13 + 1;			// intialize card randomly
			if (card>10) {					// let J, Q, K represents 10 points
				p+=10;						// total points + 10
				if (p>21 && x!=0) {			// if total points is over 21 and
					p-=10;					// there's an A represents 11 points
					x--;					// total points - 10 and x - 1
				}
			}
			else if (card==1 && p<=10) {	// A represents 11 points when total
				p+=11;						// points is smaller or equal to 10,
				x++;						// and x + 1
			}
			else {
				p+=card;
				if (p>21 && x!=0) {			// if total points is over 21 and
					p-=10;					// there's an A represents 11 points
					x--;					// total points - 10 and x - 1
				}
			}
		}
		if (p==21) 							// if total points equals to 21,
			s++;							// s + 1
		p=0;								// reinitialize p to 0
		x=0;								// reinitialize x to 0
	}
	return s/N*100;							// send s/N*100 back
}		
