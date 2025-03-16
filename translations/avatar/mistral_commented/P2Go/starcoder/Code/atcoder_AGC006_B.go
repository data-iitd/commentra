// Define input variables
var N, X int
// Comment: Read input values N and X from the standard input

// Import "fmt" and "sort" packages
import (
    "fmt"
    "sort"
)
// Comment: Import fmt and sort packages

// Define a function calc that takes an integer x as an argument
func calc(x int) int {
// Define a nested function sub that takes an integer y and an optional debug argument
    func sub(y int, debug bool) int {
    // Define a nested function sub that takes an integer y and an optional debug argument

        if debug {
            fmt.Println("D", y)
        }
        // If debug is set to True, print the intermediate values of y

        for i := 0; i < len(y)-2; i++ {
            y[i] = sort.IntSlice(y[i:i+3]).Less(1)
        }
        // Sort and select the middle element from sublists of length 3 in y

        return y[0]
    }
    // Return the result of the sub function

    y := sub(x)
    // Calculate the result y of the sub function for the given input x

    if y == 2 {
        sub(x, true)
        fmt.Println("=", x)
    }
    // If the first element of y is 2, call the sub function recursively with x-1 and print x

    return y
}
// Return the first element of the y list

// Check if X is equal to 1 or N*2-1
if X == 1 || X == N*2-1 {
    fmt.Println("No")
} else {
// Else, X is neither 1 nor N*2-1
    fmt.Println("Yes")

// Calculate the list xs based on the value of X
    xs := make([]int, 0, N-1)
    if X == N*2-2 {
        for i := N-1; i >= 0; i-- {
            xs = append(xs, i)
        }
        for i := 0; i < N-1; i++ {
            xs = append(xs, i)
        }
    } else {
        for i := 0; i < N-3; i++ {
            xs = append(xs, i)
        }
        xs = append(xs, X+2, X-1, X, X+1)
        for i := N-3; i < N; i++ {
            xs = append(xs, i)
        }
    }

// Print each element of the list xs
    for _, x := range xs {
        fmt.Println(x)
    }
}
// Comment: Read input values N and X from the standard input

// Comment: Import fmt and sort packages

// Comment: Define a function calc that takes an integer x as an argument

// Comment: Define a nested function sub that takes an integer y and an optional debug argument

// Comment: If debug is set to True, print the intermediate values of y

// Comment: Sort and select the middle element from sublists of length 3 in y

// Comment: Return the result of the sub function

// Comment: If the first element of y is 2, call the sub function recursively with x-1 and print x

// Comment: Return the first element of the y list

// Comment: Check if X is equal to 1 or N*2-1

// Comment: Else, X is neither 1 nor N*2-1

// Comment: Calculate the list xs based on the value of X

// Comment: Print each element of the list xs

// Comment: Read input values N and X from the standard input

// Comment: Import fmt and sort packages

// Comment: Define a function calc that takes an integer x as an argument

// Comment: Define a nested function sub that takes an integer y and an optional debug argument

// Comment: If debug is set to True, print the intermediate values of y

// Comment: Sort and select the middle element from sublists of length 3 in y

// Comment: Return the result of the sub function

// Comment: If the first element of y is 2, call the sub function recursively with x-1 and print x

// Comment: Return the first element of the y list

// Comment: Check if X is equal to 1 or N*2-1

// Comment: Else, X is neither 1 nor N*2-1

// Comment: Calculate the list xs based on the value of X

// Comment: Print each element of the list xs

// Comment: Read input values N and X from the standard input

// Comment: Import fmt and sort packages

// Comment: Define a function calc that takes an integer x as an argument

// Comment: Define a nested function sub that takes an integer y and an optional debug argument

// Comment: If debug is set to True, print the intermediate values of y

// Comment: Sort and select the middle element from sublists of length 3 in y

// Comment: Return the result of the sub function

// Comment: If the first element of y is 2, call the sub function recursively with x-1 and print x

// Comment: Return the first element of the y list

// Comment: Check if X is equal to 1 or N*2-1

// Comment: Else, X is neither 1 nor N*2-1

// Comment: Calculate the list xs based on the value of X

// Comment: Print each element of the list xs

// Comment: Read input values N and X from the standard input

// Comment: Import fmt and sort packages

// Comment: Define a function calc that takes an integer x as an argument

// Comment: Define a nested function sub that takes an integer y and an optional debug argument

// Comment: If debug is set to True, print the intermediate values of y

