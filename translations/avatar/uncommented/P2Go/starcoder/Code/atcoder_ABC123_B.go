package main
import "fmt"
import "math"
func main() {
    var menu [][2]int
    for i := 0; i < 5; i++ {
        var m string
        fmt.Scanf("%s", &m)
        e := int(m[len(m)-1])
        if e == 0 {
            e = 10
        }
        menu = append(menu, [2]int{int(m), e})
    }
    sort.Slice(menu, func(i, j int) bool {
        return menu[i][1] < menu[j][1]
    })
    ans := 0
    for _, m := range menu[1:] {
        ans += int(math.Ceil(float64(m[0])/10)) * 10
    }
    fmt.Println(ans + menu[0][0])
}
