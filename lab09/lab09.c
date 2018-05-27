/* EE231002 Lab09. Word Processing
 * 104061210, Hong-De Jheng
 * Date:2015/11/23
 */

#include <stdio.h>				//directive
#include <string.h>

int N;							//N is the number of characters in a line
void printLine(char *para, int len);
								//printLine help us print words
int main(int argc, char *argv[])
{ 
	char s[650];				//s is used to store string
	int x=1, i;					//x determine if we should stop
								//i is used in loop
	N = atoi(argv[1]);			//get N by command-line argument
	while (x){
		i=-1;					//let i=-1
		do{				
			i++;
			s[i]=getchar();				//read the string
		} while (s[i] != '\n');			//once we read 'new line' we stop
		s[i+1] = '\0';					//use '\0' to end the string
		if (strncmp(s, "EOF", 3) == 0)	//if we read EOF ,we don't print
			x=0;
		if (x)
			printLine(s, N);			//call printLine
	}
	return 0;							//the program end
}

void printLine(char *para, int len)
{
	int num=4;							//num is hoe many characters
										//we have print
	printf("    ");						//tab
	for (;*para != '\0'; para++){		
		num++;							//once we want print a character num+1
		if (num == 1 && *para == ' ')	//if ' ' is the first character in a
			para++;						//line, we print the next character
		printf("%c", *para);			//print the character
		if(strlen(para) >= len){		
			if (*para == ' ' && *(para+len-num+1) != ' '){
				if (num != len){
					printf(" ");		//add ' ' to avoid that we cut a word
					num++;				//num + 1
				}
			}
		}
		if (num == len){				//once we print last character
			num = 0;					//let num = 0
			printf("\n");				//start the new line
		}
	}
}
