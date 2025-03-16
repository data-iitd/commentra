
// Function to resolve the problem
func resolve() {

    // Read the number of test cases
    n := readInt()

    // Initialize empty slices to store low and high values
    low := make([]int, n)
    high := make([]int, n)

    // Read low and high values for each test case and append to respective slices
    for i := 0; i < n; i++ {
        a, b := readTwoInts()
        low[i] = a
        high[i] = b
    }

    // Sort the low and high slices in ascending order
    sort.Ints(low)
    sort.Ints(high)

    // Check if the number of test cases is odd
    if n%2!= 0 {
        // If it is odd, print the difference between the middle low and middle high values
        fmt.Println(high[n/2] - low[n/2] + 1)
    } else {
        // If it is even, calculate the average of middle low and middle high values
        hh := (high[n/2] + high[n/2-1]) / 2
        ll := (low[n/2] + low[n/2-1]) / 2

        // Print the result which is twice the difference between the averages
        fmt.Println(int((hh-ll)*2)+1)
    }
}

