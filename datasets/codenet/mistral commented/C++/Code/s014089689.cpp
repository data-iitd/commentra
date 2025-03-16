
#include<iostream> // Include the iostream library for input and output operations
using namespace std; // Use the standard namespace for easier access to iostream functions

int main(){ // Beginning of the main function
	int n; // Declare an integer variable 'n' to store the size of the string
	cin>>n; // Read the size of the string from the standard input
	string s; // Declare a string variable 's' to store the string
	cin>>s; // Read the string from the standard input
	int cnt=0; // Initialize a counter variable 'cnt' to 0

	// Beginning of the first for loop
	for(int i=0;i<n;i++){ // Loop through each character in the string 's'
		cnt++; // Increment the counter variable 'cnt'
		int j=i+1; // Initialize a variable 'j' to check for the next character

		// Beginning of the inner for loop
		for(;j<n;j++){ // Compare the current character with the next characters in the string
			if(s[i]!=s[j]){ // If the current character is not equal to the next character
				break; // Exit the inner for loop
			}
		}
		i=j-1; // If the current character is repeated, update the index 'i' to the previous index
	}

	// Output the result
	cout<<cnt<<endl; // Print the value of the counter variable 'cnt' to the standard output
}