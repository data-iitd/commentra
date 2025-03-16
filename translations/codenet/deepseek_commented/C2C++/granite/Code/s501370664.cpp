
#include <iostream> // Include standard input/output library for cout and cin
#include <cmath>    // Include standard library for square root calculation (sqrt)
#include <cstring>  // Include standard library for memory allocation (calloc)

using namespace std; // Use the standard namespace

int *flag;         // Declare a global integer array to keep track of prime numbers

// Function to mark non-prime numbers up to a given number 'num'
void prime(int num){
	int i,j;        // Declare loop variables

	flag = (int *)calloc(sizeof(int),num+1); // Allocate memory for the flag array

	for(i = 2;i*i <= num;i++){ // Iterate to mark non-prime numbers
		if(flag[i] == 0){     // If 'i' is a prime number
			for(j = 2;i*j <= num;j++){ // Mark multiples of 'i' as non-prime
				flag[i*j] = 1;
			}
		}
	}
}

// Main function to read an integer, calculate pairs of primes summing to 'n', and print the result
int main(){
	int n,i,cnt; // Declare variables to store input, loop index, and count of pairs

	prime(50000); // Call the prime function to mark non-prime numbers up to 50000

	while(1){ // Infinite loop to read input until 'n' is zero
		cin >> n; // Read an integer 'n' from the user
		if(n == 0){
			break; // Exit the loop if 'n' is zero
		}
		i = 2; // Initialize the starting prime number
		cnt = 0; // Initialize the count of pairs
		while(i*2 <= n){ // Loop to find pairs of primes summing to 'n'
			if(!flag[i] &&!flag[n-i]){ // Check if both 'i' and 'n-i' are prime
				cnt++; // Increment the count if a valid pair is found
			}
			i++; // Move to the next potential prime number
		}
		cout << cnt << endl; // Print the count of pairs of primes summing to 'n'
	}

	return 0; // Return 0 to indicate successful execution
}


