
#include <string.h> // Include string header file for string manipulation functions
#include<iostream> // Include standard input/output library for input/output operations

using namespace std; // Use standard namespace

int main(void) // Function definition for main function
{
	int i; // Initialize integer variable 'i'
	int sum=0; // Initialize integer variable'sum' to zero
	int flag=0; // Initialize integer variable 'flag' to zero
	char x[1002]; // Initialize character array 'x' of size 1002

	// Read a string from standard input and store it in 'x' array
	cout<<"Enter a string of digits separated by spaces or newline: ";
	cin>>x;

	do{ // Begin a do-while loop

		// Initialize sum to zero before processing each string
		sum=0;

		// Process each character in the string 'x'
		for(i=0;i<1002;i++){
			// Check if current character is end-of-string marker
			if(x[i]==0){
				// If so, print the sum of digits in the previous string and exit the loop
				cout<<"Sum of digits in previous string: "<<sum<<endl;
				break;
			}else{
				// Otherwise, add the ASCII value of the character to the sum (subtracting 0x30 to convert ASCII to integer)
				sum+=x[i]-0x30;
			}
		}

		// Initialize sum to zero for next iteration of the loop
		sum=0;

		// Read next string from standard input
		cout<<"Enter a string of digits separated by spaces or newline: ";
		cin>>x;

	}while(x[0]!=0x30); // Continue the loop until the first character of the input string is '0'

	return 0 ; // Function returns 0 upon successful execution
}

