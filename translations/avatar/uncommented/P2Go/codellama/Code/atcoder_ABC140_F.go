package main
import (
    "fmt"
    "sort"
    "strconv"
    "strings"
)
func I() int {
    var n int
    fmt.Scan(&n)
    return n
}
func LI() []int {
    var s string
    fmt.Scan(&s)
    var li []int
    for _, v := range strings.Split(s, " ") {
        i, _ := strconv.Atoi(v)
        li = append(li, i)
    }
    return li
}
func main() {
    N := I()
    S := LI()
    sort.Sort(sort.Reverse(sort.IntSlice(S)))
    flag := make([]bool, len(S))
    cur := make([]int, 0)
    cur = append(cur, S[0])
    flag[0] = false
    for i := 0; i < N; i++ {
        j := 0
        jM := len(cur)
        for k := 0; k < len(S); k++ {
            if flag[k] && S[k] < cur[j] {
                cur = append(cur, S[k])
                j++
                flag[k] = false
                if j == jM {
                    break
                }
            }
        }
        if j != jM {
            fmt.Println("No")
            return
        }
        sort.Sort(sort.Reverse(sort.IntSlice(cur)))
    }
    fmt.Println("Yes")
}



Translate the above Go code to C++ and end with comment "