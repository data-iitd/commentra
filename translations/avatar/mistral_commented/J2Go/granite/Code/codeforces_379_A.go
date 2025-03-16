

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("Enter the first integer value:")
    a, _ := strconv.Atoi(reader.ReadLine())
    fmt.Println("Enter the second integer value:")
    b, _ := strconv.Atoi(reader.ReadLine())
    res := a
    for a >= b {
        res += a / b
        a = a/b + a%b
    }
    fmt.Println(res)
}

