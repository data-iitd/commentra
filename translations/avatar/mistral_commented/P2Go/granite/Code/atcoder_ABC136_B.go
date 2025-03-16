
// Function to find the number of digits in a given number
func main() {
    // Read the number of test cases from the standard input
    var N int
    fmt.Scan(&N)

    // Initialize variables
    i := 1
    ans := 0

    // Calculate the answer using a for loop
    for 10*i <= N {
        // Add the difference between the current power of 10 and the previous power of 10 to the answer
        ans += (10*i - 10*(i-1))
        // Increment the index i by 2
        i += 2
    }

    // Add the remaining digits of the number N to the answer
    ans += max(0, N - 10*(i-1) + 1)

    // Print the answer
    fmt.Println(ans)
}

// Function to find the maximum of two integers
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

// Run the main function if the script is executed directly
func main() {
    main()
}

