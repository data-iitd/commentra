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
    n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    a := make([]int, n)
    for i := 0; i < n; i++ {
        a[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
    }
    abs_a := make([]int, n)
    for i := 0; i < n; i++ {
        if a[i] < 0 {
            abs_a[i] = -a[i]
        } else {
            abs_a[i] = a[i]
        }
    }
    ans := 0
    min := abs_a[0]
    for _, e := range abs_a {
        ans += e
        if min > e {
            min = e
        }
    }
    num_negative := 0
    for _, e := range a {
        if e < 0 {
            num_negative++
        }
    }
    if num_negative%2 == 1 {
        ans -= min * 2
    }
    fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}

