
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter rating: ")
    text, _ := reader.ReadString('\n')
    rating, _ := strconv.Atoi(text)

    if rating < 1200 {
        fmt.Println("ABC")
    } else if rating >= 2800 {
        fmt.Println("AGC")
    } else {
        fmt.Println("ARC")
    }
}

