
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

var (
    in  = bufio.NewReader(os.Stdin)
    out = bufio.NewWriter(os.Stdout)
)

func main() {
    l, _ := strconv.Atoi(strings.Split(read(), " ")[0])
    r, _ := strconv.Atoi(strings.Split(read(), " ")[1])
    curr := r
    s := 0
    for curr > 0 {
        s++
        curr /= 10
    }
    first := int(math.Pow(10, float64(s)))
    second := first / 2
    ans := -1
    for _, i := range []int{l, r, first, second} {
        if i >= l && i <= r {
            curr = i
            rev := ""
            for _, k := range fmt.Sprintf("%d", curr) {
                rev += fmt.Sprintf("%d", 9-int(k[0]-'0'))
            }
            ans = max(ans, int(rev)*curr)
        }
    }
    fmt.Println(ans)
}

func read() string {
    buf := make([]byte, 0)
    for {
        line, prefix, err := in.ReadLine()
        if err!= nil {
            panic(err)
        }
        buf = append(buf, line...)
        if prefix == false {
            break
        }
    }
    return string(buf)
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

