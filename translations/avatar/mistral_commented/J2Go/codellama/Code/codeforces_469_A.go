
package main

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    var n, levels, level2 int
    var sum, sum2, sum3 int
    var arr, arr2, arr3 []int
    var count int

    n, _ = strconv.Atoi(os.Args[1])
    levels, _ = strconv.Atoi(os.Args[2])
    level2, _ = strconv.Atoi(os.Args[3])

    arr = make([]int, levels)
    arr2 = make([]int, levels+level2)
    arr3 = make([]int, n)

    for i := 0; i < levels; i++ {
        arr[i], _ = strconv.Atoi(os.Args[4+i])
    }

    for i := 0; i < levels+level2; i++ {
        if i < levels {
            arr2[i] = arr[i]
        } else {
            arr2[i], _ = strconv.Atoi(os.Args[4+levels+i-levels])
        }
    }

    for i := 0; i < n; i++ {
        arr3[i] = i + 1
    }

    for i := 0; i < n; i++ {
        for x := 0; x < len(arr2); x++ {
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

