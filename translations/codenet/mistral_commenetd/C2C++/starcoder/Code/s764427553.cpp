
#include<bits/stdc++.h>

// Main function starts here
int main(){
	// Initialize an array 'prime' of size MAX_V+1 with all elements set to 1
	const int MAX_V=999999;
	int prime[MAX_V+1];
	for(int i=0;i<=MAX_V;i++){
		prime[i]=1; // Initialize all elements to 1
	}

	// Sieve of Eratosthenes algorithm to find prime numbers
	for(int i=2;i<=MAX_V;i++){
		// If i is prime, mark all its multiples as composite
		if(prime[i]){
			for(int k=i*i;k<=MAX_V;k+=i){
				prime[k]=0;
			}
		}
	}

	// Set prime[0] and prime[1] to 0 as they are not prime numbers
	prime[0]=0;
	prime[1]=0;

	// Initialize a counter 'count' for the number of test cases
	int count=0;

	// Read input test cases until end of file is reached
	while(scanf("%d",&n)!=EOF){
		// Increment the counter for each test case
		count++;

		// Initialize a counter 'cnt' to count the number of prime digits in n
		int cnt=0;

		// Iterate through each digit of n from right to left and count the number of prime digits
		for(int i=n;i>0;i--){
			if(prime[i]==1){
				cnt++; // Increment the counter if the digit is prime
			}
		}

		// Print the result for the current test case
		printf("%d\n",cnt);

		// Break the loop if the required number of test cases have been processed
		if(count==30)break;
	}

	// Return 0 to indicate successful execution of the program
	return 0;
}

