package main // Defining the main package

import (
    "fmt" // Importing the fmt package for formatted I/O
    "sort" // Importing the sort package for sorting slices
)

func main() { // Defining the main function that is executed when the program runs
    var n int
    fmt.Scan(&n) // Reading the number of elements in the list from the standard input

    list := make([]int64, n) // Creating a slice of int64 type to store n elements

    for i := 0; i < n; i++ { // Iterating through the input to add each element to the slice
        fmt.Scan(&list[i]) // Reading each long integer into the slice
    }

    odd := []int64{} // Creating an empty slice of int64 type to store odd numbers
    sum := int64(0) // Initializing the sum variable to 0

    for _, i := range list { // Iterating through each element in the slice
        if i%2 == 0 { // Checking if the current element is even
            sum += i // Adding the even number to the sum
        } else {
            odd = append(odd, i) // Adding the odd number to the odd slice
        }
    }

    sort.Slice(odd, func(i, j int) bool { // Sorting the odd slice in ascending order
        return odd[i] < odd[j]
    })

    for _, i := range odd { // Iterating through each odd number in the sorted odd slice
        sum += i // Adding the odd number to the sum
    }

    if len(odd)%2 != 0 { // Checking if the size of the odd slice is odd
        sum -= odd[0] // Subtracting the first odd number if the size is odd
    }

    fmt.Println(sum) // Printing the final sum to the standard output
}

// <END-OF-CODE>
