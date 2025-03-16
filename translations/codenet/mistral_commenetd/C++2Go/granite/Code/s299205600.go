

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    fmt.Print("Enter first integer: ")
    a, _ := strconv.Atoi(reader.ReadString('\n')[0 : len(reader.ReadString('\n')[0])-1])

    fmt.Print("Enter second integer: ")
    b, _ := strconv.Atoi(reader.ReadString('\n')[0 : len(reader.ReadString('\n')[0])-1])

    var result int

    if a > b {
        result = 2*a - 1
    } else if a == b {
        result = 2 * a
    } else {
        result = 2*b - 1
    }

    fmt.Println(result)
}

