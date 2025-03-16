
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    N, _ := reader.ReadString('\n')
    N = N[:len(N)-1]
    S := 0
    for _, n := range N {
        S += int(n - '0')
    }
    if s, _ := strconv.Atoi(N); s%S == 0 {
        fmt.Println("Yes")
    } else {
        fmt.Println("No")
    }
}

