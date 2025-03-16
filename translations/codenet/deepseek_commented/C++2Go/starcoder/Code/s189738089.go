<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

func main() {
  // Initialization of the dp array
  dp := make([]int, 101000)
  dp[0] = 0
  // input
  var N, K int
  fmt.Scan(&N, &K)
  h := make([]int, N)
  for i := 0; i < N; i++ {
    fmt.Scan(&h[i])
  }

  // Dynamic Programming Loop
  for i := 0; i < N; i++ {
    for j := 1; j <= K; j++ {
      dp[i + j] = min(dp[i + j], dp[i] + abs(h[i] - h[i + j]))
    }
  }

  // Output
  fmt.Println(dp[N - 1])
}

