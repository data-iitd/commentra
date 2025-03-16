
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("Enter two integers:")
    aStr, _ := reader.ReadString('\n')
    bStr, _ := reader.ReadString('\n')
    a, _ := strconv.Atoi(aStr)
    b, _ := strconv.Atoi(bStr)
    if a <= 8 && b <= 8 {
        fmt.Println("Yay!")
    } else {
        fmt.Println(":(")
    }
}

