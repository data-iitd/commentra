

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
    a, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    b, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    c, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    d, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

    if c > b {
        fmt.Println(0)
    } else if a > d {
        fmt.Println(0)
    } else if a < c {
        fmt.Println(min(b, d) - c)
    } else {
        l := []int{a, b, c, d}
        sort(l)
        fmt.Println(l[2] - l[1])
    }
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    panic(err)
}

func min(a, b int) int {
    if a <= b {
        return a
    }
    return b
}

func sort(l []int) {
    for i := 0; i < len(l); i++ {
        for j := i + 1; j < len(l); j++ {
            if l[i] > l[j] {
                l[i], l[j] = l[j], l[i]
            }
        }
    }
}

// Translate the given Java code to Go and end with the comment "