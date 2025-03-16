package main
import "fmt"
func main() {
    var princess, dragon, t, f, c int
    fmt.Scanf("%d\n%d\n%d\n%d\n%d", &princess, &dragon, &t, &f, &c)
    if dragon <= princess {
        fmt.Println(0)
        return
    }
    result := 0
    position := t * princess
    position += princess * position / (dragon - princess)
    for position < c {
        result += 1
        position += princess * position / dragon
        position += princess * f
        position += princess * position / (dragon - princess)
    }
    fmt.Println(result)
}
