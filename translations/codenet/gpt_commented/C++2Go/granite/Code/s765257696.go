
package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    var n int
    fmt.Fscanf(reader, "%d\n", &n)

    p := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Fscanf(reader, "%d", &p[i])
    }

    ans := 0
    for i := 0; i < n-2; i++ {
        if p[i] > p[i+1] && p[i+1] > p[i+2] {
            ans++
        }
        if p[i] < p[i+1] && p[i+1] < p[i+2] {
            ans++
        }
    }

    fmt.Println(ans)
}

