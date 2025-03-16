#######
# Code
#######

# Define input variables A, B, C, D as integers
# obtained from user input, separated by spaces
int A, B, C, D;
cin >> A >> B >> C >> D;

// Initialize a 2D array 'd' with dimensions (C+1) x (D+1)
// filled with zeros
int d[C + 1][D + 1];
for (int i = 0; i <= C; i++) {
    for (int j = 0; j <= D; j++) {
        d[i][j] = 0;
    }
}

// Set the value of d[A][B] to 1
d[A][B] = 1;

// Matrix multiplication using dynamic programming approach
// Iterate through the rows from A to C
for (int i = A; i <= C; i++) {
    // Iterate through the columns from B to D
    for (int j = B; j <= D; j++) {
        // Calculate the value of d[i][j] using the previous values
        d[i][j] += (d[i][j - 1] * i + d[i - 1][j] * j - d[i - 1][j - 1] * (i - 1) * (j - 1)) % m;
    }
}

// Print the final value of d[C][D]
cout << d[C][D] << endl;

