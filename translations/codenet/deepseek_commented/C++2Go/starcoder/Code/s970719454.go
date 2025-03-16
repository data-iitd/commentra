<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Declare arrays to store information
var here [100001]int
var dp1 [100001]int
var dp2 [100001]int

func main() {
    // Main loop to read input values
    for {
        var n, m int
        fmt.Scanf("%d %d", &n, &m)
        if n == 0 {
            break
        }

        // Initialize arrays for each iteration
        for i := 0; i < 100001; i++ {
            here[i] = 0
            dp1[i] = 0
            dp2[i] = 0
        }

        // Flag to determine behavior based on input
        var dpflg bool

        // Read m values and mark them in 'here'
        for i := 0; i < m; i++ {
            var a int
            fmt.Scanf("%d", &a)
            if a == 0 {
                dpflg = true
            }
            here[a] = 1
        }

        // Variables to store maximum lengths of sequences
        var maxi1, maxi2 int

        // Calculate maximum length of sequences in dp1
        for i := 1; i < n+1; i++ {
            if here[i] == 1 {
                dp1[i] = dp1[i-1] + 1
            }
            maxi1 = max(maxi1, dp1[i])
        }

        // Calculate maximum length of sequences in dp2
        for i := 1; i < n+1; i++ {
            if here[i] == 1 {
                dp2[i] = dp2[i-1] + 1
            } else {
                dp2[i] = dp1[i-1] + 1
            }
            maxi2 = max(maxi2, dp2[i])
        }

        // Output the result based on the value of dpflg
        if!dpflg {
            fmt.Printf("%d\n", maxi1)
        } else {
            fmt.Printf("%d\n", maxi2)
        }
    }
}

<<<<<<< HEAD
=======
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

>>>>>>> 98c87cb78a (data updated)
