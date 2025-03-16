

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter the first integer: ")
    a, _ := strconv.Atoi(reader.ReadString('\n')[0 : len(reader.ReadString('\n')[0])-1])
    fmt.Print("Enter the second integer: ")
    b, _ := strconv.Atoi(reader.ReadString('\n')[0 : len(reader.ReadString('\n')[0])-1])
    res := a
    for a >= b {
        res += a / b
        a = a/b + a%b
    }
    fmt.Println(res)
}

