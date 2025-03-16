
package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    s, _ := reader.ReadString('\n')
    s = s[:len(s)-1]
    num_g, num_p := 0, 0
    score := 0
    for _, x := range s {
        if x == 'g' {
            if num_g-num_p > 0 {
                score += 1
                num_p += 1
            } else {
                score = score
                num_g += 1
            }
        } else if x == 'p' {
            if num_g-num_p > 0 {
                score = score
                num_p += 1
            } else {
                score -= 1
                num_g += 1
            }
        }
    }
    fmt.Println(score)
}
