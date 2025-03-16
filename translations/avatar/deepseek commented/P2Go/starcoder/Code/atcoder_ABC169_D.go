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
    if n == 1 {
        fmt.Println(0)
        return
    }
    fac := make(map[int]int)
    for i := 2; i <= n; i++ {
        for j := 2; j <= i; j++ {
            if i%j == 0 {
                fac[j]++
                break
            }
        }
    }
    ans := 0
    for p, e := range fac {
        x := e
        for i := 1; i < 99999999; i++ {
            if x >= i {
                x -= i
                ans += 1
            } else {
                break
            }
        }
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

