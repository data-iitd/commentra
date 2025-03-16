

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
    var n int
    var str string
    fmt.Fscan(reader, &n)
    fmt.Fscan(reader, &str)
    l := strings.Split(str, "")
    t := 0
    for i := 0; i < n; i++ {
        if l[i]!= "4" && l[i]!= "7" {
            t = 1
            break
        }
    }
    if t == 1 {
        fmt.Println("NO")
    } else {
        x := 0
        y := 0
        for i := 0; i < n/2; i++ {
            x, _ = strconv.Atoi(l[i])
            y, _ = strconv.Atoi(l[n-1-i])
            x += y
        }
        if x == y {
            fmt.Println("YES")
        } else {
            fmt.Println("NO")
        }
    }
}
