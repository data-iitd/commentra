package main // Step 1: Define the main package.

import ( // Step 2: Import necessary packages.
    "fmt"
    "math"
)

func main() { // Step 3: Implement the main function.
    var n int // Step 4: Declare a variable to read the size of the array.
    fmt.Scan(&n) // Step 5: Read the size of the array from the user.
    
    arr := make([]int64, n) // Step 6: Create a slice to store the elements of the array.
    for i := 0; i < n; i++ { // Step 7: Read the elements of the array from the user.
        fmt.Scan(&arr[i])
    }
    
    answer := int64(math.Abs(float64(arr[0]))) // Step 8: Initialize a variable to store the answer.
    for i := 1; i < n; i++ { // Step 9: Calculate the absolute difference between consecutive elements and add it to the answer.
        answer += int64(math.Abs(float64(arr[i] - arr[i-1])))
    }
    
    fmt.Println(answer) // Step 10: Print the final answer.
}

// <END-OF-CODE>
