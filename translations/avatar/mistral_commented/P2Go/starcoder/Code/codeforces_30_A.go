// Function to find a number X raised to the power n such that A * X^n equals B
func task4(A, B, n int) int {

    // Iterate through all possible values of X from -1000 to 1000
    for X := -1000; X <= 1000; X++ {

        // Check if the condition A * X^n equals B is satisfied
        if A * (X ** n) == B {

            // If the condition is satisfied, return the value of X
            return X
        }
    }

    // If no solution is found, return a message indicating that
    return "No solution"
}

// Get input values of A, B, and n from the user
var A, B, n int
fmt.Scanf("%d %d %d", &A, &B, &n)

// Call the function and print the result
fmt.Println(task4(A, B, n))

