
#include<stdio.h>
// Include the standard input/output library

int main(void){
// Function main starts the execution of the program
int i, n, tmp; // Declare variables i, n, and tmp
long long int min = 1000000, max = -1000000, sum = 0; // Initialize variables min, max, and sum

scanf("%d",&n);
// Read the number of integers to be entered from the user
printf("Enter the number of integers: ");
for(i=0;i<n;i++){
// Use a for loop to read and process each integer
scanf("%d",&tmp);
// Read the next integer from the user and store it in variable tmp
if(min>tmp)min=tmp;
// If the current integer is smaller than the current minimum, update the minimum
if(max<tmp)max=tmp;
// If the current integer is larger than the current maximum, update the maximum
sum+=tmp;
// Add the current integer to the sum
}

printf("%ld %ld %ld\n",min,max,sum);
// Print the minimum, maximum, and sum of the entered integers
return 0;
// Function main ends with a return statement
}