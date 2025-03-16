// Define constants for base and maximum size
const B = 13131
const N = 500000 + 7

// Declare global variables
var n int // Length of the input string
var s []byte // Input string
var f []int64 // Array to store computed values based on the input string
var g []int64 // Array to store the shift values
var map = make(map[int64]int64) // Map to count occurrences of computed values
var cnt int64 // Counter for the final result

// Function to compute power of a number with a given exponent
func pow(a, k int64) int64 {
    // Adjust exponent if negative
    if k < 0 {
        k += (1 << 63) - 1
    }
    t := int64(1) // Initialize result
    // Exponentiation by squaring
    for ; k > 0; a *= a, k >>= 1 {
        if k&1 == 1 {
            t *= a // Multiply result if current bit is set
        }
    }
    return t // Return computed power
}

func main() {
    // Uncomment the following lines to read from a file
    // freopen("code.in", "r", stdin);
    // freopen("code.out", "w", stdout);

    // Read input values: number of operations and the operations string
    fmt.Scanf("%d%s", &n, &s)

    // Process each character in the input string
    for i := 1; i <= n; i++ {
        // If the character is '+' or '-', update f and g arrays
        if s[i-1] == '+' || s[i-1] == '-' {
            f[i] = f[i-1] + (s[i-1] == '+' ? 1 : -1) * pow(B, g[i-1])
        } else {
            // If the character is '<' or '>', update f and g arrays accordingly
            f[i] = f[i-1] // No change in f
            g[i] = g[i-1] + (s[i-1] == '<' ? -1 : 1) // Update g based on direction
        }
    }

    // Iterate backwards through the string to count valid combinations
    for i := n; i > 0; i-- {
        map[f[i]]++ // Increment the count of the current f value
        // Update the counter with the number of valid combinations found
        cnt += map[f[n]*pow(B, g[i-1])+f[i-1]]
    }

    // Output the final count of valid combinations
    fmt.Println(cnt)
}

