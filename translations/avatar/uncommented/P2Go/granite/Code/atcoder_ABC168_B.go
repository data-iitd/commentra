
package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    K, _ := fmt.Fscanf(reader, "%d\n")
    S, _ := fmt.Fscanf(reader, "%s\n")

    if len(S) <= int(K) {
        fmt.Println(S)
    } else {
        fmt.Println(S[:K] + "...")
    }
}

