
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    aStr, _ := reader.ReadString('\n')
    a, _ := strconv.Atoi(aStr)

    bStr, _ := reader.ReadString('\n')
    b, _ := strconv.Atoi(bStr)

    sum := 0

    for i := 0; i < 2; i++ {
        if a >= b {
            sum += a
            a--
        } else {
            sum += b
            b--
        }
    }

    fmt.Println(sum)
}

