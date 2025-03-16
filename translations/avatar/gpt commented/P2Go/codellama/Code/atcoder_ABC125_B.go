// Read the number of elements
N, _ := fmt.Scan(&N)

// Read the values into a list and convert them to integers
V := make([]int, N)
for i := 0; i < N; i++ {
    fmt.Scan(&V[i])
}

// Read the costs into a list and convert them to integers
C := make([]int, N)
for i := 0; i < N; i++ {
    fmt.Scan(&C[i])
}

// Initialize a list to store the profit differences, starting with 0
profit_differences := make([]int, 1)

// Initialize a variable to hold the total profit
ans := 0

// Initialize variables to hold current value and cost
X := 0
Y := 0

// Iterate through each item
for i := 0; i < N; i++ {
    // Check if the value is greater than the cost
    if V[i] - C[i] > 0 {
        // Assign the current value and cost to X and Y
        X = V[i]
        Y = C[i]
        // Calculate the profit and append it to the profit differences list
        profit_differences = append(profit_differences, X-Y)
    }
}

// Calculate and print the total profit by summing the profit differences
fmt.Println(sum(profit_differences))

