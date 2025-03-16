
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    n, _ := strconv.Atoi(reader.ReadLine())
    sum := 0
    min := 0
    max := 0
    for i := 0; i < n; i++ {
        m, _ := strconv.Atoi(reader.ReadLine())
        sum += m
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

