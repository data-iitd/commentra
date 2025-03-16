// Define the number of elements in the list 'A'
N := 0
fmt.Scan(&N)

// Initialize an empty list 'A' with 'N' elements
// Each element is a tuple containing an index and a value
A := make([][2]int, N)

// Iterate through the list 'A' and read the index and value of each element
for i := 0; i < N; i++ {
	fmt.Scan(&A[i][0], &A[i][1])
}

// Sort the list 'A' based on the second element of each tuple (the value)
sort.Slice(A, func(i, j int) bool {
	return A[i][1] < A[j][1]
})

// Extract the first element (index) of each tuple in 'A' into a new list 'A_'
A_ := make([]int, N)
for i := 0; i < N; i++ {
	A_[i] = A[i][0]
}

// Iterate through the list 'A_' (excluding the last element) and print each index
for i := 0; i < N-1; i++ {
	fmt.Print(A_[i], " ")
}

// Print the last index in 'A_'
fmt.Println(A_[N-1])

