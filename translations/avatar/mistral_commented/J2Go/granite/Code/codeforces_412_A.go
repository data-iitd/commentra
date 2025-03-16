
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

    var n, k int
    var a string

    fmt.Fscanf(reader, "%d\n", &n)
    fmt.Fscanf(reader, "%d\n", &k)
    fmt.Fscanf(reader, "%s\n", &a)

    if k > n/2 {
        for k < n {
            fmt.Println("RIGHT")
            k++
        }
    } else {
        for k > 1 {
            fmt.Println("LEFT")
            k--
        }
    }

    if k == 1 {
        for i, char := range a {
            fmt.Println("PRINT", string(char))
            if i < len(a)-1 {
                fmt.Println("RIGHT")
            }
        }
    } else {
        for i := len(a) - 1; i >= 0; i-- {
            fmt.Println("PRINT", string(a[i]))
            if i > 0 {
                fmt.Println("LEFT")
            }
        }
    }
}

