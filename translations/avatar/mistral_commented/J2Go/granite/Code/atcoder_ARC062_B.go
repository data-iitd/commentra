

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
    writer := bufio.NewWriter(os.Stdout)

    var S string
    fmt.Fscan(reader, &S)

    score := 0
    for i := 0; i < len(S); i++ {
        my := 'g'
        if i%2 == 0 {
            my = 'p'
        }
        his := S[i]
        if my!= his {
            if my == 'p' {
                score++
            } else {
                score--
            }
        }
    }

    fmt.Fprintln(writer, score)

    writer.Flush()
}

These comments should provide a good understanding of what each part of the code does. Let me know if you need any further clarification!