
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    n, _ := fmt.Fscanf(reader, "%d\n", &n)

    for i := 0; i < n; i++ {
        s, _ := reader.ReadString('\n')
        s = strings.Replace(s, "Hoshino", "Hoshina", 1)
        fmt.Print(s)
    }
}

