
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    a, _ := strconv.Atoi(readerReadLine(reader)[0])
    b, _ := strconv.Atoi(readerReadLine(reader)[0])
    hole := 1
    i := 0
    check := true
    for check {
        if hole >= b {
            check = false
        } else {
            hole = a * (i + 1) - i
            i++
        }
    }
    fmt.Println(i)
}

func readerReadLine(reader *bufio.Reader) []string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.Split(string(str), " ")
    } else {
        panic(err)
    }
}

