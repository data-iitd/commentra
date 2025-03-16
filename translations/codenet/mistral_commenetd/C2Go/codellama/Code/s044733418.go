
package main

import "fmt"
import "sort"

func compare(a, b int) int {
    return b - a
}

func main() {
    var array [10]int
    for i := 0; i < 10; i++ {
        fmt.Scan(&array[i])
    }
    sort.Ints(array[:], compare)
    for i := 0; i < 3; i++ {
        fmt.Println(array[i])
    }
}

