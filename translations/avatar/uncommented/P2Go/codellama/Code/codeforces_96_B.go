
package main

import "fmt"

var l []int
var limit int = 10000000000

func gen(number int, four int, seven int) {
    if number > limit {
        return
    }
    if number > 0 && four == seven {
        l = append(l, number)
    }
    gen(number*10+4, four+1, seven)
    gen(number*10+7, four, seven+1)
}

func main() {
    gen(0, 0, 0)
    l = append(l, 0)
    sort.Ints(l)
    var n int
    fmt.Scan(&n)
    var ans int
    for _, val := range l {
        if val >= n {
            ans = val
            break
        }
    }
    fmt.Println(ans)
}

