
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
    n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadLine()))
    l1 := make([]int, n)
    for i := 0; i < n; i++ {
        l1[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadLine()))
    }
    min := l1[0]
    max := l1[0]
    for i := 1; i < n; i++ {
        if l1[i] < min {
            min = l1[i]
        }
        if l1[i] > max {
            max = l1[i]
        }
    }
    if min == max {
        fmt.Printf("%d %d\n", max-min, n*(n-1)/2)
    } else {
        minCount := 0
        maxCount := 0
        for i := 0; i < n; i++ {
            if l1[i] == min {
                minCount++
            }
            if l1[i] == max {
                maxCount++
            }
        }
        fmt.Printf("%d %d\n", max-min, minCount*maxCount)
    }
}
