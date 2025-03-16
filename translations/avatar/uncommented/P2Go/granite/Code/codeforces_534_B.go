
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

var (
    v1, v2, t, d int
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    v1Str, _ := reader.ReadString('\n')
    v2Str, _ := reader.ReadString('\n')
    tStr, _ := reader.ReadString('\n')
    dStr, _ := reader.ReadString('\n')
    v1, _ = strconv.Atoi(v1Str)
    v2, _ = strconv.Atoi(v2Str)
    t, _ = strconv.Atoi(tStr)
    d, _ = strconv.Atoi(dStr)
    a := 1
    v := v1
    distance := 0
    for i := 0; i < t; i++ {
        if v-v2 > (t-i-1)*d {
            a *= -1
            v = (t-i-1)*d + v2
        }
        distance += v
        v += a * d
    }
    fmt.Println(distance)
}
