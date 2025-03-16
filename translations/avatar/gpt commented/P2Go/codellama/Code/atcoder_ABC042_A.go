// Read a line of input, split it into components, and convert each component to an integer, storing them in a tuple
ABC := make([]int, 0)
fmt.Scan(&ABC)

// Check if the number 5 appears exactly twice in the tuple
if ABC.Count(5) == 2 {
    // If 5 appears twice, check if the sum of the numbers in the tuple equals 17
    if ABC.Sum() == 17 {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
} else {
    // If 5 does not appear exactly twice, print 'NO'
    fmt.Println("NO")
}

