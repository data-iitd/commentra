
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter a number: ")
    text, _ := reader.ReadString('\n')
    number, _ := strconv.Atoi(text)
    for i := number; i > 0; i-- {
        if number%i == 0 {
            number = i
            fmt.Print(i, " ")
        }
    }
    fmt.Println()
}
