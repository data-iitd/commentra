
package main
import (
    "fmt"
    "math"
    "sort"
    "strconv"
    "strings"
)
func main() {
    var menu [][2]int
    for i := 0; i < 5; i++ {
        m := strings.Split(fmt.Scanf("%s\n", &m), "")
        e, _ := strconv.Atoi(m[len(m)-1])
        if e == 0 {
            e = 10
        }
        menu = append(menu, [2]int{int(m[0]), e})
    }
    sort.Slice(menu, func(i, j int) bool {
        return menu[i][1] < menu[j][1]
    })
    ans := 0
    for _, m := range menu[1:] {
        ans += int(math.Ceil(float64(m[0]) / 10)) * 10
    }
    fmt.Printf("%d\n", ans+menu[0][0])
}

