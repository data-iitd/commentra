
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
    c, _ := strconv.Atoi(read(reader))
    d, _ := strconv.Atoi(read(reader))
    e, _ := strconv.Atoi(read(reader))
    k, _ := strconv.Atoi(read(reader))

    if e-a <= k {
        fmt.Println("Yay!")
    } else {
        fmt.Println(":(")
    }
}

func read(reader *bufio.Reader) string {
    s, _ := reader.ReadString('\n')
    s = s[:len(s)-1]
    return s
}

