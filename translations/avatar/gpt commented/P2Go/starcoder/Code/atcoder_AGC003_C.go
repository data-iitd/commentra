// Read an integer N from user input
var N int
fmt.Scanf("%d", &N)

// Create a list A where each element is calculated as (input value * N + index)
// This combines user input with the index to create a unique value for each position
A := make([]int, N)
for i := 0; i < N; i++ {
    A[i] = (int(N) * int(N) + i)
}

// Sort the list A in ascending order
sort.Ints(A)

// Initialize a counter to keep track of mismatches
cnt := 0

// Iterate through each element in the sorted list A
for i := 0; i < N; i++ {
    // Calculate the value of d as the remainder of A[i] divided by N, then take that remainder modulo 2
    d := (A[i] % N) % 2

    // Check if the parity of d does not match the parity of the current index i
    if d % 2!= i % 2 {
        // If they don't match, increment the counter
        cnt++
    }
}

// Print half of the count of mismatches, as each mismatch can be paired
fmt.Printf("%d\n", cnt/2)

