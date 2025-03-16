// Define long long type for convenience
type ll int64
// Define a pair type for convenience
type PP struct {
    first, second ll
}

// Arrays to store the keys and costs
var key [1005]ll
var cost [1005]ll
// DP table to store the minimum costs for each state
var dp [1<<12+5][1005]ll
// Define a large constant for infinity
const INF ll = 123456789012

func main() {
    // Read the number of keys (n) and the number of items (m)
    var n, m ll
    fmt.Scan(&n, &m)

    // Initialize the DP table with infinity
    for i := 0; i < 1<<12+5; i++ {
        for j := 0; j < 1005; j++ {
            dp[i][j] = INF // Set each entry to infinity
        }
    }

    // Base case: cost of obtaining no keys is 0
    dp[0][0] = 0

    // Read the costs and keys for each item
    for i := 1; i <= m; i++ {
        var b ll
        fmt.Scan(&cost[i], &b) // Read cost and number of keys for item i
        for j := 0; j < b; j++ {
            var c ll
            fmt.Scan(&c) // Read each key
            key[i] += (1 << (c - 1)) // Update the key bitmask for item i
        }
    }

    // Fill the DP table
    for i := 0; i < 1<<n; i++ {
        for j := 0; j < m; j++ {
            // Update the DP table for not taking the (j+1)th item
            dp[i][j + 1] = min(dp[i][j], dp[i][j + 1])
            // Update the DP table for taking the (j+1)th item
            dp[i | key[j + 1]][j + 1] = min(dp[i | key[j + 1]][j + 1], dp[i][j] + cost[j + 1])
        }
    }

    // Check if it's possible to obtain all keys
    if dp[(1 << n) - 1][m] == INF {
        fmt.Println(-1) // If not possible, print -1
    } else {
        fmt.Println(dp[(1 << n) - 1][m]) // Print the minimum cost to obtain all keys
    }
}

// Define a min function to return the minimum of two values
func min(a, b ll) ll {
    if a < b {
        return a
    }
    return b
}

