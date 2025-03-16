package main

import (
    "fmt"
    "os"
    "bufio"
    "strings"
    "strconv"
)

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    for scanner.Scan() {
        line := scanner.Text()
        fmt.Println(line)
    }
}

