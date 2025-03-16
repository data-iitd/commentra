

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

    A, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    B, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

    if A == 0 {
        if B == 0 {
            fmt.Println(1)
        } else {
            fmt.Println("No solution")
        }
        return
    }

    if B%A!= 0 {
        fmt.Println("No solution")
        return
    }

    B /= A
    neg := B < 0

    if neg && n%2 == 0 {
        fmt.Println("No solution")
        return
    }

    if neg {
        B = -B
    }

    for x := 0; x <= B; x++ {
        if int(pow(int64(x), int64(n))) == B {
            if neg {
                fmt.Println(-x)
            } else {
                fmt.Println(x)
            }
            return
        }
    }

    fmt.Println("No solution")
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    panic(err)
}

func pow(x, n int64) int64 {
    if n == 0 {
        return 1
    }
    if n%2 == 0 {
        return pow(x*x, n/2)
    }
    return x * pow(x*x, (n-1)/2)
}

