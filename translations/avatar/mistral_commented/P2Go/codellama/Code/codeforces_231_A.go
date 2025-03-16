// Take an integer 'n' as input from the user
n := 0
fmt.Scan(&n)

// Initialize a counter 'c' to 0
c := 0

// Iterate through the range of 'n'
for i := 0; i < n; i++ {
    // Take 'n' lists of integers as input from the user
    var l1 []int
    fmt.Scan(&l1)
    
    // Check if the sum of the elements in the current list is greater than 1
    if sum(l1) > 1 {
        // Increment the counter 'c' by 1 if the condition is true
        c++
    }
}

// Print the value of the counter 'c'
fmt.Println(c)

