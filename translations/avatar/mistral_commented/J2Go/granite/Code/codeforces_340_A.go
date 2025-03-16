
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
    var j, i, x1, y1, c, count int64
    var ans bool

    input, _ := reader.ReadString('\n')
    input = strings.TrimSpace(input)
    input = strings.Replace(input, "\n", "", -1)
    inputSlice := strings.Split(input, " ")

    x, _ = strconv.ParseInt(inputSlice[0], 10, 64)
    y, _ = strconv.ParseInt(inputSlice[1], 10, 64)
    a, _ = strconv.ParseInt(inputSlice[2], 10, 64)
    b, _ = strconv.ParseInt(inputSlice[3], 10, 64)

    j = 2
    c = int64(math.Max(float64(x), float64(y)))

    if c > b {
        fmt.Println("0")
        ans = false
    }

    for c%int64(math.Min(float64(x), float64(y)))!= 0 && ans {
        if x > y {
            c = x * j
            j++
        } else {
            c = y * j
            j++
        }

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
            fmt.Println((b - i) / c + 1)
        } else {
            fmt.Println("0")
        }
    }

    fmt.Println("