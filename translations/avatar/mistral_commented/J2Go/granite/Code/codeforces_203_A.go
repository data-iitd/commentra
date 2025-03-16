
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

    x, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    t, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    a, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    b, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    da, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    db, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

    first := 0
    second := 0
    ok := false

    for i := 0; i < t; i++ {
        first = a - (da * i)
        for j := 0; j < t; j++ {
            second = b - (db * j)

            if second+first == x || second == x || first == x || x == 0 {
                ok = true
                break
            }
        }
    }

    if ok {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.Trim(string(str), "\r\n")
    }
    return ""
}

