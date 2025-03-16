
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    h, _ := reader.ReadString('\n')
    a, _ := reader.ReadString('\n')
    h, _ = strconv.Atoi(string(h[:len(h)-1]))
    a, _ = strconv.Atoi(string(a[:len(a)-1]))
    sho := h / a
    am := h % a
    if am!= 0 {
        sho += 1
    }
    fmt.Println(sho)
}
