
// Initialize an empty list `L`
List<Integer> L = new ArrayList<Integer> ( );

// Read the first input, which is the number of elements to add to the list
Scanner input = new Scanner ( System.in );
int n = input.nextInt ( );

// Use a for loop to iterate through each integer in the input
for ( int k = 0; k < n; k++ ) {
    // Add `r` elements to the list `L` with the value `r`
    for ( int r = 0; r < input.nextInt ( ); r++ ) {
        L.add ( r );
    }
    // Increment the value of `r` by 1 to prepare for the next iteration
    r++;
}

// Read the second input, which represents the indices of the elements to print from the list
int m = input.nextInt ( );

// Use another for loop to iterate through each integer in the input
for ( int j = 0; j < m; j++ ) {
    // Print the element at the given index using the index as an offset from the beginning of the list
    System.out.println ( L.get ( input.nextInt ( ) - 1 ) );
}

