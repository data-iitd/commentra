
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    alpha := make(map[string]int)

    for {
        line, _, err := reader.ReadLine()
        if err!= nil {
            break
        }

        lineStr := strings.ToLower(string(line))
        for _, ch := range lineStr {
            if ch >= 'a' && ch <= 'z' {
                alpha[string(ch)]++
            }
        }
    }

    for ch, count := range alpha {
        fmt.Printf("%s : %d\n", ch, count)
    }
}

