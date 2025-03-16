// Define the number of elements in the list 'A'
const N = int(os.Stdin.Readline())

// Initialize an empty list 'A' with 'N' elements
// Each element is a tuple containing an index and a value
var A []struct {
    index int
    value int
}

// Sort the list 'A' based on the second element of each tuple (the value)
sort.Slice(A, func(i, j int) bool {
    return A[i].value < A[j].value
})

// Extract the first element (index) of each tuple in 'A' into a new list 'A__'
var A__ []int
for _, a := range A {
    A__ = append(A__, a.index)
}

// Iterate through the list 'A__' (excluding the last element) and print each index
for i := 0; i < len(A__) - 1; i++ {
    fmt.Printf("%d ", A__[i])
}

// Print the last index in 'A__'
fmt.Printf("%d", A__[len(A__) - 1])

