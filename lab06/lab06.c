/* EE231002 Lab06. Latin Square
 * 104061210, Hong-De Jheng
 * Date:2015/11/2
 */

#include <stdio.h>
#if !defined(N)
#define N 3
#endif

int n=1;					//n represents number of latin squares
int A[N][N],temp[N][N];		/*A[N][N] is a latin square, temp[N][N] is a 
							  temporary latin square to create new one*/
void print_array()			//fuction of print out latin square
{
	int i,j;				//factors to implement the function
	printf("Latin Square %d\n", n++);    //print out which latin square is now
	printf(" ");			//print a white space
	for (i=0; i<N; i++) {	//control column
		for (j=0; j<N; j++) { 			//control row
			printf(" %c", A[i][j]); 	//print latin square
		}
		printf("\n");		//new line
		if (i != (N-1))		//don't print another extra space when it runs to
			printf(" ");	//the last row 
	}
}

void create_array(int row, int time)  /*fuction of creating latin square,
										this function fills A first then B,etc*/
{
	int i, j;				//factors to implement the function
	int x;					//factors to judging whether latin sqaure repeats
	char ch='A';			//latin square's character
	
	if (row==N) {			//judging whether the function runs to the last row
		create_array(0,time+1);	  
	//recursive the function and changing time to time+1 
		return ;
	}
	if (time>N) {			//judging whether the fill-in is over the limit
		print_array();		//print out latin square
		return ;
	}							
	for (i=0; i<N; i++) {	//control row
		x=0;				//assign x=0
		for (j=1; j<time; j++) {  	 /*loop for checking the same column 
									   from second row*/
			if (temp[j][row]==(i+ch-1)) {  
	//checking whether the latin square is filled with the previous letter
				x++;		//if does,x+1
			}
		}
		if (x==0) {			
	//if x equals to 0,it means that this column doesn't have previous letter
			for (j=0; j<row; j++) { //then check the same row from first column
				if (temp[time][j]==(i+ch-1)) { 
	//checking whrther the latin square is filled with the previous letter
					x++;   //if does,x+1
				}
			}
		}
		if (x==0) {
	//if x equals to 0,it means that this row doesn't have previous letter
			temp[time][row]=(i+ch-1);  
   //assign the temporary latin square's specific position to the previos letter
			A[row][i]=(time+ch-1);
	/*assign the present latin square's first position to the present letter
	  (becuase time starts from one,first letter will start from A)*/
			create_array(row+1,time); 
	//recursive the function and changing row to row+1
		}
	}
}

int main(void)
{
	create_array(0,1);     //run the function
	printf("Total number of Latin Squares found is %d\n", n-1); //print result
	return 0;
}
