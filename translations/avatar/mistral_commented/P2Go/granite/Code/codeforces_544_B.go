
###
# Code
###

import (
    "bufio"
    "fmt"
    "os"
)

// Read input: two integers n and k
var (
    n, k int
)

func init() {
    // Initialize input reader
    scanner := bufio.NewScanner(os.Stdin)
    scanner.Scan()
    fmt.Sscanf(scanner.Text(), "%d %d", &n, &k)
}

func main() {
    // Initialize variable x to 0
    x := 0

    // Check if k is valid based on the condition
    if k <= int(max(float64(n*n)/2, float64(n*n)-(float64(n*n)/2))) {
        // If k is valid, print 'YES'
        fmt.Println("YES")

        // Iterate through rows and columns of the grid
        for i := 0; i < n; i++ {
            for j := 0; j < n; j++ {

                // Check if current position (i, j) is valid based on the condition
                if i%2 == j%2 && x < k {

                    // If valid, print 'L' and increment x
                    fmt.Print("L")
                    x++

                // If not valid, print 'S'
                } else {
                    fmt.Print("S")
                }
            }

            // Move to the next line after completing a row
            fmt.Println()
        }
    } else {
        fmt.Println("NO")
    }
}

func max(a, b float64) float64 {
    if a > b {
        return a
    }
    return b
}

