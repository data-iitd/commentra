
package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Read the number of elements N from the standard input
    N, _ := strconv.Atoi(os.Args[1])

    // Create an integer array A of size N to store the elements
    A := make([]int, N)

    // Use a for loop to read each element from the standard input and store it in the corresponding index of the array A
    for i := 0; i < N; i++ {
        A[i], _ = strconv.Atoi(os.Args[i+2])
    }

    // Use the sort.Ints() function to sort the elements in the array A in ascending order
    sort.Ints(A)

    // Initialize two variables, min and max, to store the minimum and maximum elements in the array A, respectively
    min := A[0]
    max := A[N-1]

    // Use a for-each loop to iterate through each element in the array A and perform some checks
    for _, value := range A {
        if value == min { // If the current element is equal to the minimum element min, increment the variable mins by 1
            mins++
        }
        if value == max { // If the current element is equal to the maximum element max, increment the variable maxs by 1
            maxs++
        }
    }

    // Check if the minimum and maximum elements are the same
    if min == max {
        result := (max - min) + 1 // Calculate the difference between the minimum and maximum elements, plus 1
        result *= mins             // Multiply the result by the number of occurrences of the minimum element
        result -= mins * (mins - 1) / 2 // Subtract the number of combinations of pairs of minimum elements
        fmt.Println(result) // Print the output
    } else {
        result := (max - min) // Calculate the difference between the minimum and maximum elements
        result *= mins         // Multiply the result by the number of occurrences of the minimum element
        result *= maxs         // Multiply the result by the number of occurrences of the maximum element
        fmt.Println(result) // Print the output
    }
}

// Define a static debug method to print the contents of an array or other objects for debugging purposes
func debug(obj ...interface{}) {
    fmt.Println(strings.Join(strings.Fields(fmt.Sprint(obj)), " "))
}

