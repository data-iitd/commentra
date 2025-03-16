package main
import "fmt"
import "math"
import "sort"
import "strconv"
import "strings"
import "unicode"
import "unicode/utf8"

func main() {
    var n, num int
    fmt.Scanf("%d %d", &n, &num)
    numSet := make(map[int]bool)
    for i := 0; i < n; i++ {
        var num int
        fmt.Scanf("%d", &num)
        numSet[num] = true
    }
    twoTimesSet := make(map[int]bool)
    for num := range numSet {
        for i := 1; i < 30; i++ {
            num /= 2
            if num%2!= 0 {
                twoTimesSet[i] = true
                break
            }
        }
        if len(twoTimesSet)!= 1 {
            fmt.Println(0)
            return
        }
    }
    numList := make([]int, 0, len(numSet))
    for num := range numSet {
        numList = append(numList, num)
    }
    sort.Ints(numList)
    lcm := numList[0]
    for i := 1; i < len(numList); i++ {
        lcm = lcm * numList[i] / gcd(lcm, numList[i])
    }
    fmt.Println((num - lcm/2) / lcm + 1)
}

func gcd(a, b int) int {
    for b!= 0 {
        a, b = b, a%b
    }
    return a
}

