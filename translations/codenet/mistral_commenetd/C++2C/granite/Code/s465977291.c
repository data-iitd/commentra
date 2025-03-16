

#include<stdio.h>
#include<math.h>

int main(){
	// Read two integers 'n' and 'd' from the standard input
	int n, d;
	scanf("%d %d", &n, &d);

	// Calculate the value of 'a' as 'd' multiplied by 2 and adding 1
	double a = d*2+1;

	// Use the ceil function to find the smallest integer greater than or equal to the result of dividing 'n' by 'a'
	// Print the result to the standard output
	printf("%.0lf\n", ceil(n/a));

	// Return 0 to indicate successful execution of the program
	return 0;
}

