// Define the modulo constant
const mod = 1e9 + 7

// Read the number of elements
var n int
fmt.Scanf("%d", &n)

// Read the list of integers and convert them to a list of integers
var c []int
for i := 0; i < n; i++ {
    var x int
    fmt.Scanf("%d", &x)
    c = append(c, x)
}

// Sort the list in descending order
sort.Slice(c, func(i, j int) bool { return c[i] > c[j] })

// Calculate the value of b as 2^(2*n - 2) modulo mod
b := int64(math.Pow(2, float64(2*n-2))) % mod

// Calculate the value of a as 2 * b modulo mod
a := int64(2 * b) % mod

// Initialize the answer variable
ans := int64(0)

// Iterate through the sorted list and calculate the answer
for i := 0; i < n; i++ {
    // Update the answer by adding the product of the current element and (a + i * b)
    ans += int64(c[i]) * (a + int64(i)*b)
    // Ensure the answer remains within the modulo
    ans %= mod
}

// Print the final result
fmt.Printf("%d\n", ans)

