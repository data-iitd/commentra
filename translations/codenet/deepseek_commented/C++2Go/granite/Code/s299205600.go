
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    a, _ := strconv.Atoi(reader.ReadLine())
    b, _ := strconv.Atoi(reader.ReadLine())
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

