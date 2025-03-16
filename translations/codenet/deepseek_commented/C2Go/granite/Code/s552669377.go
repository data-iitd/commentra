
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    n, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1])
    min := 1000000
    max := -1000000
    sum := 0
    for i := 0; i < n; i++ {
        tmp, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1])
        if min > tmp {
            min = tmp
        }
        if max < tmp {
            max = tmp
        }
        sum += tmp
    }
    fmt.Printf("%d %d %d\n", min, max, sum)
}

