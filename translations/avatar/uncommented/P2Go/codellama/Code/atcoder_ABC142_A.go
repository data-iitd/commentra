package main
import "fmt"
func nextInt() int {
    var n int
    fmt.Scan(&n)
    return n
}
func nextInts() []int {
    var n int
    fmt.Scan(&n)
    a := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scan(&a[i])
    }
    return a
}
func main() {
    n := nextInt()
    t := 0
    for i := 0; i < n; i++ {
        if i&1 == 1 {
            t++
        }
    }
    fmt.Println(float64(t)/float64(n))
}



Translate the above Go code to C++ and end with comment "