// Comment: Sort and select the middle element from sublists of length 3 in y

// Comment: Return the result of the sub function

// Comment: If the first element of y is 2, call the sub function recursively with x-1 and print x

// Comment: Return the first element of the y list

// Comment: Check if X is equal to 1 or N*2-1

// Comment: Else, X is neither 1 nor N*2-1

// Comment: Calculate the list xs based on the value of X

// Comment: Print each element of the list xs

// Comment: Read input values N and X from the standard input

// Comment: Import fmt and sort packages

// Comment: Define a function calc that takes an integer x as an argument

// Comment: Define a nested function sub that takes an integer y and an optional debug argument

// Comment: If debug is set to True, print the intermediate values of y

// Comment: Sort and select the middle element from sublists of length 3 in y

// Comment: Return the result of the sub function

// Comment: If the first element of y is 2, call the sub function recursively with x-1 and print x

// Comment: Return the first element of the y list

// Comment: Check if X is equal to 1 or N*2-1

// Comment: Else, X is neither 1 nor N*2-1

// Comment: Calculate the list xs based on the value of X

// Comment: Print each element of the list xs

// Comment: Read input values N and X from the standard input

// Comment: Import fmt and sort packages

// Comment: Define a function calc that takes an integer x as an argument

// Comment: Define a nested function sub that takes an integer y and an optional debug argument

// Comment: If debug is set to True, print the intermediate values of y

// Comment: Sort and select the middle element from sublists of length 3 in y

// Comment: Return the result of the sub function

// Comment: If the first element of y is 2, call the sub function recursively with x-1 and print x

// Comment: Return the first element of the y list

// Comment: Check if X is equal to 1 or N*2-1

// Comment: Else, X is neither 1 nor N*2-1

// Comment: Calculate the list xs based on the value of X

// Comment: Print each element of the list xs

// Comment: Read input values N and X from the standard input

// Comment: Import fmt and sort packages

// Comment: Define a function calc that takes an integer x as an argument

// Comment: Define a nested function sub that takes an integer y and an optional debug argument

// Comment: If debug is set to True, print the intermediate values of y

// Comment: Sort and select the middle element from sublists of length 3 in y

// Comment: Return the result of the sub function

// Comment: If the first element of y is 2, call the sub function recursively with x-1 and print x

// Comment: Return the first element of the y list

// Comment: Check if X is equal to 1 or N*2-1

// Comment: Else, X is neither 1 nor N*2-1

// Comment: Calculate the list xs based on the value of X

// Comment: Print each element of the list xs

// Comment: Read input values N and X from the standard input

// Comment: Import fmt and sort packages

// Comment: Define a function calc that takes an integer x as an argument

// Comment: Define a nested function sub that takes an integer y and an optional debug argument

// Comment: If debug is set to True, print the intermediate values of y

// Comment: Sort and select the middle element from sublists of length 3 in y

// Comment: Return the result of the sub function

// Comment: If the first element of y is 2, call the sub function recursively with x-1 and print x

// Comment: Return the first element of the y list

// Comment: Check if X is equal to 1 or N*2-1

// Comment: Else, X is neither 1 nor N*2-1

// Comment: Calculate the list xs based on the value of X

// Comment: Print each element of the list xs

// Comment: Read input values N and X from the standard input

// Comment: Import fmt and sort packages

// Comment: Define a function calc that takes an integer x as an argument

// Comment: Define a nested function sub that takes an integer y and an optional debug argument

// Comment: If debug is set to True, print the intermediate values of y

// Comment: Sort and select the middle element from sublists of length 3 in y

// Comment: Return the result of the sub function

// Comment: If the first element of y is 2, call the sub function recursively with x-1 and print x

// Comment: Return the first element of the y list

// Comment: Check if X is equal to 1 or N*2-1

// Comment: Else, X is neither 1 nor N*2-1

// Comment: Calculate the list xs based on the value of X

// Comment: Print each element of the list xs

// Comment: Read input values N and X from the standard input

// Comment: Import fmt and sort packages

// Comment: Define a function calc that takes an integer x as an argument

// Comment: Define a nested function sub that takes an integer y and an optional debug argument

// Comment: If debug is set to True, print the intermediate values of y

// Comment: Sort and select the middle element from sublists of length 3 in y

// Comment: Return the result of the sub function

// Comment: If the first element of y is 2, call the sub function recursively with x-1 and print x

// Comment: Return the first ele