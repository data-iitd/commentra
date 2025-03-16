// Function to perform the main logic of the program
func main() {

    // Initialize variables n and m with the given input
    var n, m int
    fmt.Scan(&n, &m)

    // Initialize lists round_complexity and george_complexity
    // with the given input
    round_complexity := make([]int, n)
    george_complexity := make([]int, m)
    for i := 0; i < n; i++ {
        fmt.Scan(&round_complexity[i])
    }
    for i := 0; i < m; i++ {
        fmt.Scan(&george_complexity[i])
    }

    // Initialize variables i and j to 0
    i := 0
    j := 0

    // Start the while loop that compares the complexity of each
    // round with George's complexity and moves the pointers accordingly
    for i < n && j < m {

        // Increment i if the complexity of the current round is
        // less than or equal to George's complexity at the current j
        if round_complexity[i] <= george_complexity[j] {
            i++
        }

        // Increment j
        j++
    }

    // Print the final answer
    fmt.Println(n - i)
}

// Run the main function if the script is executed directly
func main() {
    main()
}

