
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
    n, _ := strconv.Atoi(reader.ReadLine()[2:])
    for i := 0; i < n; i++ {
        score := 0
        base := 0
        out := 0
        for out < 3 {
            line := reader.ReadLine()
            if string(line) == "OUT" {
                out++
            } else if string(line) == "HIT" {
                if base == 3 {
                    score++
                } else {
                    base++
                }
            } else if string(line) == "HOMERUN" {
                score += base + 1
                base = 0
            }
        }
        fmt.Println(score)
    }
}

