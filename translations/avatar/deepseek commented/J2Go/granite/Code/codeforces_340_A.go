
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
    var x, y, a, b int64
    var err error
    var input string
    var tokens []string

    input, err = reader.ReadString('\n')
    if err!= nil {
        panic(err)
    }
    tokens = strings.Split(input, " ")
    x, err = strconv.ParseInt(tokens[0], 10, 64)
    if err!= nil {
        panic(err)
    }
    y, err = strconv.ParseInt(tokens[1], 10, 64)
    if err!= nil {
        panic(err)
    }
    a, err = strconv.ParseInt(tokens[2], 10, 64)
    if err!= nil {
        panic(err)
    }
    b, err = strconv.ParseInt(tokens[3], 10, 64)
    if err!= nil {
        panic(err)
    }

    var j int64 = 2
    var i, x1, y1, c int64
    var ans bool = true

    c = int64(math.Max(float64(x), float64(y)))

    if c > b {
        fmt.Println("0")
        ans = false
    }

    for c%int64(math.Min(float64(x), float64(y)))!= 0 && ans {
        if x > y {
            c = x * j
        } else {
            c = y * j
        }
        j++

        if c > b {
            fmt.Println("0")
            ans = false
            break
        }
    }

    if ans {
        i = a
        for i = a; i <= b; i++ {
            if i%c == 0 {
                break
            }
        }
        if i!= b+1 {
            fmt.Println(((b - i) / c) + 1)
        } else {
            fmt.Println("0")
        }
    }
}
