package main
import "fmt"
import "os"
import "strconv"
import "strings"

func main() {
    var n, q int
    var s string
    var problems [][]int
    fmt.Sscanf(os.Args[1], "%d", &n)
    fmt.Sscanf(os.Args[2], "%d", &q)
    s = os.Args[3]
    problems = make([][]int, q)
    for i := 0; i < q; i++ {
        problems[i] = make([]int, 2)
        fmt.Sscanf(os.Args[4+i], "%d %d", &problems[i][0], &problems[i][1])
    }
    var cumsum []int
    cumsum = make([]int, n)
    cumsum[0] = 1
    for i := 1; i < n; i++ {
        if s[i-1:i+1] == "AC" {
            cumsum[i] = cumsum[i-1] + 1
        } else {
            cumsum[i] = cumsum[i-1]
        }
    }
    for _, problem := range problems {
        fmt.Println(cumsum[problem[1]-1] - cumsum[problem[0]-1])
    }
}

