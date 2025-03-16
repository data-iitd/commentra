<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func calc_score() int {
    out := 0
    score := 0
    base := 0
    for out < 3 {
        str, _ := bufio.NewReader(os.Stdin).ReadString('\n')
        str = strings.TrimSpace(str)
        if str == "OUT" {
            out++
        } else if str == "HIT" {
            if base == 3 {
                score++
            } else {
                base++
            }
        } else if str == "HOMERUN" {
            score += (base + 1)
            base = 0
        }
    }
    return score
}

func main() {
    n, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadString('\n'))
    for inning := 0; inning < n; inning++ {
        fmt.Println(calc_score())
    }
}

