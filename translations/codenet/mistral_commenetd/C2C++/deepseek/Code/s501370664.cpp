#include <iostream>
#include <vector>
#include <cmath>

// Declare a flag array to keep track of prime numbers
std::vector<bool> flag;

// Function to find prime numbers up to a given limit
void prime(int num){
	int i,j;

	// Allocate memory for flag array of size num+1
	flag.assign(num+1, false);

	// Loop through numbers from 2 to num
	for(i = 2;i*i <= num;i++){
		// If a number is not marked as composite, mark all its multiples as composite
		if(!flag[i]){
			for(j = 2;i*j <= num;j++){
				flag[i*j] = true;
			}
		}
	}
}

int main(){
	int n,i,cnt;

	// Call prime function to find prime numbers up to 50000
	prime(50000);

	// Loop until user inputs 0
	while(true){
		// Read user input for number n
		std::cin >> n;
		// Break the loop if user inputs 0
		if(n == 0){
			break;
		}
		// Initialize i and cnt to 0
		i = 2;
		cnt = 0;
		// Loop through numbers from 2 to square root of n
		while(i*i <= n){
			// If i and n-i are both prime, increment cnt
			if(!flag[i] && !flag[n-i]){
				cnt++;
			}
			// Increment i for next iteration
			i++;
		}
		// Print the result
		std::cout << cnt << std::endl;
	}

	// Return 0 to indicate successful execution
	return 0;
}
