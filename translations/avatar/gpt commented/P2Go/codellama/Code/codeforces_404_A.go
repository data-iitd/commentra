// Read the number of rows/columns for the square matrix
n := 0
fmt.Scan(&n)

// Initialize an empty list to store the input strings
s := make([]string, n)

// Read n strings from input and append them to the list s
for i := 0; i < n; i++ {
	fmt.Scan(&s[i])
}

// Initialize a flag variable (not used in this code)
flag := 0

// Initialize lists to store diagonal elements
d1 := make([]string, n)  // Primary diagonal
d2 := make([]string, n)  // Secondary diagonal

// Initialize a set to store non-diagonal elements
rem := make(map[string]bool)

// Iterate through the matrix to populate the diagonals and non-diagonal elements
for i := 0; i < n; i++ {
	for j := 0; j < n; j++ {
		// If it's a primary diagonal element
		if (i == j) {
			d1[i] = s[i][j]
		}
		// If it's a secondary diagonal element
		if (i == n - j - 1) {
			d2[i] = s[i][j]
		}
		// If it's a non-diagonal element
		if (i != j && i != n - j - 1) {
			rem[s[i][j]] = true
		}
	}
}

// Check conditions to determine the output
// If the number of unique non-diagonal elements is not 1
if (len(rem) != 1) {
	fmt.Println("NO")
}
// If the primary and secondary diagonals are not equal
if (d1 != d2) {
	fmt.Println("NO")
}
// If the primary diagonal does not consist of the same element
if (len(rem) != 1) {
	fmt.Println("NO")
}
// If the unique element in the primary diagonal is also in the non-diagonal set
if (rem[d1[0]] == true) {
	fmt.Println("NO")
}
// If all conditions are satisfied, print 'YES'
else {
	fmt.Println("YES")
}

