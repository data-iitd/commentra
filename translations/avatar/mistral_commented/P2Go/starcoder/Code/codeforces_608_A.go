
// Importing the sys and input function from the standard library
import "fmt"

// Assigning the stdin readline function to a variable named input
var input = fmt.Scanf

// Reading the first line of input and storing the number of test cases and the target sum in variables n and s
var n, s int
input("%d %d\n", &n, &s)

// Initializing a variable c to 0
var c int

// Iterating through the test cases using a for loop
for i := 0; i < n; i++ {
    // Reading the start and end time of each activity from the input
    var f, t int
    input("%d %d\n", &f, &t)
    
    // Calculating the difference between the end time and the difference between the target sum and start time
    x := t - (s - f)
    
    // Updating the variable c with the maximum value of x calculated in the current iteration
    if x > c {
        c = x
    }
}

// Printing the final answer which is the sum of the target sum and the maximum overlap calculated
fmt.Printf("%d\n", s + c)

