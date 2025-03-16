package main
import "fmt"
func gen(number int, four, seven int) {
    if number > 10000000000 {
        return
    }
    if number > 0 && four == seven {
        fmt.Println(number)
    }
    gen(number*10+4, four+1, seven)
    gen(number*10+7, four, seven+1)
}
func main() {
    gen(0, 0, 0)
}
