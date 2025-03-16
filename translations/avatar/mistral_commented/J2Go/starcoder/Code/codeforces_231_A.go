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
    t, _ := strconv.Atoi(readLine(reader))
    count := 0
    for t > 0 {
        a, _ := strconv.Atoi(readLine(reader))
        b, _ := strconv.Atoi(readLine(reader))
        c, _ := strconv.Atoi(readLine(reader))
        if a == 1 || b == 1 || c == 1 || a == 1 && b == 1 && c == 1 {
            count++
        }
        t--
    }
    fmt.Println(count)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}

