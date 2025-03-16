
package main

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    var n int
    var list []int64
    var odd []int64
    var sum int64

    fmt.Scan(&n)

    for i := 0; i < n; i++ {
        var num int64
        fmt.Scan(&num)
        list = append(list, num)
    }

    for _, num := range list {
        if num%2 == 0 {
            sum += num
        } else {
            odd = append(odd, num)
        }
    }

    sort.Slice(odd, func(i, j int) bool {
        return odd[i] < odd[j]
    })

    for _, num := range odd {
        sum += num
    }

    if len(odd)%2 != 0 {
        sum -= odd[0]
    }

    fmt.Println(sum)
}

