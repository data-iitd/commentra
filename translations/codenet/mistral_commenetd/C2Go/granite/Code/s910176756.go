
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    for {
        aStr, err := reader.ReadString(' ')
        if err!= nil {
            break
        }
        a, err := strconv.Atoi(aStr)
        if err!= nil {
            break
        }
        op, err := reader.ReadByte()
        if err!= nil {
            break
        }
        bStr, err := reader.ReadString('\n')
        if err!= nil {
            break
        }
        b, err := strconv.Atoi(bStr)
        if err!= nil {
            break
        }
        var c int
        switch op {
        case '+':
            c = a + b
        case '-':
            c = a - b
        case '*':
            c = a * b
        case '/':
            c = a / b
        default:
            break
        }
        fmt.Println(c)
    }
}

