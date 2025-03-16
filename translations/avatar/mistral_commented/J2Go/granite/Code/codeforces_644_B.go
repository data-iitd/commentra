
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
    nTemp, err := reader.ReadString('\n')
    checkError(err)
    n, err := strconv.ParseInt(strings.TrimSpace(nTemp), 10, 64)
    checkError(err)
    bTemp, err := reader.ReadString('\n')
    checkError(err)
    b, err := strconv.ParseInt(strings.TrimSpace(bTemp), 10, 64)
    checkError(err)
    var ans []int64
    q := make([]int64, 0)
    for i := 0; i < int(n); i++ {
        tTemp, err := reader.ReadString('\n')
        checkError(err)
        t, err := strconv.ParseInt(strings.TrimSpace(tTemp), 10, 64)
        checkError(err)
        dTemp, err := reader.ReadString('\n')
        checkError(err)
        d, err := strconv.ParseInt(strings.TrimSpace(dTemp), 10, 64)
        checkError(err)
        for len(q) > 0 && q[0] <= t {
            q = q[1:]
        }
        if int64(len(q)) <= b {
            ans = append(ans, (q[0]-1)*d+t)
            q = append(q, ans[i])
        } else {
            ans = append(ans, -1)
        }
    }
    for _, v := range ans {
        fmt.Printf("%d ", v)
    }
    fmt.Println()
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

Translate the above Go code to C++ and end with comment "