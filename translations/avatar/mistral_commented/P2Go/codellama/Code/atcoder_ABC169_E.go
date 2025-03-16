// Function to resolve the problem
func resolve( ) {

    // Read the number of test cases
    var n int
    fmt.Scan(&n)

    // Initialize empty slices to store low and high values
    low := make([]int, 0)
    high := make([]int, 0)

    // Read low and high values for each test case and append to respective slices
    for i := 0; i < n; i++ {
        var a, b int
        fmt.Scan(&a, &b)
        low = append(low, a)
        high = append(high, b)
    }

    // Sort the low and high slices in ascending order
    sort.Ints(low)
    sort.Ints(high)

    // Check if the number of test cases is odd
    if n % 2 {
        // If it is odd, print the difference between the middle low and middle high values
        fmt.Println(high[(n+1)/2-1] - low[(n+1)/2-1] + 1)
    } else {
        // If it is even, calculate the average of middle low and middle high values
        hh := (high[(n)/2-1] + high[(n)/2]) / 2
        ll := (low[(n)/2-1] + low[(n)/2]) / 2

        // Print the result which is twice the difference between the averages
        fmt.Println(int((hh-ll)*2)+1)
    }
}

