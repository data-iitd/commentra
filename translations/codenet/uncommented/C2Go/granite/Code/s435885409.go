
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
        for out := 0; out < 3; {
            line, _ := reader.ReadString('\n')
            line = strings.TrimSpace(line)
            if line == "OUT" {
                out++
            } else if line == "HIT" {
                if base == 3 {
                    score++
                } else {
                    base++
                }
            } else if line == "HOMERUN" {
                score += base + 1
                base = 0
            }
        }
        fmt.Println(score)
    }
}

