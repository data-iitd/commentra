package main
import "fmt"
func main() {
    c := "abcdefghijklmnopqrstuvwxyz"
    i := strings.Index(c, "c")
    fmt.Printf("%s\n", c[i+1])
}
