// Take an integer input `n` which represents the number of lists to be provided as input.
n := 0
fmt.Scan(&n)

// Initialize a counter `c` to 0. This will keep track of the number of lists where the sum of elements is greater than 1.
c := 0

// Loop `n` times to process each list of integers.
for i := 0; i < n; i++ {
    // Take a list of integers as input, split them by spaces, convert them to integers, and store them in `l1`.
    var l1 []int
    fmt.Scan(&l1)
    
    // Calculate the sum of the elements in `l1`.
    // If the sum is greater than 1, increment the counter `c` by 1.
    if sum(l1) > 1 {
        c++
    }
}

// After the loop completes, print the final value of `c`, which represents the number of lists where the sum of elements is greater than 1.
fmt.Println(c)

