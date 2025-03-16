
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

    fmt.Println("Enter the number of elements")
    N, err := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
    checkError(err)

    fmt.Println("Enter the list of integers")
    P := make([]int, N)
    for i := 0; i < N; i++ {
        P[i], err = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
        checkError(err)
    }

    editorial(N, P)
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

func editorial(N int, P []int) {
    a := make([]int, N+1)
    for i, p := range P {
        a[p] = i
    }

    tmp := 1
    max_len := 1
    for i := 1; i < N; i++ {
        if a[i] < a[i+1] {
            tmp += 1
            max_len = max(max_len, tmp)
        } else {
            tmp = 1
    }

    ans := N - max_len
    fmt.Println(ans)
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

