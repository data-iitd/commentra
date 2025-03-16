// Read the number of test cases
N := 0
fmt.Scan(&N)

// Read the array V of size N
V := make([]int, N)
for i := 0; i < N; i++ {
	fmt.Scan(&V[i])
}

// Read the array C of size N
C := make([]int, N)
for i := 0; i < N; i++ {
	fmt.Scan(&C[i])
}

// Initialize an empty list to store the differences between V and C
list := make([]int, 0)

// Initialize variables to store the current difference and the sum of differences
ans := 0
X := 0
Y := 0

// Iterate through each index i from 0 to N-1
for i := 0; i < N; i++ {
	// If the difference between V[i] and C[i] is positive
	if V[i]-C[i] > 0 {
		// Update X and Y with the respective values from V and C at index i
		X = V[i]
		Y = C[i]
		// Append the difference X-Y to the list
		list = append(list, X-Y)
		// Update the sum of differences
		ans += X - Y
	}
}

// Print the sum of all the elements in the list
fmt.Println(sum(list))
// Print the sum of all the differences between V and C
fmt.Println(ans)

