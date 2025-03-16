

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
    bStr, _ := reader.ReadString('\n')

    a, _ := strconv.Atoi(aStr)
    b, _ := strconv.Atoi(bStr)

    c := 0

    for i := 0; i < 2; i++ {
        c += int(math.Max(float64(a), float64(b)))
        if a >= b {
            a--
        } else {
            b--
        }
    }

    fmt.Println(c)
}

