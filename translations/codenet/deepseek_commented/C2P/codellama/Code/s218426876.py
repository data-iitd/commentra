#include <string.h>
#include<stdio.h>
int main(void)
{
	int i,sum=0;
	int flag=0;
	char x[1002]; // Declare a character array to store the input string
	scanf("%s",x); // Read the first string from the input
	do{
		
		for(i=0;i<1002;i++){ // Loop through each character in the string
			if(x[i]==0){ // Check if the current character is the null terminator
				printf("%d\n",sum); // Print the sum of the digits and exit the loop
				break;
			}else{
				sum+=x[i]-0x30; // Convert the character to its corresponding digit and add it to the sum
			}
		}
		sum=0; // Reset the sum for the next string
		scanf("%s",x); // Read the next string from the input
	}while(x[0]!=0x30); // Continue the loop until a string starting with '0' is encountered

	return 0 ;
}