// Importing the fmt module
import "fmt"

// Reading the first line of input which contains the number of elements 'n' in the list 'w'
var n int
fmt.Scan(&n)

// Initializing an empty list 'd' to store the indices of the elements that satisfy the condition
var d []int

// Iterating through each element 'i' in the list 'w'
for i := 0; i < n; i++ {
    // Calculating the average of the remaining sum of elements after removing the current element 'w[i]'
    // and checking if it's equal to the current element 'w[i]'
    if (x - w[i])/(n-1) == w[i] {
        // If the condition is true, append the index 'i+1' to the list 'd'
        d = append(d, i+1)
    }
}

// Printing the length of the list 'd'
fmt.Println(len(d))

// Printing the elements of the list 'd' separated by a space
fmt.Println(strings.Join(d, " "))

// End of code
