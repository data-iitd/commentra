
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

    h = strings.TrimSpace(h)
    a = strings.TrimSpace(a)

    hInt, _ := strconv.Atoi(h)
    aInt, _ := strconv.Atoi(a)

    sho := hInt / aInt
    am := hInt % aInt

    if am!= 0 {
        sho += 1
    }

    fmt.Println(sho)
}

