

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

    NTemp, err := reader.ReadString('\n')
    checkError(err)
    N, err := strconv.ParseInt(strings.TrimSpace(NTemp), 10, 64)
    checkError(err)

    var L []int64

    for i := 0; i < int(N); i++ {
        aTemp, err := reader.ReadString('\n')
        checkError(err)
        a, err := strconv.ParseInt(strings.TrimSpace(aTemp), 10, 64)
        checkError(err)
        L = append(L, a)
    }

    sort.Slice(L, func(i, j int) bool {
        return L[i] < L[j]
    })

    count := int64(0)

    for i := 0; i < int(N); i++ {
        for j := i + 1; j < int(N); j++ {
            a := L[i]
            b := L[j]
            res := find(L, j+1, a+b)
            count += res
        }
    }

    fmt.Println(count)
}

func find(li []int64, from int, target int64) int {
    low := from
    upp := len(li) - 1

    if upp-low < 0 {
        return 0
    } else if li[from] >= target {
        return 0
    } else if li[upp] < target {
        return upp - low + 1
    }

    for upp-low > 1 {
        mid := (upp-low+1)%2 == 0? (low+upp)/2+1 : (low+upp)/2
        if li[mid] >= target {
            upp = mid
        } else {
            low = mid
        }
    }

    return low - from + 1
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

