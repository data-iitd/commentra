// Define input variables
var N, X int
fmt.Scan(&N, &X)
// Comment: Read input values N and X from the standard input

// Import fmt module for formatting output
import "fmt"
// Comment: Import fmt module

// Define a function calc that takes an integer x as an argument
func calc(x int) int {

    // Define a nested function sub that takes an integer y and an optional debug argument
    sub := func(y int, debug bool) int {

        if debug {
            fmt.Println("D", y)
        }
        // If debug is set to True, print the intermediate values of y

        for len(y) > 1 {
            y = []int{y[1], y[2], y[3]}
            if debug {
                fmt.Println("D", y)
            }
        }
        // Sort and select the middle element from sublists of length 3 in y

        return y[1]
    }
    // Return the result of the sub function

    y := sub(x, false)
    // Calculate the result y of the sub function for the given input x

    if y == 2 {
        sub(x-1, true)
        fmt.Println("=", x)
    }
    // If the first element of y is 2, call the sub function recursively with x-1 and print x

    return y
}
// Return the first element of the y list

if X == 1 || X == N*2-1 {
// Check if X is equal to 1 or N*2-1

    fmt.Println("No")
// If it is, print "No"

} else {
// Else, X is neither 1 nor N*2-1

    fmt.Println("Yes")
// Print "Yes"

    if X == N * 2 - 2 {
        xs := make([]int, N-1)
        for i := 0; i < N-1; i++ {
            xs[i] = N-1 - i
        }
        for i := 0; i < N-1; i++ {
            xs[i] = i + 1
        }
    } else {
        ys := make([]int, N*2-4)
        for i := 0; i < N*2-4; i++ {
            ys[i] = i + 1
        }
        xs := make([]int, N*2-2)
        for i := 0; i < N-3; i++ {
            xs[i] = ys[i]
        }
        xs[N-3] = X + 2
        xs[N-2] = X - 1
        xs[N-1] = X
        xs[N] = X + 1
        for i := 0; i < N-3; i++ {
            xs[N+1+i] = ys[N-3+i]
        }
    }
    // Calculate the list xs based on the value of X

    for _, x := range xs {
        fmt.Println(x)
    }
// Print each element of the list xs

}
// Comment: End of code

Translate the above Go code to C++ and end with comment "