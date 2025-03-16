package main
import (
    "fmt"
    "math"
    "strconv"
)
func main() {
    var N int
    fmt.Scan(&N)
    a := make([]int, N)
    for i := 0; i < N; i++ {
        fmt.Scan(&a[i])
    }
    max_val := 0
    max_sign := 0
    max_index := -1
    for i, a0 := range a {
        if abs(a0) > max_val {
            max_val = abs(a0)
            max_sign = my_sign(a0)
            max_index = i
        }
    }
    if max_sign == 0 {
        fmt.Println(0)
    } else if max_sign == 1 {
        fmt.Println(2 * N - 1)
        for i := 0; i < N; i++ {
            fmt.Println(max_index + 1, i + 1)
        }
        for i := 0; i < N - 1; i++ {
            fmt.Println(i + 1, i + 2)
        }
    } else {
        fmt.Println(2 * N - 1)
        for i := 0; i < N; i++ {
            fmt.Println(max_index + 1, i + 1)
        }
        for i := 1; i < N; i++ {
            fmt.Println(i + 1, i)
        }
    }
}
func my_sign(x int) int {
    if x > 0 {
        return 1
    } else if x < 0 {
        return -1
    } else {
        return 0
    }
}
func abs(x int) int {
    if x < 0 {
        return -x
    } else {
        return x
    }
}
func input() string {
    var s string
    fmt.Scan(&s)
    return s
}
func I() int {
    return int(input())
}
func II() []int {
    return map(strconv.Atoi, strings.Split(input(), " "))
}
func III() [][]int {
    N := I()
    if N <= 0 {
        return [][]int{{}}
    } else if N == 1 {
        return [][]int{II()}
    } else {
        read_all := make([][]int, N)
        for i := 0; i < N; i++ {
            read_all[i] = II()
        }
        return map([]int, zip(*read_all))
    }
}
func Line(N int, num int) [][]int {
    if N <= 0 {
        return [][]int{{}}
    } else if num == 1 {
        return [][]int{II()}
    } else {
        read_all := make([][]int, N)
        for i := 0; i < N; i++ {
            read_all[i] = II()
        }
        return map([]int, zip(*read_all))
    }
}
func map(f func(int) int, a []int) []int {
    b := make([]int, len(a))
    for i, v := range a {
        b[i] = f(v)
    }
    return b
}
func zip(a ...[]int) [][]int {
    b := make([][]int, len(a[0]))
    for i := 0; i < len(a[0]); i++ {
        b[i] = make([]int, len(a))
        for j := 0; j < len(a); j++ {
            b[i][j] = a[j][i]
        }
    }
    return b
}
func my_sign(x int) int {
    if x > 0 {
        return 1
    } else if x < 0 {
        return -1
    } else {
        return 0
    }
}
func abs(x int) int {
    if x < 0 {
        return -x
    } else {
        return x
    }
}
func input() string {
    var s string
    fmt.Scan(&s)
    return s
}
func I() int {
    return int(input())
}
func II() []int {
    return map(strconv.Atoi, strings.Split(input(), " "))
}
func III() [][]int {
    N := I()
    if N <= 0 {
        return [][]int{{}}
    } else if N == 1 {
        return [][]int{II()}
    } else {
        read_all := make([][]int, N)
        for i := 0; i < N; i++ {
            read_all[i] = II()
        }
        return map([]int, zip(*read_all))
    }
}
func Line(N int, num int) [][]int {
    if N <= 0 {
        return [][]int{{}}
    } else if num == 1 {
        return [][]int{II()}
    } else {
        read_all := make([][]int, N)
        for i := 0; i < N; i++ {
            read_all[i] = II()
        }
        return map([]int, zip(*read_all))
    }
}
func map(f func(int) int, a []int) []int {
    b := make([]int, len(a))
    for i, v := range a {
        b[i] = f(v)
    }
    return b
}
func zip(a ...[]int) [][]int {
    b := make([][]int, len(a[0]))
    for i := 0; i < len(a[0]); i++ {
        b[i] = make([]int, len(a))
        for j := 0; j < len(a); j++ {
            b[i][j] = a[j][i]
        }
    }
    return b
}
func my_sign(x int) int {
    if x > 0 {
        return 1
    } else if x < 0 {
        return -1
    } else {
        return 0
    }
}
func abs(x int) int {
    if x < 0 {
        return -x
    } else {
        return x
    }
}
func input() string {
    var s string
    fmt.Scan(&s)
    return s
}
func I() int {
    return int(input())
}
func II() []int {
    return map(strconv.Atoi, strings.Split(input(), " "))
}
func III() [][]int {
    N := I()
    if N <= 0 {
        return [][]int{{}}
    } else if N == 1 {
        return [][]int{II()}
    } else {
        read_all := make([][]int, N)
        for i := 0; i < N; i++ {
            read_all[i] = II()
        }
        return map([]int, zip(*read_all))
    }
}
func Line(N int, num int) [][]int {
    if N <= 0 {
        return [][]int{{}}
    } else if num == 1 {
        return [][]int{II()}
    } else {
        read_all := make([][]int, N)
        for i := 0; i < N; i++ {
            read_all[i] = II()
        }
        return map([]int, zip(*read_all))
    }
}
func map(f func(int) int, a []int) []int {
    b := make([]int, len(a))
    for i, v := range a {
        b[i] = f(v)
    }
    return b
}
func zip(a ...[]int) [][]int {
    b := make([][]int, len(a[0]))
    for i := 0; i < len(a[0]); i++ {
        b[i] = make([]int, len(a))
        for j := 0; j < len(a); j++ {
            b[i][j] = a[j][i]
        }
    }
    return b
}
func my_sign(x int) int {
    if x > 0 {
        return 1
    } else if x < 0 {
        return -1
    } else {
        return 0
    }
}
func abs(x int) int {
    if x < 0 {
        return -x
    } else {
        return x
    }
}
func input() string {
    var s string
    fmt.Scan(&s)
    return s
}
func I() int {
    return int(input())
}
func II() []int {
    return map(strconv.Atoi, strings.Split(input(), " "))
}
func III() [][]int {
    N := I()
    if N <= 0 {
        return [][]int{{}}
    } else if N == 1 {
        return [][]int{II()}
    } else {
        read_all := make([][]int, N)
        for i := 0; i < N; i++ {
            read_all[i] = II()
        }
        return map([]int, zip(*read_all))
    }
}
func Line(N int, num int) [][]int {
    if N <= 0 {
        return [][]int{{}}
    } else if num == 1 {
        return [][]int{II()}
    } else {
        read_all := make([][]int, N)
        for i := 0; i < N; i++ {
            read_all[i] = II()
        }
        return map([]int, zip(*read_all))
    }
}
func map(f func(int) int, a []int) []int {
    b := make([]int, len(a))
    for i, v := range a {
        b[i] = f(v)
    }
    return b
}
func zip(a ...[]int) [][]int {
    b := make([][]int, len(a[0]))
    for i := 0; i < len(a[0]); i++ {
        b[i] = make([]int, len(a))
        for j := 0; j < len(a); j++ {
            b[i][j] = a[j][i]
        }
    }
    return b
}
func my_sign(x int) int {
    if x > 0 {
        return 1
    } else if x < 0 {
        return -1
    } else {
        return 0
    }
}
func abs(x int) int {
    if x < 0 {
        return -x
    } else {
        return x
    }
}
func input() string {
    var s string
    fmt.Scan(&s)
    return s
}
func I() int {
    return int(input())
}
func II() []int {
    return map(strconv.Atoi, strings.Split(input(), " "))
}
func III() [][]int {
    N := I()
    if N <= 0 {
        return [][]int{{}}
    } else if N == 1 {
        return [][]int{II()}
    } else {
        read_all := make([][]int, N)
        for i := 0; i < N; i++ {
            read_all[i] = II()
        }
        return map([]int, zip(*read_all))
    }
}
func Line(N int, num int) [][]int {
    if N <= 0 {
        return [][]int{{}}
    } else if num == 1 {
        return [][]int{II()}
    } else {
        read_all := make([][]int, N)
        for i := 0; i < N; i++ {
            read_all[i] = II()
        }
        return map([]int, zip(*read_all))
    }
}
func map(f func(int) int, a []int) []int {
    b := make([]int, len(a))
    for i, v := range a {
        b[i] = f(v)
    }
    return b
}
func zip(a ...[]int) [][]int {
    b := make([][]int, len(a[0]))
    for i := 0; i < len(a[0]); i++ {
        b[i] = make([]int, len(a))
        for j := 0; j < len(a); j++ {
            b[i][j] = a[j][i]
        }
    }
    return b
}
func my_sign(x int) int {
    if x > 0 {
        return 1
    } else if x < 0 {
        return -1
    } else {
        return 0
    }
}
func abs(x int) int {
    if x < 0 {
        return -x
    } else {
        return x
    }
}
func input() string {
    var s string
    fmt.Scan(&s)
    return s
}
func I() int {
    return int(input())
}
func II() []int {
    return map(strconv.Atoi, strings.Split(input(), " "))
}
func III() [][]int {
    N := I()
    if N <= 0 {
        return [][]int{{}}
    } else if N == 1 {
        return [][]int{II()}
    } else {
        read_all := make([][]int, N)
        for i := 0; i < N; i++ {
            read_all[i] = II()
        }
        return map([]int, zip(*read_all))
    }
}
func Line(N int, num int) [][]int {
    if N <= 0 {
        return [][]int{{}}
    } else if num == 1 {
        return [][]int{II()}
    } else {
        read_all := make([][]int, N)
        for i := 0; i < N; i++ {
            read_all[i] = II()
        }
        return map([]int, zip(*read_all))
    }
}
func map(f func(int) int, a []int) []int {
    b := make([]int, len(a))
    for i, v := range a {
        b[i] = f(v)
    }
    return b
}
func zip(a ...[]int) [][]int {
    b := make([][]int, len(a[0]))
    for i := 0; i < len(a[0]); i++ {
        b[i] = make([]int, len(a))
        for j := 0; j < len(a); j++ {
            b[i][j] = a[j][i]
        }
    }
    return b
}
func my_sign(x int) int {
    if x > 0 {
        return 1
    } else if x < 0 {
        return -1
    } else {
        return 0
    }
}
func abs(x int) int {
    if x < 0 {
        return -x
    } else {
        return x
    }
}
func input() string {
    var s string
    fmt.Scan(&s)
    return s
}
func I() int {
    return int(input())
}
func II() []int {
    return map(strconv.Atoi, strings.Split(input(), " "))
}
func III() [][]int {
    N := I()
    if N <= 0 {
        return [][]int{{}}
    } else if N == 1 {
        return [][]int{II()}
    } else {
        read_all := make([][]int, N)
        for i := 0; i < N; i++ {
            read_all[i] = II()
        