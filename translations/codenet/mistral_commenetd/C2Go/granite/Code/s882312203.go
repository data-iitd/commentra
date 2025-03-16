

package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter a string: ")
    s, _ := reader.ReadString('\n')
    s = strings.TrimSpace(s)

    for j := 0; j < len(s); j++ {
        for i := 0; i < len(s); i++ {
            if i!= j && s[i] == s[j] {
                fmt.Println("no")
                return
            }
        }
    }

    fmt.Println("yes")
}

