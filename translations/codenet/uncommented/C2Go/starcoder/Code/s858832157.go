package main

import (
    "fmt"
    "os"
    "bufio"
    "strconv"
)

func main() {
    var i int = 1
    scanner := bufio.NewScanner(os.Stdin)
    for scanner.Scan() {
        input, _ := strconv.Atoi(scanner.Text())
        if input == 0 {
            break
        }
        fmt.Printf("Case %d: %d\n", i, input)
        i++
    }
}

