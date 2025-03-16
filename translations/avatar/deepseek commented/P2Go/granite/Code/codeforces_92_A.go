

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    fmt.Print("Enter the value of n: ")
    n, _ := reader.ReadString('\n')
    n, _ = strconv.Atoi(n)

    fmt.Print("Enter the value of m: ")
    m, _ := reader.ReadString('\n')
    m, _ = strconv.Atoi(m)

    i := 1
    for m >= i {
        m -= i
        i = (i % n) + 1
    }

    fmt.Println("The value of m after the loop is:", m)
}

