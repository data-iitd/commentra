
// Initialize an empty list `L`
List<Integer> L = new ArrayList<Integer> ( );

// Read the first input, which is the number of elements to add to the list
Scanner sc = new Scanner ( System.in );
int n = sc.nextInt ( );

// Use a for loop to iterate through each integer in the input
for ( int i = 0; i < n; i++ ) {
    // Add `r` elements to the list `L` with the value `r`
    for ( int j = 0; j < sc.nextInt ( ); j++ ) {
        L.add ( r );
    }
    // Increment the value of `r` by 1 to prepare for the next iteration
    r++;
}

// Read the second input, which represents the indices of the elements to print from the list
Scanner sc2 = new Scanner ( System.in );
int m = sc2.nextInt ( );

// Use another for loop to iterate through each integer in the input
for ( int i = 0; i < m; i++ ) {
    // Print the element at the given index using the index as an offset from the beginning of the list
    System.out.println ( L.get ( sc2.nextInt ( ) - 1 ) );
}

