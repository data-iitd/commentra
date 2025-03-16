
package main

import (
    "fmt"
    "sort"
)

func main() {
    var N int
    fmt.Scan(&N)
    S := make([]int, 1<<N)
    spawned := make([]bool, 1<<N)
    spawned[1<<N-1] = true
    for i := 0; i < 1<<N; i++ {
        fmt.Scan(&S[i])
    }
    sort.Ints(S)
    active := make([]int, 1)
    active[0] = 1<<N - 1
    spawned[1<<N-1] = true
    for i := 0; i < N; i++ {
        sort.Sort(sort.Reverse(sort.IntSlice(active)))
        activated := make([]int, 0)
        next := 1<<N - 1
        for _, slime := range active {
            for next >= 0 && (S[next] >= slime || spawned[next]) {
                next--
            }
            if next < 0 {
                fmt.Println("No")
                return
            }
            spawned[next] = true
            activated = append(activated, S[next])
        }
        active = append(active, activated...)
    }
    fmt.Println("Yes")
}

