

// Function to find the difference between two numbers using Euclidean algorithm
func substract ( a, b int ) int {
    // Check if 'a' is greater than 'b'
    if a > b {
        // Initialize total to 0
        total := 0
        // Continue the loop while both 'a' and 'b' are greater than 0
        for a > 0 && b > 0 {
            // Add the quotient of 'a' and 'b' to the total
            total += int ( a / b )
            // Update 'a' and 'b' for the next iteration
            a = a % b
            if a > 0 {
                // Add the quotient of 'b' and 'a' to the total
                total += int ( b / a )
                // Update 'a' and 'b' for the next iteration
                b = b % a
            }
        }
        // Return the total difference
        return total
    }
    // Check if 'a' is smaller than 'b'
    if a < b {
        // Initialize total to 0
        total := 0
        // Continue the loop while both 'a' and 'b' are greater than 0
        for a > 0 && b > 0 {
            // Add the quotient of 'b' and 'a' to the total
            total += int ( b / a )
            // Update 'a' and 'b' for the next iteration
            b = b % a
            if b > 0 {
                // Add the quotient of 'a' and 'b' to the total
                total += int ( a / b )
                // Update 'a' and 'b' for the next iteration
                a = a % b
            }
        }
        // Return the total difference
        return total
    }
    // Check if 'a' is equal to 'b'
    if a == b {
        // Return 1 if 'a' is equal to 'b'
        return 1
    }
    // Return 0 if none of the above conditions are met
    return 0
}
// Take the number of test cases as input
n, _ := fmt.Scanf ( "%d", &n )
// Initialize an empty list to store the differences
lst := make ( []int, n )
// Iterate through each test case
for i := 0 ; i < n ; i++ {
    // Take two numbers as input
    a, _ := fmt.Scanf ( "%d", &a )
    b, _ := fmt.Scanf ( "%d", &b )
    // Append the difference between 'a' and 'b' to the list
    lst[i] = substract ( a, b )
}
// Print each difference in the list
for i := 0 ; i < n ; i++ {
    // Print the difference
    fmt.Println ( lst[i] )
}

