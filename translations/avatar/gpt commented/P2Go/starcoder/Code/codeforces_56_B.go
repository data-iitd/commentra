// Read the number of elements in the list
N := int(input())

// Read the list of integers from input and convert them to a list of integers
A := strings.Split(input(), " ")
A = make([]int, len(A))
for i := 0; i < len(A); i++ {
    A[i], _ = strconv.Atoi(A[i])
}

// Initialize minimum and maximum indices for the range of elements that are out of place
mn, mx := N + 1, -1

// Iterate through the list to find the first and last indices where the element is not in its correct position
for i := 0; i < N; i++ {
    // Check if the current index + 1 does not match the value at that index
    if (i + 1!= A[i]) {
        // Update the minimum index if the current index is less than the current minimum
        mn = min(mn, i)
        // Update the maximum index if the current index is greater than the current maximum
        mx = max(mx, i)
    }
}

// If no elements were out of place, output '0 0'
if (mx == -1) {
    fmt.Println("0 0")
} else {
    // Reverse the subarray from mn to mx and concatenate it with the rest of the list
    A = append(A[:mn], A[mn:mx+1][::-1]...)
    A = append(A[mn:mx+1], A[mx+1:]...)
    
    // Check if the modified list is sorted
    if (sort.IntsAreSorted(A)) {
        // If sorted, print the 1-based indices of the range that was reversed
        fmt.Println(mn + 1, mx + 1)
    } else {
        // If not sorted, output '0 0'
        fmt.Println("0 0")
    }
}

