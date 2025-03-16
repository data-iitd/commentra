// Set the value of modulo for modular arithmetic calculations
mod := 1000000007

// Read an integer n from the standard input
n, _ := strconv.Atoi(readLine(os.Stdin))

// Read n integers from the standard input and store them in a list c in descending order
c := make([]int, n)
for i := 0; i < n; i++ {
	c[i], _ = strconv.Atoi(readLine(os.Stdin))
}
sort.Ints(c)

// Calculate the value of b using the formula 2^(2*n-2) modulo mod
b := int(math.Pow(2, float64(2*n-2))) % mod

// Calculate the value of a as 2*b modulo mod
a := 2 * b % mod

// Initialize the variable ans to zero
ans := 0

// Iterate through each index i from 0 to n-1 in the list c
for i := 0; i < n; i++ {
	// Add the product of the current element c[i] and the sum of a and i*b to the variable ans
	ans += c[i] * (a + i*b)
	// Update the value of ans by taking the modulo of the current sum with mod
	ans %= mod
}

// Print the value of ans as the output
fmt.Println(ans)

