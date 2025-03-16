package main
import "fmt"
func main() {
    var n int
    fmt.Scanf("%d", &n)
    a := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &a[i])
    }
    current_level := 0
    counter := 0
    counter_turns := -1
    for counter < len(a) {
        counter_turns += 1
        for i := 0; i < len(a); i++ {
            if a[i]!= -1 && a[i] <= counter {
                counter += 1
                a[i] = -1
            }
        }
        a = append(a[:0], reverse(a)...)
    }
    fmt.Println(counter_turns)
}
func reverse(a []int) []int {
    for i := 0; i < len(a)/2; i++ {
        a[i], a[len(a)-1-i] = a[len(a)-1-i], a[i]
    }
    return a
}
