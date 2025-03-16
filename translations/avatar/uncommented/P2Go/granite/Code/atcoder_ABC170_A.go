
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
    fmt.Println("Enter a list of integers separated by spaces:")
    input, _ := reader.ReadString('\n')
    input = strings.TrimSpace(input)
    numbers := strings.Split(input, " ")
    for index, number := range numbers {
        if number == "0" {
            fmt.Println("Index:", index+1)
            break
        }
    }
}
