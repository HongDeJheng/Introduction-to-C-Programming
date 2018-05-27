/* EE231002 Lab07. Matrix Determinants
 * 104061210, Hong-De Jheng
 * Date:2015/11/9
 */

#include <stdio.h>
#if !defined(N)
#define N 3
#endif

void pandita(int B[N]);
int calculate(int A[N][N], int B[N]);
int power(int x, int n);

int main(void)
{
	int i, j, x=0;			// i, j, x are controlling factor
	int A[N][N], fac[N];	// A is the input array,
						// fac is the array of controlling which to calculate
	int s=1, t, Fac=1;		// s represents sum, 
							// t represents how many times pandita has done,
							// Fac represents N!
	 
	printf("Input matrix is\n ");	
	for (i=0; i<N; i++) {			// loop for scanning and printing A[N][N]
		for (j=0; j<N; j++) {
			scanf("%d", &A[i][j]);
			printf(" %d", A[i][j]);
		}
		s*=A[i][i];					// s=A[0][0]*A[1][1]*...*A[N-1][N-1]
		printf("\n");				// new line after first row is printed
		if (i != N-1)				// don't print another extra space when it
			printf(" ");			// runs to last row
	}
	for (i=0; i<N; i++) {		 // loop for initialize fac[N] and N!
		fac[i]=i;
		Fac*=(i+1);
	}
	for (t=0; t < Fac-1; t++) {  // loop when pandita hasn't done N!-1 time
								 // because line 30 is calculate, we can't
								 // calculate when pandita has done N! time
		pandita(fac);			 // do the function
		for (i=0; i<N-1; i++) {	 // loop for checking how many time it reverse
			for (j=i+1; j<N; j++) {
				if (fac[i]>fac[j]) // in general, the value is from small to big
								   // if it doesn't, it means that the array has
								   // been reverse
					x++;		 // when reverse once,x+1
			}
		}
		s+=calculate(A,fac)*power((-1),x); 
		// after pandita has done, the calculation sequence has changed
		// if its times of reverse is even, then the value is positive,
		// if its odd, then the value is negative
		x=0;					 // assign x=0 to checking the next change
	}
	printf("Det = %d\n", s);	 // print out result
	return 0;
}

void pandita(int B[N])		// changing the calculating position
{
	int j, k, maxj, maxk, temp;
	// j,k,maxj,maxk,temp are factors to implement Pandita's algorithm

	for (j=0;j<N-1;j++) {	/* loop for finding first condition of Pandita's
							   algorithm.j<N-1 because B[j+1] bellow can't 
							   be B[N] */
		if (B[j]<B[j+1])	// tests whether B[j] is smaller than B[j+1]
			maxj=j;			// assign maxj = j
	}

	for (k=maxj+1;k<N;k++) {  // loop for finding second condition
		if (B[maxj]<B[k])	  // tests whether B[maxj] is smaller than B[k]
			maxk=k;			  // assign maxk = k
	}

	temp=B[maxj];			// assign temp = B[maxj] to keep this value 
	B[maxj]=B[maxk];		// replace B[maxj] by B[maxk]
	B[maxk]=temp;			// replace B[maxk] by temp
							// B[maxj] and B[maxk] interchange
	for (j=N;(maxj+1)<(j-1);) { // loop for reverse B[j+1] to B[N-1]
		temp=B[maxj+1];			// assign temp = B[maxj+1] to keep value
		B[maxj+1]=B[j-1];		// replace B[maxj+1] by B[j-1]
		B[j-1]=temp;			// replace B[j-1] by temp
		maxj++;					// maxj+1
		j--;					// j--
	}						// reverse complete
}

int calculate(int A[N][N], int B[N])	// calculates the value from specific 
{										// position
	int i, v=1;				// i is controlling factor, v represents value

	for (i=0; i<N; i++)		// loop for requiring v
		v*=A[i][B[i]];		// v changes everytime pandita changes fac[N]
	return v;
}

int power(int x, int n)			// get x^n's value
{
	if (n==0)					// when the power n equals to 1
		return 1;				// send 1 back
	else						// if don't
		return x*power(x,n-1);	// recursive the function will until n=0
}
