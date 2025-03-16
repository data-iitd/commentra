
// Initialize an empty list `L`
var L []int

// Read the first input, which is the number of elements to add to the list
var n int
fmt.Scanf("%d", &n)

// Use a for loop to iterate through each integer in the input
for k := 0; k < n; k++ {
    // Add `r` elements to the list `L` with the value `r`
    L = append(L, r)
    // Increment the value of `r` by 1 to prepare for the next iteration
    r++
}

// Read the second input, which represents the indices of the elements to print from the list
var indices []int
fmt.Scanf("%d", &indices)

// Use another for loop to iterate through each integer in the input
for _, j := range indices {
    // Print the element at the given index using the index as an offset from the beginning of the list
    fmt.Printf("%d\n", L[j-1])
}

