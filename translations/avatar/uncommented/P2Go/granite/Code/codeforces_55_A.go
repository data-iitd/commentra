
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
    n, _ := strconv.Atoi(text)
    for n%2 == 0 {
        n /= 2
    }
    if n == 1 {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
}
