
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

    Q, _ := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
    H, _ := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
    S, _ := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
    D, _ := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
    N, _ := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)

    onePrice := int64(0)
    if Q*4 < H*2 {
        if Q*4 < S {
            onePrice = Q * 4
        } else {
            onePrice = S
        }
    } else {
        if H*2 < S {
            onePrice = H * 2
        } else {
            onePrice = S
        }
    }

    if float64(onePrice) <= float64(D)/2 {
        fmt.Println(N * onePrice)
    } else {
        fmt.Println((N/2)*D + (N%2)*onePrice)
    }
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    panic(err)
}

