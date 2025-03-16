// Define long long type for large integers
type ll int64

// Define constants for modulo operations and maximum size
const mod = 1e9 + 7
const NMAX = 1000010

// Arrays to store factorials, inverse factorials, and modular inverses
var fac [NMAX]ll
var finv [NMAX]ll
var inv [NMAX]ll

// Function to initialize factorials and their inverses
func init() {
    // Base cases for factorials and their inverses
    fac[0], fac[1] = 1, 1
    finv[0], finv[1] = 1, 1
    inv[1] = 1

    // Precompute factorials and their modular inverses
    for i := 2; i < NMAX; i++ {
        fac[i] = (fac[i - 1] * ll(i)) % mod // Compute factorial mod
        inv[i] = mod - inv[mod % ll(i)] * (mod / ll(i)) % mod // Compute modular inverse using Fermat's little theorem
        finv[i] = (finv[i - 1] * inv[i]) % mod // Compute inverse factorial mod
    }
}

// Function to compute binomial coefficient C(n, k)
func C(n, k int) ll {
    // Return 0 if k is greater than n or if either is negative
    if n < k {
        return 0
    }
    if n < 0 || k < 0 {
        return 0
    }

    // Calculate C(n, k) using precomputed factorials and inverses
    return (fac[n] * (finv[k] * finv[n - k] % mod)) % mod
}

func main() {
    // Initialize factorials and inverses
    init()

    // Read input values for X and Y
    var X, Y int
    fmt.Scan(&X, &Y)

    // Check if the sum of X and Y is divisible by 3
    if (X + Y) % 3 != 0 {
        fmt.Println(0) // If not, output 0 and exit
        return
    }

    // Calculate n based on the sum of X and Y
    n := (X + Y) / 3 + 1

    // Calculate k based on the relationship to the line y = 2x
    k := 2 * (n - 1) - Y + 1 // Determine how far the point is from the topmost point

    // Output the result of the binomial coefficient C(n-1, k-1)
    fmt.Println(C(n - 1, k - 1))
}

