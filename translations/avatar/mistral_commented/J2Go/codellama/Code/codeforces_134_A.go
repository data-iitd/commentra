
package main

import (
    "fmt"
    "strconv"
)

func main() {
    var n int
    fmt.Scan(&n)
    arr := make([]int, n)
    var sum int
    for i := 0; i < n; i++ {
        fmt.Scan(&arr[i])
        sum += arr[i]
    }
    var c int
    var sb strings.Builder
    for i := 0; i < n; i++ {
        if (sum-arr[i])%(n-1) == 0 && (sum-arr[i])/(n-1) == arr[i] {
            c++
            sb.WriteString(strconv.Itoa(i+1) + " ")
        }
    }
    fmt.Println(c)
    fmt.Println(sb.String())
}

