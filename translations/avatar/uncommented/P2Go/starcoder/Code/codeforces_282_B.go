package main
import "fmt"
func main() {
    var firstline int
    var total int
    var memory []string
    fmt.Scanf("%d", &firstline)
    for x := 0; x < firstline; x++ {
        var A, G int
        fmt.Scanf("%d %d", &A, &G)
        if total+A <= 500 {
            total += A
            memory = append(memory, "A")
        } else {
            total -= G
            memory = append(memory, "G")
        }
    }
    fmt.Println(strings.Join(memory, ""))
}
