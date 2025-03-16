

package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    x := make([]int, 3)
    max := 0
    for i := 0; i < 3; i++ {
        num, _ := reader.ReadString('\n')
        x[i], _ = strconv.Atoi(strings.TrimSpace(num))
        if x[i] > max {
            max = x[i]
        }
    }

    k, _ := reader.ReadString('\n')
    k, _ = strconv.Atoi(strings.TrimSpace(k))

    a := make([][]int64, 3)
    for i := 0; i < 3; i++ {
        a[i] = make([]int64, x[i])
        for j := 0; j < x[i]; j++ {
            num, _ := reader.ReadString('\n')
            a[i][j], _ = strconv.ParseInt(strings.TrimSpace(num), 10, 64)
        }
        sort.Slice(a[i], func(i, j int) bool {
            return a[i][j] < a[i][j+1]
        })
    }

    ans := make([]int64, 0)
    for i := 0; i < x[0]; i++ {
        for j := 0; j < x[1]; j++ {
            for m := 0; m < x[2]; m++ {
                if (i+1)*(j+1)*(m+1) <= k {
                    tmp := a[0][x[0]-i-1] + a[1][x[1]-j-1] + a[2][x[2]-m-1]
                    ans = append(ans, tmp)
                }
            }
        }
    }

    sort.Slice(ans, func(i, j int) bool {
        return ans[i] < ans[j]
    })

    for i := 0; i < k; i++ {
        fmt.Println(ans[len(ans)-i-1])
    }
}

