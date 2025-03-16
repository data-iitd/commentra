// Define the modulo constant
mod := 1000000007

// Read the number of elements
n := 0
fmt.Scan(&n)

// Read the list of integers and convert them to a list of integers
c := make([]int, n)
for i := 0; i < n; i++ {
    fmt.Scan(&c[i])
}

// Sort the list in descending order
sort.Sort(sort.Reverse(sort.IntSlice(c)))

// Calculate the value of b as 2^(2*n - 2) modulo mod
b := int(math.Pow(2, float64(2*n-2))) % mod

// Calculate the value of a as 2 * b modulo mod
a := 2 * b % mod

// Initialize the answer variable
ans := 0

// Iterate through the sorted list and calculate the answer
for i := 0; i < n; i++ {
    // Update the answer by adding the product of the current element and (a + i * b)
    ans += c[i] * (a + i*b)
    // Ensure the answer remains within the modulo
    ans %= mod
}

// Print the final result
fmt.Println(ans)

