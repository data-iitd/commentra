

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
    n, _ := strconv.Atoi(reader.ReadString('\n')[0 : len(reader.ReadString('\n')[0])-1])
    fmt.Print("Enter the second integer: ")
    m, _ := strconv.Atoi(reader.ReadString('\n')[0 : len(reader.ReadString('\n')[0])-1])

    if n == 0 {
        if m!= 0 {
            fmt.Println("Impossible")
        } else {
            fmt.Println("0 0")
        }
        return
    }

    if m <= n {
        if m == 0 {
            m = 1
        }
        fmt.Println(n, m+n-1)
        return
    }

    fmt.Println(m, m+n-1)
}

