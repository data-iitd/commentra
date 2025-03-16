
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    r := bufio.NewReader(os.Stdin)
    line, _, err := r.ReadLine()
    if err!= nil {
        panic(err)
    }
    s := string(line)
    fmt.Printf("%c%d%c\n", s[0], len(s)-3, s[len(s)-2])
}

