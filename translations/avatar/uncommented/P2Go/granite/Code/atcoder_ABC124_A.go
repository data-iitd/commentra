
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    a, _ := strconv.Atoi(reader.ReadString('\n')[0 : len(reader.ReadString('\n')[0])-1])
    b, _ := strconv.Atoi(reader.ReadString('\n')[0 : len(reader.ReadString('\n')[0])-1])
    c := 0
    for i := 0; i < 2; i++ {
        c += int(Max(int64(a), int64(b)))
        if a >= b {
            a -= 1
        } else {
            b -= 1
        }
    }
    fmt.Println(c)
}

func Max(a, b int64) int64 {
    if a > b {
        return a
    }
    return b
}
