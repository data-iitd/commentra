

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    v1, _ := reader.ReadString('\n')
    v2, _ := reader.ReadString('\n')
    t, _ := reader.ReadString('\n')
    d, _ := reader.ReadString('\n')

    v1, _ = strconv.Atoi(v1)
    v2, _ = strconv.Atoi(v2)
    t, _ = strconv.Atoi(t)
    d, _ = strconv.Atoi(d)

    a := 1
    v := v1
    distance := 0

    for i := 0; i < t; i++ {
        if v - v2 > (t - i - 1) * d {
            a *= -1
            v = (t - i - 1) * d + v2
        }
        distance += v
        v += a * d
    }

    fmt.Println(distance)
}
