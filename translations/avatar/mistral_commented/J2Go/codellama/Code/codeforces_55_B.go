
package main

import (
    "fmt"
    "math"
)

var min int64 = math.MaxInt64

func main() {
    var arr []int64
    var ops []string

    for i := 0; i < 4; i++ {
        var num int64
        fmt.Scan(&num)
        arr = append(arr, num)
    }

    for i := 0; i < 3; i++ {
        var op string
        fmt.Scan(&op)
        ops = append(ops, op)
    }

    util(arr, ops, 0)

    fmt.Println(min)
}

func util(arr []int64, ops []string, idx int) {
    if idx == 3 {
        min = int64(math.Min(float64(min), float64(arr[0])))
        return
    }

    for i := 0; i < len(arr); i++ {
        for j := i + 1; j < len(arr); j++ {
            var a []int64

            for k := 0; k < len(arr); k++ {
                if k != j && k != i {
                    a = append(a, arr[k])
                }
            }

            var res int64

            if idx < 3 && ops[idx] == "+" {
                res = arr[i] + arr[j]
            } else {
                res = arr[i] * arr[j]
            }

            a = append(a, res)
            util(a, ops, idx+1)
        }
    }
}

