
package main

import "fmt"

func main() {
    var li []int
    var ind int
    for i := 1; i <= 371; i++ {
        var temp []int
        p, q := i, i
        count := 0
        for p != 0 {
            p /= 10
            count++
        }
        if count == 1 {
            li = append(li, i)
        }
        if count == 2 {
            temp = []int{}
            for q != 0 {
                x := q % 10
                q /= 10
                temp = append(temp, x)
            }
            li = append(li, temp...)
        }
        if count == 3 {
            temp = []int{}
            for q != 0 {
                x := q % 10
                q /= 10
                temp = append(temp, x)
            }
            li = append(li, temp...)
        }
    }
    li = li[:len(li)-2]
    n, _ := fmt.Scanln()
    fmt.Println(li[n-1])
}

