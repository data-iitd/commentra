#######
// Code
#######

// Define input variables A, B, C, D as integers
// obtained from user input, separated by spaces
var A, B, C, D int
fmt.Scanf("%d %d %d %d", &A, &B, &C, &D)

// Initialize a 2D array 'd' with dimensions (C+1) x (D+1)
// filled with zeros
d := make([][]int, C+1)
for i := range d {
    d[i] = make([]int, D+1)
}

// Set the value of d[A][B] to 1
d[A][B] = 1

// Matrix multiplication using dynamic programming approach
// Iterate through the rows from A to C
for i := A; i <= C; i++ {
    // Iterate through the columns from B to D
    for j := B; j <= D; j++ {
        // Calculate the value of d[i][j] using the previous values
        d[i][j] += (d[i][j-1]*i + d[i-1][j]*j - d[i-1][j-1]*(i-1)*(j-1)) % m
}

// Print the final value of d[C][D]
fmt.Println(d[C][D])

