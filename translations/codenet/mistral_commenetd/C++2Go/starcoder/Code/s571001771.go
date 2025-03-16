<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)
import "fmt"

// Define necessary data types and constants
type ll int64
const INF = 123456789012 // Constants and data types are defined here
var key [1005]ll // Initialize arrays here
var cost [1005]ll
var dp [1<<12 + 5][1005]ll // 2D dynamic programming table

func main() {
  // Read input
  var n, m ll // n is the number of switches, m is the number of bulbs
  fmt.Scanf("%v %v", &n, &m)

  // Initialize dynamic programming table with infinite values
  for i := 0; i < (1<<12)+5; i++ {
    for j := 0; j < 1005; j++ {
      dp[i][j] = INF // Set all values to infinite
    }
  }
  dp[0][0] = 0 // Set the initial value of dp[0][0] to 0

  // Read bulbs' information
  for i := 1; i <= m; i++ {
    var b ll // The number of switches needed to turn on this bulb
    fmt.Scanf("%v %v", &cost[i], &b)

    // Update key array
    for j := 0; j < b; j++ {
      var c ll // The position of the switch
      fmt.Scanf("%v", &c)
      key[i] += 1 << (c-1) // Set the corresponding bit in key[i] to 1
    }
  }

  // Fill dynamic programming table
  for i := 0; i < (1<<n); i++ { // Iterate through all possible combinations of switches
    for j := 0; j < m; j++ { // Iterate through all bulbs
      dp[i][j+1] = min(dp[i][j], dp[i][j+1]) // Update dp[i][j+1] with the minimum value between dp[i][j] and dp[i][j+1]
      dp[i|key[j+1]][j+1] = min(dp[i|key[j+1]][j+1], dp[i][j]+cost[j+1]) // Update dp[i|key[j+1]][j+1] with the minimum value between dp[i|key[j+1]][j+1] and dp[i][j]+cost[j+1]
    }
  }

  // Output result
  if dp[(1<<n)-1][m] == INF {
    fmt.Println(-1) // Check if the minimum cost is infinite
  } else {
    fmt.Println(dp[(1<<n)-1][m]) // Output the minimum cost
  }
}

