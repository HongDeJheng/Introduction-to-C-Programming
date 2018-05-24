/* EE231002 Lab05. Permutations
 * 1040612100, Hong-De Jheng
 * 2015/10/26
 */

#include <stdio.h>
#define N 7

int main(void)
{
	int A[N],s=1,i,j,k,n=1,maxj,maxk,temp;
	/* A[N] represents permutations,s represents sum of number of pemutations,
	   i,j,k,maxj,maxk,temp are factors to implement Pandita's algorithm,
	   n represents number of premutations */

	printf("permutation #1:");  // print out "permutations #1:"
	for (i=0;i<N;i++) {		    // loop for assign A[i]'s value and print it out
		A[i]=i+1;				// assign A[i]'s value = i+1
		s*=A[i];				// s=s*(A[0]*...*A[N-1])
		printf(" %d", A[i]);	// print out all A[i]
	}
	printf("\n");				// new line
	n++;						// n+1
	while (n!=s+1) {			// loop while n not equal to sum
		for (j=0;j<N-1;j++) {	/* loop for finding first condition of Pandita's
								   algorithm.j<N-1 because A[j+1] bellow can't 
								   be A[N] */
			if (A[j]<A[j+1])	// tests whether A[j] is smaller than A[j+1]
				maxj=j;			// assign maxj = j
		}

		for (k=maxj+1;k<N;k++) {  // loop for finding second condition
			if (A[maxj]<A[k])	  // tests whether A[maxj] is smaller than A[k]
				maxk=k;			  // assign maxk = k
		}

		temp=A[maxj];			// assign temp = A[maxj] to keep this value 
		A[maxj]=A[maxk];		// replace A[maxj] by A[maxk]
		A[maxk]=temp;			// replace A[maxk] by temp
								// A[maxj] and A[maxk] interchange
		for (j=N;(maxj+1)<(j-1);) { // loop for reverse A[j+1] to A[N-1]
			temp=A[maxj+1];			// assign temp = A[maxj+1] to keep value
			A[maxj+1]=A[j-1];		// replace A[maxj+1] by A[j-1]
			A[j-1]=temp;			// replace A[j-1] by temp
			maxj++;					// maxj+1
			j--;					// j--
		}						// reverse complete
		printf("permutation #%d:", n); // print out the next permutation number
		for (i=0;i<N;i++)		// loop for print out permutation
			printf(" %d", A[i]);// print out new permutation
		n++;					// n+1
		printf("\n");			// new line
	}
	printf("  Total number of permutations is %d\n", n-1);	
	/* print out total number of permutations,n-1 because line 51 n+1 whether
	   the loop's condition is correspond or not */
	return 0;
}
