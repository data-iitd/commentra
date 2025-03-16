
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Create a new scanner to read input from the console
    scanner := bufio.NewScanner(os.Stdin)

    // Read the number of elements N and the multiplier X
    scanner.Scan()
    N, _ := strconv.Atoi(scanner.Text())
    scanner.Scan()
    X, _ := strconv.ParseInt(scanner.Text(), 10, 64)

    // Initialize an array to store the elements and a prefix sum array
    x := make([]int, N)
    xsum := make([]int64, N+1)

    // Read the elements into the array and compute the prefix sums
    for i := 0; i < N; i++ {
        scanner.Scan()
        x[i], _ = strconv.Atoi(scanner.Text())
        xsum[i+1] = xsum[i] + int64(x[i])
    }

    // Initialize the answer with the cost of processing all elements with the base cost
    ans := X*int64(N) + 5*xsum[N]

    // Iterate through possible splits of the array
    for i := 1; i < N; i++ {
        // Calculate the cost for the current split
        cost := X*int64(i) + 5*(xsum[N]-xsum[N-i])

        // Incrementally add costs based on the current split
        for j := 5; j <= N-i; j += 2 {
            // If the current cost exceeds the best answer found, break out of the loop
            if cost > ans {
                break
            }
            // Update the cost based on the prefix sums
            cost += int64(j) * (xsum[N-i]-xsum[N-i-j])
        }
        // Update the answer with the minimum cost found
        ans = int64(int(cost))
        if ans > X*int64(N)+5*xsum[N] {
            ans = X*int64(N) + 5*xsum[N]
        }
    }

    // Output the final answer, which includes the base cost
    fmt.Println(ans)
}

