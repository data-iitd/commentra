package main
import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)
func main() {
    var n int
    var c int
    fmt.Scanf("%d\n", &n)
    for i := 0; i < n; i++ {
        var l1 []int
        fmt.Scanf("%s\n", &l1)
        l1 = strings.Split(l1, " ")
        l1 = convert_string_to_int(l1)
        if sum(l1) > 1 {
            c = c + 1
        }
    }
    fmt.Printf("%d\n", c)
}
func convert_string_to_int(str_slice []string) []int {
    int_slice := make([]int, len(str_slice))
    for i := 0; i < len(str_slice); i++ {
        int_slice[i], _ = strconv.Atoi(str_slice[i])
    }
    return int_slice
}
func sum(l1 []int) int {
    var sum int
    for _, v := range l1 {
        sum += v
    }
    return sum
}
