
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    s, _ := reader.ReadString('\n')
    nTemp, _ := reader.ReadString('\n')

    n, _ := strconv.Atoi(nTemp)

    ans := 0

    for i := 0; i < n; i++ {
        x, _ := reader.ReadString('\n')

        a, b := 0, 0

        for _, j := range s {
            if string(j) == string(x[0]) {
                a++
            } else if string(j) == string(x[1]) {
                b++
            } else {
                ans += int(Min(uint64(a), uint64(b)))
                a, b = 0, 0
            }
        }

        ans += int(Min(uint64(a), uint64(b)))
    }

    fmt.Println(ans)
}

func Min(x, y uint64) uint64 {
    if x < y {
        return x
    }

    return y
}

