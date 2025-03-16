#include <cstdio>
#include <algorithm>
using std::sort; // include the sort function from the algorithm library

int main(void) // main function declaration
{
	int *a, *b, i, N; // declare pointers a and b, integer i and integer N
	int frontHalf, backHalf; // declare integers frontHalf and backHalf

	scanf("%d",&N); // read the number of elements from the standard input
	a = new int [N]; // allocate memory for an array of size N and assign the address to pointer a
	b = new int [N]; // allocate memory for an array of size N and assign the address to pointer b

	for(i=0;i<N;i++) // iterate through the array a and assign each element to b
	{
		scanf("%d",(a+i)); // read an integer from the standard input and assign it to the ith position in array a
		b[i] = a[i]; // copy the value of the ith position in array a to the ith position in array b
	}

	sort(b, b+N); // sort the elements in array b in ascending order

	frontHalf = b[N/2-1]; // assign the middle value of the first half of the sorted array b to frontHalf
	backHalf = b[N/2]; // assign the middle value of the second half of the sorted array b to backHalf

	delete [] b; // deallocate the memory allocated for array b

	for(i=0;i<N;i++) // iterate through the array a and print the appropriate middle value based on the condition
	{
		if(a[i]<backHalf) // if the value at the ith position in array a is less than the middle value of the second half of the sorted array b
			printf("%d\n",backHalf); // print the middle value of the second half of the sorted array b
		else
			printf("%d\n",frontHalf); // print the middle value of the first half of the sorted array b
	}

	delete [] a; // deallocate the memory allocated for array a

	return 0; // indicate successful termination of the program
}
