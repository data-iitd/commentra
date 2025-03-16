// Set the value of modulo for modular arithmetic calculations
const mod = 1e9 + 7

// Read an integer n from the standard input
var n int
fmt.Scanf("%d", &n)

// Read n integers from the standard input and store them in a list c in descending order
var c []int
for i := 0; i < n; i++ {
    var x int
    fmt.Scanf("%d", &x)
    c = append(c, x)
}
sort.Slice(c, func(i, j int) bool { return c[i] > c[j] })

// Calculate the value of b using the formula 2^(2*n-2) modulo mod
var b int64 = 1
for i := 0; i < 2*n-2; i++ {
    b = (b * 2) % mod
}

// Calculate the value of a as 2*b modulo mod
var a int64 = 2 * b % mod

// Initialize the variable ans to zero
var ans int64 = 0

// Iterate through each index i from 0 to n-1 in the list c
for i := 0; i < n; i++ {
    // Add the product of the current element c[i] and the sum of a and i*b to the variable ans
    ans += c[i] * (a + int64(i)*b)
    // Update the value of ans by taking the modulo of the current sum with mod
    ans %= mod
}

// Print the value of ans as the output
fmt.Printf("%d\n", ans)

