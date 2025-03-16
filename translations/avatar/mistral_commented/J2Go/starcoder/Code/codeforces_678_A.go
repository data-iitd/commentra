
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
    fmt.Print("Enter n: ")
    n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
    fmt.Print("Enter k: ")
    k, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
    n++
    z := 0
    if n%k!= 0 {
        z = k - n%k
    }
    fmt.Println(n + z)
}

