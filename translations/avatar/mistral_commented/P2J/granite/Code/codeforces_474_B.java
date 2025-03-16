

// Initialize an empty list `L`
List < Integer > L = new ArrayList < > ( ) ;

// Read the first input, which is the number of elements to add to the list
Scanner in = new Scanner ( System. in ) ;
int n = in.nextInt ( ) ;

// Use a for loop to iterate through each integer in the input
for ( int k = 0 ; k < n ; k ++ ) {
    // Read the next integer from the input
    int r = in.nextInt ( ) ;
    // Add `r` elements to the list `L` with the value `r`
    for ( int i = 0 ; i < r ; i ++ )
        L. add ( r ) ;
}

// Read the second input, which represents the indices of the elements to print from the list
n = in.nextInt ( ) ;

// Use another for loop to iterate through each integer in the input
for ( int j = 0 ; j < n ; j ++ ) {
    // Read the next integer from the input
    int i = in.nextInt ( ) - 1 ;
    // Print the element at the given index using the index as an offset from the beginning of the list
    System. out. println ( L. get ( i ) ) ;
}

