<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "sort"
)

// Define constants
const maxn = 200000 + 10
const INF = int(1e8)

// Declare arrays
var maps [maxn]int
var num [maxn]int

func main() {
    var n int
    for {
        fmt.Scanf("%d", &n)
        if n == 0 {
            break
        }

        // Read the elements into maps array and copy them to num array
        for i := 1; i <= n; i++ {
            fmt.Scanf("%d", &maps[i])
            num[i] = maps[i]
        }

        // Sort the maps array to find the median easily
        sort.Ints(maps[1:n + 1])

        // Calculate the median index
        m := n / 2

        // Iterate through the num array and print the appropriate median value
        for i := 1; i <= n; i++ {
            if num[i] <= maps[m] {
                fmt.Printf("%d\n", maps[m + 1]) // Print the element after the median if num[i] is less than or equal to the median
            } else {
                fmt.Printf("%d\n", maps[m]) // Print the median if num[i] is greater than the median
            }
        }
    }
}

