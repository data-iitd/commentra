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

func main() {
    var sum int64 = 0
    var n int
    var m int
    var i int
    var min int
    var max int

    reader := bufio.NewReader(os.Stdin)
    fmt.Fscan(reader, &n)

    for i = 0; i < n; i++ {
        fmt.Fscan(reader, &m)
        sum += int64(m)

        if i == 0 {
            min = m
            max = m
        }

        if min > m {
            min = m
        }

        if max < m {
            max = m
        }
    }

    fmt.Printf("%d %d %d\n", min, max, sum)
}

