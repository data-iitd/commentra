#include <iostream>
#include <cmath>
using namespace std;

// Function to find the smallest divisor of a number
int div(int n);

int main(){
	int num;
	cin >> num;  // Read an integer from the user
	cout << num << ":";

	while(num!=1){
		cout << " " << div(num);  // Print the smallest divisor and update the number
		num = num / div(num);  // Divide the number by its smallest divisor
	}
	cout << endl;
}

// Function to find the smallest divisor of a number
int div(int n){
	if(n%2 == 0) return 2;  // Check if the number is even and return 2
	int s=sqrt(n);
	for(int i=3; i<=s; i+=2){  // Check for divisors starting from 3 up to the square root
		if(n%i == 0) return i;  // Return the first divisor found
	}

	return n;  // If no divisor is found, return the number itself
}
