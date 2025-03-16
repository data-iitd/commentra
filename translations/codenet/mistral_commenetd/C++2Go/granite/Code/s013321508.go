

package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    var N, M int
    fmt.Fscanf(reader, "%d %d\n", &N, &M)

    L := make([]int, N)
    for i := 0; i < N; i++ {
        fmt.Fscanf(reader, "%d", &L[i])
    }

    sort.Ints(L)

    for i := 0; i < M; i++ {
        maxL := L[len(L)-1]
        if maxL == 0 {
            break
        }
        maxL /= 2
        pos := sort.SearchInts(L, maxL)
        L = append(L[:pos], append([]int{maxL}, L[pos:]...)...)
        L = L[:len(L)-1]
    }

    ans := int64(0)
    for _, v := range L {
        ans += int64(v)
    }
    fmt.Println(ans)
}

