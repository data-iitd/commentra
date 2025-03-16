package main

import (
    "fmt"
    "math"
)

func main() {
    var N int
    fmt.Scanf("%d", &N)

    var i int = 1
    var ans int = 0

    for {
        if math.Pow(10, float64(i)) > float64(N) {
            break
        }
        ans += int(math.Pow(10, float64(i))) - int(math.Pow(10, float64(i-1)))
        i += 2
    }
    ans += max(0, N - int(math.Pow(10, float64(i-1))) + 1)
    fmt.Println(ans)
}

// 