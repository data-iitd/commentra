
package main

import (
    "bufio"
    "fmt"
    "math"
    "os"
    "strconv"
    "strings"
)

func main() {
    menu := make([][]int, 5)
    for i := 0; i < 5; i++ {
        m, _ := reader.ReadString('\n')
        m = strings.TrimSpace(m)
        e, _ := strconv.Atoi(string(m[len(m)-1]))
        if e == 0 {
            e = 10
        }
        menu[i] = []int{atoi(m), e}
    }
    sort.Slice(menu, func(i, j int) bool {
        return menu[i][1] < menu[j][1]
    })
    ans := 0
    for _, m := range menu[1:] {
        ans += int(math.Ceil(float64(m[0]) / 10)) * 10
    }
    ans += menu[0][0]
    fmt.Println(ans)
}

var reader = bufio.NewReader(os.Stdin)

