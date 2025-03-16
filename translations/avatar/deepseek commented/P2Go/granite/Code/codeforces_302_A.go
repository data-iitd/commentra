

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
    m, _ := strconv.Atoi(reader.ReadLine()[2:])
    sa := 0
    for _, char := range reader.ReadLine() {
        if char == '-' {
            sa++
        }
    }
    sa = int(min(int64(n-sa), int64(sa)))
    var ss []string
    for ; m > 0; m-- {
        a, _ := strconv.Atoi(reader.ReadLine()[2:])
        b, _ := strconv.Atoi(reader.ReadLine()[2:])
        b -= a
        if b%2 == 1 && b <= sa*2 {
            ss = append(ss, "1\n")
        } else {
            ss = append(ss, "0\n")
        }
    }
    fmt.Print(strings.Join(ss, ""))
}

func min(a, b int64) int64 {
    if a < b {
        return a
    }
    return b
}

