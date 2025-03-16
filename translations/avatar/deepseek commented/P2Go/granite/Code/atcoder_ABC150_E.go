

const mod = 100000007
// Define the modulo value as \(10^9 + 7\)

func main() {
    n := readInt()
    // Read the integer input `n`

    c := readNInt64s(n)
    // Read the list of integers `c` and convert them to a slice

    sort.Slice(c, func(i, j int) bool {
        return c[i] > c[j]
    })
    // Sort the slice `c` in descending order

    b := pow(2, 2*n-2, mod)
    // Calculate `b` using the power function with base 2, exponent \(2 * n - 2\), and modulo `mod`

    a := (2 * b) % mod
    // Calculate `a` as twice `b` modulo `mod`

    ans := int64(0)
    // Initialize `ans` to 0

    for i := 0; i < n; i++ {
        // Loop through each element in the range `n`
        ans += c[i] * (a + int64(i)*b)
        // Update `ans` with the sum of the product of `c[i]` and `(a + i * b)`
        ans %= mod
        // Take modulo `mod` at each step to prevent overflow
    }

    fmt.Println(ans)
    // Print the final result `ans`
}

func readInt() int {
    // Function to read an integer input
    // Implement this function according to your language's standard input method
}

func readNInt64s(n int) []int64 {
    // Function to read `n` integers as a slice of int64
    // Implement this function according to your language's standard input method
}

func pow(x, n, mod int64) int64 {
    // Function to calculate the power of `x` to the power of `n` modulo `mod`
    // Implement this function according to your language's standard math library
}

