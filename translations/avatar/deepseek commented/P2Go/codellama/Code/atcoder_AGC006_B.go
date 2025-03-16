// Read N and X from input
n, x := [ int ( _ ) for _ in input ( ).split ( ) ]

// Import the permutations function from itertools
from itertools import permutations

// Define the calc function which processes a list x
func calc ( x []int ) int {
    // Define a nested sub function within calc for further processing
    func sub ( y []int , debug bool ) []int {
        // Print the current state of y if debug mode is on
        if debug {
            fmt.Println ( "D" , y )
        }
        // Reduce y by repeatedly taking triplets, sorting them, and keeping the middle element
        for len ( y ) > 1 {
            y = [ sorted ( y [ i : i + 3 ] ) [ 1 ] for i in range ( len ( y ) - 2 ) ]
            // Print the current state of y if debug mode is on
            if debug {
                fmt.Println ( "D" , y )
            }
        }
        // Return the final single element of y
        return y
    }
    // Process the input list x using sub function
    y := sub ( x )
    // Check if the final element of y is 2
    if y [ 0 ] == 2 {
        // Call sub again with debug mode on and print the result
        sub ( x , true )
        fmt.Println ( "=" , x )
    }
    // Return the first element of the final y
    return y [ 0 ]
}

// Check if X is 1 or N * 2 - 1, print "No" if true
if x == 1 or x == n * 2 - 1 {
    fmt.Println ( "No" )
} else {
    // Print "Yes" if X is not 1 or N * 2 - 1
    fmt.Println ( "Yes" )
    // Construct the list xs based on the value of X
    if x == n * 2 - 2 {
        xs := list ( range ( n - 1 , x + 2 ) ) + list ( range ( 1 , n - 1 ) )
    } else {
        ys := list ( range ( 1 , x - 1 ) ) + list ( range ( x + 3 , n * 2 ) )
        xs := ys [ : n - 3 ] + [ x + 2 , x - 1 , x , x + 1 ] + ys [ n - 3 : ]
    }
    // Print each element of xs
    for x in xs {
        fmt.Println ( x )
    }
}

