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
    fmt.Fprint(os.Stderr, "Enter the number of elements: ")
    n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
    fmt.Fprint(os.Stderr, "Enter the elements: ")
    a := make([]int, n)
    for i := 0; i < n; i++ {
        a[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
    }
    max_val := 0
    max_sign := 0
    max_index := -1
    for i, a0 := range a {
        if a0 > max_val {
            max_val = a0
            max_sign = 1
            max_index = i
        } else if a0 < max_val {
            max_val = a0
            max_sign = -1
            max_index = i
        }
    }
    if max_sign == 0 {
        fmt.Println(0)
    } else if max_sign == 1 {
        fmt.Println(2 * n - 1)
        for i := 0; i < n; i++ {
            fmt.Println(max_index + 1, i + 1)
        }
        for i := 0; i < n - 1; i++ {
            fmt.Println(i + 1, i + 2)
        }
    } else {
        fmt.Println(2 * n - 1)
        for i := 0; i < n; i++ {
            fmt.Println(max_index + 1, i + 1)
        }
        for i := n - 1; i > 0; i-- {
            fmt.Println(i + 2, i + 1)
        }
    }
}

