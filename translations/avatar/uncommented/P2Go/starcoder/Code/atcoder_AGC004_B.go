package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)

    input, err := reader.ReadString('\n')
    if err!= nil {
        panic(err)
    }
    n, err := strconv.Atoi(strings.TrimSpace(input))
    if err!= nil {
        panic(err)
    }
    a := make([]int, n)
    for i := 0; i < n; i++ {
        input, err = reader.ReadString('\n')
        if err!= nil {
            panic(err)
        }
        a[i], err = strconv.Atoi(strings.TrimSpace(input))
        if err!= nil {
            panic(err)
        }
    }
    b := make([][]int, n)
    for i := 0; i < n; i++ {
        b[i] = make([]int, n)
    }
    for i := 0; i < n; i++ {
        m := a[i]
        for j := 0; j < n; j++ {
            k := i - j
            if k < 0 {
                k += n
            }
            m = min(m, a[k])
            b[j][i] = m
    }
    m := 1000000000
    for i, j := range b {
        m = min(m, sum(j) + i * x)
    }
    fmt.Println(m)
}

func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}

func sum(a []int) int {
    s := 0
    for _, x := range a {
        s += x
    }
    return s
}

