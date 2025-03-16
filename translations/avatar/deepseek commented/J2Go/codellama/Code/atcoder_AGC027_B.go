
package main

import (
    "fmt"
    "math"
)

func main() {
    // Read the number of points N and the target value X
    var N int
    var X int64
    fmt.Scan(&N, &X)

    // Initialize an array to store the positions of N points
    x := make([]int64, N)
    xsum := make([]int64, N+1)

    // Read the positions of the points into the array x and calculate the cumulative sum
    for i := 0; i < N; i++ {
        fmt.Scan(&x[i])
        xsum[i+1] = xsum[i] + x[i]
    }

    // Initialize ans with a value calculated using the total sum of positions and the given X value
    ans := X*int64(N) + 5*xsum[N]

    // Iterate over possible values of i, which represents the number of points to be removed
    for i := 1; i < N; i++ {
        cost := X*int64(i) + 5*(xsum[N]-xsum[N-i])

        // For each value of i, calculate the cost of removing i points and update ans if a better cost is found
        for j := 5; k := N - i; k >= 0; j += 2 {
            if cost > ans {
                break
            }
            cost += j * (xsum[k] - xsum[math.Max(float64(k-i), 0)])
        }
        ans = int64(math.Min(float64(ans), float64(cost)))
    }

    // Print the minimum cost found
    fmt.Println(ans + int64(N)*X)
}

