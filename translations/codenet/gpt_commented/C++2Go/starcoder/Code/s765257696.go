package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Optimize input/output operations
    bufio.NewReader(os.Stdin)
    fmt.Println("Enter the number of elements: ")
    var n, ans int
    fmt.Scanf("%d\n", &n)
    var p [n]int
    fmt.Println("Enter the elements: ")
    for i := 0; i < n; i++ {
        fmt.Scanf("%d\n", &p[i])
    }
    for i := 0; i < n - 2; i++ {
        if p[i] > p[i+1] && p[i+1] > p[i+2] {
            ans++
        }
        if p[i] < p[i+1] && p[i+1] < p[i+2] {
            ans++
        }
    }
    fmt.Println(ans)
}

