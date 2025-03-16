

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
    str, _ := reader.ReadString('\n')
    str = strings.TrimSpace(str)
    c := []rune(str)
    k, _ := strconv.ParseInt(strings.TrimSpace(reader.ReadLine()), 10, 64)
    n := len(str)

    for i := int64(0); i < k; i++ {
        if c[i] == '1' {
            if i == k-1 {
                fmt.Println(1)
                return
            }
        } else {
            fmt.Println(string(c[i]))
            return
        }
    }
}

