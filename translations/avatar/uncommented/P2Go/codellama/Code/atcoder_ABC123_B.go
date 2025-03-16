package main

import (
    "fmt"
    "math"
)

func main() {
    menu := make([][]int, 5)
    for i := 0; i < 5; i++ {
        m := input()
        e := int(m[len(m)-1])
        if e == 0 {
            e = 10
        }
        menu[i] = []int{int(m), e}
    }
    menu = sort(menu, func(x, y []int) bool {
        return x[1] < y[1]
    })
    ans := 0
    for _, m := range menu[1:] {
        ans += int(math.Ceil(float64(m[0]) / 10)) * 10
    }
    fmt.Println(ans + menu[0][0])
}

func input() string {
    var s string
    fmt.Scan(&s)
    return s
}

func sort(menu [][]int, f func(x, y []int) bool) [][]int {
    for i := 0; i < len(menu); i++ {
        for j := i + 1; j < len(menu); j++ {
            if f(menu[i], menu[j]) {
                menu[i], menu[j] = menu[j], menu[i]
            }
        }
    }
    return menu
}

