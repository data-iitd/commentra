
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    x1, _ := strconv.ParseInt(nextString(reader), 10, 64)
    y1, _ := strconv.ParseInt(nextString(reader), 10, 64)
    x2, _ := strconv.ParseInt(nextString(reader), 10, 64)
    y2, _ := strconv.ParseInt(nextString(reader), 10, 64)
    dx := x2 - x1
    dy := y2 - y1
    x3 := x2 - dy
    y3 := y2 + dx
    x4 := x1 - dy
    y4 := y1 + dx
    fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
}

func nextString(reader *bufio.Reader) string {
    str, _ := reader.ReadString('\n')
    return str
}

