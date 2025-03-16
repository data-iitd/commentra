
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    aStr, _ := reader.ReadString('\n')
    bStr, _ := reader.ReadString('\n')
    a, _ := strconv.Atoi(aStr)
    b, _ := strconv.Atoi(bStr)
    ans := 0
    out := 1
    for out < b {
        out--
        out += a
        ans++
    }
    fmt.Println(ans)
}

