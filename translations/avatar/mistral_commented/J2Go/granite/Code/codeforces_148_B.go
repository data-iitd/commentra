
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

    VP, _ := strconv.ParseFloat(strings.TrimSpace(readLine(reader)), 64)
    VD, _ := strconv.ParseFloat(strings.TrimSpace(readLine(reader)), 64)
    T, _ := strconv.ParseFloat(strings.TrimSpace(readLine(reader)), 64)
    F, _ := strconv.ParseFloat(strings.TrimSpace(readLine(reader)), 64)
    C, _ := strconv.ParseFloat(strings.TrimSpace(readLine(reader)), 64)

    if VD <= VP {
        fmt.Println("0")
        return
    }

    answer := 0
    start := T

    for {
        x := start * VP / (VD - VP)

        if (start+x)*VP >= C {
            break
        }

        start += 2*x + F
        answer++
    }

    fmt.Println(answer)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    return ""
}

