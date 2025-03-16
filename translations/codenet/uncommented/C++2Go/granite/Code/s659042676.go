
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    a, _ := strconv.Atoi(read(reader))
    b, _ := strconv.Atoi(read(reader))
    fmt.Println(6 - a - b)
}

func read(reader *bufio.Reader) string {
    s, _ := reader.ReadString('\n')
    s = s[:len(s)-1]
    return s
}

