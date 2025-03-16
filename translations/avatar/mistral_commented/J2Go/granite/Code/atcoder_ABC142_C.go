
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
    var N int
    fmt.Fscanf(reader, "%d\n", &N)

    idorder := make(map[int]int)

    for i := 1; i <= N; i++ {
        var A int
        fmt.Fscanf(reader, "%d\n", &A)
        idorder[A] = i
    }

    for i := 1; i <= N; i++ {
        fmt.Printf("%d ", idorder[i])
    }

    fmt.Println()
}

