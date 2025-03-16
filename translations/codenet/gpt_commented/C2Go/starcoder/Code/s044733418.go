package main

import "fmt"

// compare is a function that returns an integer comparing two integers
func compare(a, b int) int {
    // Return the difference between b and a for descending order
    return b - a
}

func main() {
    // Declare an array of integers and a variable for iteration
    var array [10]int
    var i int

    // Read 10 integers from standard input into the array
    for i = 0; i!= 10; i++ {
        fmt.Scanf("%d", &array[i])
    }

    // Sort the array in descending order using qsort and the compare function
    qsort(array[:], 10, compare)

    // Print the first 3 elements of the sorted array
    for i = 0; i!= 3; i++ {
        fmt.Println(array[i])
    }
}

