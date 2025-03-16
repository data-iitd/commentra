

package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

func main() {
    // Creating a scanner object for reading input from the standard input
    in := bufio.NewReader ( os.Stdin )
    // Creating a writer object for writing output to the standard output
    out := bufio.NewWriter ( os.Stdout )

    // Reading the number of elements in the list from the input
    n, _ := strconv.Atoi ( strings.TrimSpace ( readLine ( in ) )

    // Creating a slice of size 'n' to store the elements
    list := make ( []int, n )

    // Reading 'n' elements from the input and adding them to the slice
    for i := 0 ; i < n ; i ++ {
        list [ i ], _ = strconv.Atoi ( strings.TrimSpace ( readLine ( in ) )
    }

    // Sorting the slice in ascending order using sort.Ints() function
    sort.Ints ( list )

    // Initializing a variable 'c' to keep track of the number of distinct elements
    c := 1

    // Iterating through the slice to find the number of distinct elements
    for i := 0 ; i < n ; i ++ {
        // If the current element is greater than or equal to the current count 'c', increment the count
        if list [ i ] >= c {
            c ++
        }
    }

    // Writing the result to the output
    fmt.Fprintln ( out, c )

    // Flushing the writer object to write the output to the standard output
    out.Flush ( )

    // Debugging function to print the deep toString representation of an object
    func debug ( obj...interface{} ) {
        fmt.Fprintln ( os.Stderr, obj... )
    }

    // Function to read a line from the input
    func readLine ( in * bufio.Reader ) string {
        buf, _ := in.ReadString ( '\n' )
        return strings.TrimSpace ( buf )
    }
}

Translate the above Go code to C++ and end with comment "