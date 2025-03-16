
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
    fmt.Print("Enter a string: ")
    str, _ := reader.ReadString('\n')
    str = strings.TrimSpace(str)
    k, _ := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
    n := len(str)
    for i := int64(0); i < k; i++ {
        if str[i] == '1' {
            if i == k-1 {
                fmt.Println(1)
                return
            }
        } else {
            fmt.Println(string(str[i]))
            return
        }
    }
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    return ""
}

