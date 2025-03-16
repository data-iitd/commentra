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
    fmt.Println("Enter three integers:")
    a, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
    b, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
    c, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))

    if a > b {
        a, b = b, a
    }
    if b > c {
        b, c = c, b
    }
    if a > b {
        a, b = b, a
    }

    fmt.Println(a, b, c)
}

