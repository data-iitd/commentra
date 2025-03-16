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
    reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)
    fmt.Println("Enter the numbers separated by space:")
    input, _ := reader.ReadString('\n')
    input = strings.TrimSpace(input)
    a := strings.Split(input, " ")
    a = append(a, "")
    var i int
    var j int
    var k int
    var n int
    var t int
    var x int
    var y int
    var z int
    n, _ = strconv.Atoi(a[0])
    a = a[1:n+1]
    a_int := make([]int, n)
    for i = 0; i < n; i++ {
        a_int[i], _ = strconv.Atoi(a[i])
    }
    sort.Ints(a_int)
    for i = 1; i < n; i++ {
        if a_int[i]!= a_int[i-1] && a_int[i] < a_int[i-1]*2 {
            fmt.Println("YES")
            return
        }
    }
    fmt.Println("NO")
}
