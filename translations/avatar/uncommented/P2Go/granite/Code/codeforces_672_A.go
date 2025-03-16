
package main
import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)
func main() {
    reader := bufio.NewReader(os.Stdin)
    var n int
    fmt.Fscanf(reader, "%d\n", &n)
    li := make([]int, 0)
    ind := 0
    for i := 1; i < 371; i++ {
        temp := make([]int, 0)
        p, q := i, i
        count := 0
        for p!= 0 {
            p /= 10
            count++
        }
        if count == 1 {
            li = append(li, i)
        }
        if count == 2 {
            temp = make([]int, 0)
            for q!= 0 {
                x := q % 10
                q /= 10
                temp = append(temp, x)
            }
            li = append(li, temp...)
        }
        if count == 3 {
            temp = make([]int, 0)
            for q!= 0 {
                x := q % 10
                q /= 10
                temp = append(temp, x)
            }
            li = append(li, temp...)
        }
    }
    li = li[:len(li)-2]
    fmt.Println(li[n-1])
}
