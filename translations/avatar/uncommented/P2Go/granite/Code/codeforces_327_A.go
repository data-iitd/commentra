
package main
import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)
func find(s string, ch byte) []int {
    var indices []int
    for i, ltr := range s {
        if ltr == ch {
            indices = append(indices, i)
        }
    }
    return indices
}
func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("Enter the number of elements:")
    nTemp, err := reader.ReadString('\n')
    if err!= nil {
        fmt.Println("Error reading input:", err)
        return
    }
    n, err := strconv.Atoi(strings.TrimSpace(nTemp))
    if err!= nil {
        fmt.Println("Error converting input to integer:", err)
        return
    }
    fmt.Println("Enter the elements:")
    sTemp, err := reader.ReadString('\n')
    if err!= nil {
        fmt.Println("Error reading input:", err)
        return
    }
    s := strings.TrimSpace(sTemp)
    if strings.Count(s, "0") == 0 {
        fmt.Println(n - 1)
    } else {
        indices := find(s, '0')
        if len(indices) == 1 {
            fmt.Println(n)
        } else {
            max := 0
            for _, x := range indices {
                for _, y := range indices {
                    if x!= y {
                        distance := abs(x, y)
                        max = maxInt(max, 2+2*distance-1-distance+1)
                    }
                }
            }
            fmt.Println(strings.Count(s, "1") + max)
        }
    }
}
func abs(a, b int) int {
    if a < b {
        return b - a
    }
    return a - b
}
func maxInt(a, b int) int {
    if a > b {
        return a
    }
    return b
}
