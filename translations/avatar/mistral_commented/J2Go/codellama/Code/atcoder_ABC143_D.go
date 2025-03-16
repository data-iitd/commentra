
package main

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    var N int
    var L []int
    var count int

    fmt.Scan(&N)

    L = make([]int, N)

    for i := 0; i < N; i++ {
        fmt.Scan(&L[i])
    }

    sort.Ints(L)

    for i := 0; i < N; i++ {
        for j := i + 1; j < N; j++ {
            a := L[i]
            b := L[j]
            res := find(L, j+1, a+b)
            count += res
        }
    }

    fmt.Println(count)
}

func find(L []int, from int, target int) int {
    low := from
    upp := len(L) - 1
    mid := 0

    if upp-low < 0 {
        return 0
    } else if L[from] >= target {
        return 0
    } else if L[upp] < target {
        return upp - low + 1
    }

    for upp-low > 1 {
        mid = (upp-low+1)/2 + 1

        if L[mid] >= target {
            upp = mid
        } else {
            low = mid
        }
    }

    return low - from + 1
}

