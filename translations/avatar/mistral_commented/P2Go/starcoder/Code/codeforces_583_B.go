// Define the main function
func main() {
    // Read the number of test cases
    var n int
    fmt.Scanf("%d", &n)

    // Read the array of integers
    a := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &a[i])
    }

    // Initialize variables
    currentLevel := 0
    counter := 0
    counterTurns := -1

    // Main loop
    for counter < len(a) {
        // Increment turns counter
        counterTurns++

        // Iterate through the array
        for i := 0; i < len(a); i++ {
            // If current index is valid and its value is less than or equal to current level
            if a[i]!= -1 && a[i] <= counter {
                // Increment counter and mark the index as visited
                counter++
                a[i] = -1
        }

        // Reverse the array
        a = reverse(a)
    }

    // Print the result
    fmt.Printf("%d", counterTurns)
}

// Reverse the array
func reverse(a []int) []int {
    for i := 0; i < len(a)/2; i++ {
        a[i], a[len(a)-i-1] = a[len(a)-i-1], a[i]
    }
    return a
}

// END-OF-CODE
