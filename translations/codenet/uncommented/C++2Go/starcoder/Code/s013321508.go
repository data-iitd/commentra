package main

import (
    "fmt"
    "sort"
)

func main() {

    var N, M int
    fmt.Scanf("%d %d\n", &N, &M)

    L := make([]int, 100000)
    var l int
    for i := 0; i < N; i++ {
        fmt.Scanf("%d\n", &l)
        L[i] = l
    }

    sort.Ints(L)

    for i := 0; i < M; i++ {
        max_L := L[len(L)-1]
        if max_L == 0 {
            break
        }

        max_L /= 2
        itr := sort.SearchInts(L, max_L)
        L = append(L[:itr], append([]int{max_L}, L[itr:]...)...)
        L = L[:len(L)-1]
    }

    ans := 0
    for _, l := range L {
        ans += l
    }

    fmt.Println(ans)

}

