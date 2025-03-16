
// Function to print the first n-1 elements of an array
void white(int n,int A[]){
	int i;
	// Loop to print the first n-1 elements of the array
	for(i=0;i<n-1;i++){
		System.out.print(A[i]+" ");
	}
	// Print the last element of the array
	System.out.println(A[i]);
}

// Function to implement insertion sort algorithm
void insertionsort(int n,int A[]){
	int i,j,a;
	// Loop to sort the array using insertion sort algorithm
	for(i=0;i<n;i++){
		// Inner loop to find the position of the current element in sorted array
		for(j=0;j<i;j++){
			// Swap if current element is smaller than the previous one
			if(A[i]<A[j]){
				// Swap the elements
				a=A[i];A[i]=A[j];A[j]=a;
			}
		}
		// Call the white function to print the sorted array after each iteration
		white(n,A);
	}
}

// Main function to take input and call the insertion sort function
public static void main(String[] args) {
	int i,n,A[];
	// Take the size of the array as input
	Scanner sc=new Scanner(System.in);
	n=sc.nextInt();
	// Take the elements of the array as input
	A=new int[n];
	for (i = 0; i < n; i++) {
		A[i]=sc.nextInt();
	}
	// Call the insertion sort function to sort the array
	insertionsort(n,A);

	// Return 0 to indicate successful execution of the program
	System.out.println("