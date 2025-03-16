package main
import (
    "fmt"
    "math"
    "strconv"
)
func main() {
    var n int
    fmt.Scan(&n)
    if n == 1 {
        fmt.Println(0)
        return
    }
    var fac_ []int
    for i := 2; i * i <= n; i++ {
        for n % i == 0 {
            fac_ = append(fac_, i)
            n /= i
        }
    }
    if n != 1 {
        fac_ = append(fac_, n)
    }
    fac := make(map[int]int)
    for _, v := range fac_ {
        fac[v]++
    }
    ans := 0
    for p, e := range fac {
        x := e
        for i := 1; i <= 99999999; i++ {
            if x >= i {
                x -= i
                ans++
            } else {
                break
            }
        }
    }
    fmt.Println(ans)
}



Translate the above Go code to C++ and end with comment "