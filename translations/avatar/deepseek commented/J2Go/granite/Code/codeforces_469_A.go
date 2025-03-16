

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
    var n, levels, sum, sum2, sum3, count int
    fmt.Fscanf(reader, "%d\n", &n)
    fmt.Fscanf(reader, "%d\n", &levels)
    arr := make([]int, levels)
    for i := 0; i < levels; i++ {
        fmt.Fscanf(reader, "%d", &arr[i])
    }
    fmt.Fscanf(reader, "%d\n", &sum2)
    level3 := levels + sum2
    arr2 := make([]int, level3)
    for i := 0; i < levels; i++ {
        arr2[i] = arr[i]
    }
    for i := levels; i < level3; i++ {
        fmt.Fscanf(reader, "%d", &arr2[i])
    }
    arr3 := make([]int, n)
    j := 0
    for i := 0; i < n; i++ {
        j++
        arr3[i] = j
    }
    for i := 0; i < n; i++ {
        for x := 0; x < level3; x++ {
            if arr3[i] == arr2[x] {
                count++
                break
            }
        }
    }
    if count == n {
        fmt.Println("I become the guy.")
    } else {
        fmt.Println("Oh, my keyboard!")
    }
}

