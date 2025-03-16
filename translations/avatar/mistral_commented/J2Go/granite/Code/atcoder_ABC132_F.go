
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var n, k int
    var err error
    n, err = strconv.Atoi(reader.ReadLine())
    if err!= nil {
        panic(err)
    }
    k, err = strconv.Atoi(reader.ReadLine())
    if err!= nil {
        panic(err)
    }
    mod := int64(1e9 + 7)
    len := make([]int, 0)
    l := 1
    for l <= n {
        r := n / (n / l)
        len = append(len, r-l+1)
        l = r + 1
    }
    q := len
    dp := make([]int64, k*(q+1))
    for j := 1; j <= q; j++ {
        dp[j] = int64(len[j-1]) + dp[j-1]
    }
    for i := 1; i < k; i++ {
        for j := 1; j <= q; j++ {
            dp[i*(q+1)+j] = dp[i*(q+1)+j-1]+dp[(i-1)*(q+1)+q-j+1]*int64(len[j-1])
            dp[i*(q+1)+j] %= mod
        }
    }
    fmt.Println(dp[k*(q+1)-1])
}

