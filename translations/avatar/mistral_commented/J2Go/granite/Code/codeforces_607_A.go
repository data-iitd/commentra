

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
    fmt.Println("Enter the number of elements in the array:")
    n, _ := strconv.Atoi(reader.ReadLine()[0])
    beacon := make([]int, 1000001)
    dp := make([]int, 1000001)
    for i := 0; i < n; i++ {
        input := strings.Split(reader.ReadLine()[0], " ")
        a, _ := strconv.Atoi(input[0])
        beacon[a] = beacon[a] + 1
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
    }
    max := 0
    for i := 0; i < 1000001; i++ {
        if dp[i] > max {
            max = dp[i]
        }
    }
    fmt.Println(n - max)
}

These comments should provide a clear understanding of the logic behind each part of the code.