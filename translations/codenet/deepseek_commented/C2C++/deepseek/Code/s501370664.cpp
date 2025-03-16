#include <iostream>  // Include iostream for cin and cout
#include <vector>    // Include vector for dynamic array
#include <cstdlib>   // Include cstdlib for calloc-like allocation

using namespace std; // Use the standard namespace

vector<bool> flag;  // Declare a global vector to keep track of prime numbers

// Function to mark non-prime numbers up to a given number 'num'
void prime(int num){
	int i,j;  // Declare loop variables

	flag.assign(num+1, false);  // Allocate memory for the flag vector

	for(i = 2;i*i <= num;i++){  // Iterate to mark non-prime numbers
		if(!flag[i]){  // If 'i' is a prime number
			for(j = 2;i*j <= num;j++){  // Mark multiples of 'i' as non-prime
				flag[i*j] = true;
			}
		}
	}
}

// Main function to read an integer, calculate pairs of primes summing to 'n', and print the result
int main(){
	int n,i,cnt;  // Declare variables to store input, loop index, and count of pairs

	prime(50000);  // Call the prime function to mark non-prime numbers up to 50000

	while(true){  // Infinite loop to read input until 'n' is zero
		cin >> n;  // Read an integer 'n' from the user
		if(n == 0){
			break;  // Exit the loop if 'n' is zero
		}
		i = 2;  // Initialize the starting prime number
		cnt = 0;  // Initialize the count of pairs
		while(i*2 <= n){  // Loop to find pairs of primes summing to 'n'
			if(!flag[i] && !flag[n-i]){  // Check if both 'i' and 'n-i' are prime
				cnt++;  // Increment the count if a valid pair is found
			}
			i++;  // Move to the next potential prime number
		}
		cout << cnt << endl;  // Print the count of pairs of primes summing to 'n'
	}

	return 0;  // Return 0 to indicate successful execution
}
