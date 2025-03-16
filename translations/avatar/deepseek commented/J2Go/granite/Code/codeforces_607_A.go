

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("Enter the number of beacons:")
    n, _ := strconv.Atoi(reader.ReadLine())
    beacon := make([]int, 1000001)
    dp := make([]int, 1000001)
    max := 0

    for i := 0; i < n; i++ {
        input := strings.Split(reader.ReadLine(), " ")
        a, _ := strconv.Atoi(input[0])
        beacon[a] = strconv.Atoi(input[1])
    }

    if beacon[0]!= 0 {
        dp[0] = 1
    }

    for i := 1; i < 1000001; i++ {
        if beacon[i]!= 0 && beacon[i] < i {
            dp[i] = dp[i-beacon[i]-1] + 1
        } else if beacon[i]!= 0 {
            dp[i] = 1
        } else {
            dp[i] = dp[i-1]
        }
        if dp[i] > max {
            max = dp[i]
        }
    }

    fmt.Println(n - max)
}

