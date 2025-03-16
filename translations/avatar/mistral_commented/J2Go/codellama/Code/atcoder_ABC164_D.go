
package main

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    var N int
    var S string
    var mod_arr []int
    var mod_cnt []int
    var radix int
    var tmp int
    var ans int64

    fmt.Scan(&S)
    N = len(S)
    mod_arr = make([]int, N)
    mod_cnt = make([]int, 2019)
    radix = 1

    for i := 0; i < N; i++ {
        tmp = 0
        tmp = (int(S[N-1-i]) - int('0')) * radix % 2019
        if i != 0 {
            tmp = (tmp + mod_arr[i-1]) % 2019
        }
        mod_arr[i] = tmp
        mod_cnt[tmp]++
        radix = radix * 10 % 2019
    }

    ans = 0
    for i := 0; i < 2019; i++ {
        ans += int64(mod_cnt[i]) * int64(mod_cnt[i]-1) / 2
    }

    fmt.Println(ans)
}

