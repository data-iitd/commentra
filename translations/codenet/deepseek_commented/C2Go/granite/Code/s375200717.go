
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
    fmt.Print("Enter an integer: ")
    text, _ := reader.ReadString('\n')
    n, _ := strconv.Atoi(strings.TrimSpace(text))

    for i := 1; i <= n; i++ {
        a := i
        if a%3 == 0 {
            fmt.Printf(" %d", i)
        } else {
            for ; a > 0; {
                if a%10 == 3 {
                    fmt.Printf(" %d", i)
                    a = 0
                }
                a = a / 10
            }
        }
    }
    fmt.Println()
}

