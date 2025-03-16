
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    x1, _ := strconv.ParseInt(read(reader), 10, 64)
    y1, _ := strconv.ParseInt(read(reader), 10, 64)
    x2, _ := strconv.ParseInt(read(reader), 10, 64)
    y2, _ := strconv.ParseInt(read(reader), 10, 64)

    dx := x2 - x1
    dy := y2 - y1

    x3 := x2 - dy
    y3 := y2 + dx

    x4 := x1 - dy
    y4 := y1 + dx

    fmt.Println(x3, y3, x4, y4)
}

func read(reader *bufio.Reader) string {
    s, _ := reader.ReadString('\n')
    s = s[:len(s)-1]
    return s
}

