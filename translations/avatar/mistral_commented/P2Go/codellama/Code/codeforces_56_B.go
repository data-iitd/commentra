#######
# Code
#######

// Read the number of elements in the list 'A'
var N int
fmt.Scan(&N)

// Initialize an empty list 'A' with the given size 'N'
// and read the elements from the standard input
A := make([]int, N)
for i := 0; i < N; i++ {
    fmt.Scan(&A[i])
}

// Initialize minimum and maximum indices 'mn' and 'mx'
mn, mx := N+1, -1

// Iterate through the list 'A' from index 0 to 'N-1'
for i := 0; i < N; i++ {
    // Check if the current index 'i' is not equal to the next element
    if i+1 != A[i] {
        // Update the minimum and maximum indices 'mn' and 'mx'
        mn = min(mn, i)
        mx = max(mx, i)
    }
}

// Check if the maximum index 'mx' is still equal to -1
if mx == -1 {
    // If yes, print '0 0' as the output
    fmt.Println("0 0")
} else {
    // Slice the list 'A' based on the indices 'mn' and 'mx+1'
    A = A[:mn] + A[mn:(mx+1)][::-1] + A[(mx+1):]
    
    // Check if the sliced list 'A' is sorted in ascending order
    if sort.IntsAreSorted(A) {
        // If yes, print the minimum and maximum indices 'mn+1' and 'mx+1' as the output
        fmt.Println(mn+1, mx+1)
    } else {
        // If no, print '0 0' as the output
        fmt.Println("0 0")
    }
}

