
#include <iostream>
#include <cstdlib>

using namespace std;

// Declare a flag array to keep track of prime numbers
int *flag;

// Function to find prime numbers up to a given limit
void prime(int num){
	int i,j;

	// Allocate memory for flag array of size num+1
	flag = (int *)calloc(sizeof(int),num+1);

	// Loop through numbers from 2 to num
	for(i = 2;i*i <= num;i++){
		// If a number is not marked as composite, mark all its multiples as composite
		if(flag[i] == 0){
			for(j = 2;i*j <= num;j++){
				flag[i*j] = 1;
			}
		}
	}
}

int main(){
	int n,i,cnt;

	// Call prime function to find prime numbers up to 50000
	prime(50000);

	// Loop until user inputs 0
	while(1){
		// Read user input for number n
		cin >> n;
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
			if(!flag[i] &&!flag[n-i]){
				cnt++;
			}
			// Increment i for next iteration
			i++;
		}
		// Print the result
		cout << cnt << endl;
	}

	// Return 0 to indicate successful execution
	return 0;
}

