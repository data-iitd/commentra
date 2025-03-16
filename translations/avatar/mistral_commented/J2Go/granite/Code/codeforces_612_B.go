
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    n, _ := strconv.Atoi(reader.ReadLine()[2:])
    dp := make([]int, 200001)
    ans := int64(0)
    for i := 0; i < n; i++ {
        num, _ := strconv.Atoi(reader.ReadLine())
        dp[num] = i
    }
    for i := 2; i <= n; i++ {
        ans += int64(abs(dp[i]-dp[i-1]))
    }
    fmt.Println(ans)
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

// END-OF-CODE