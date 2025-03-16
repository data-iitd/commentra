
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    s := bufio.NewScanner(os.Stdin)
    s.Scan()
    line := s.Text()

    for j := 0; j < len(line); j++ {
        for i := 0; i < len(line); i++ {
            if i!= j && string(line[i]) == string(line[j]) {
                fmt.Println("no")
                return
            }
        }
    }

    fmt.Println("yes")
}

