

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("Enter the number of elements and the list elements separated by spaces:")
    text, _ := reader.ReadString('\n')
    n, _ := strconv.Atoi(strings.TrimSpace(strings.Split(text, " ")[0]))
    a := make([]int, n)
    text, _ = reader.ReadString('\n')
    for i := 0; i < n; i++ {
        a[i], _ = strconv.Atoi(strings.TrimSpace(strings.Split(text, " ")[i]))
    }
    if sum := sum(a); sum%(n*(n+1)/2)!= 0 {
        fmt.Println("NO")
    } else {
        k := sum / (n * (n + 1) / 2)
        a = append(a, a[0])
        if sum := sum(make([]int, n), func(i int) int {
            return (k-a[i]+a[i+1])%n
        }); sum!= 0 || sum2 := sum(make([]int, n), func(i int) int {
            return (k - a[i] + a[i+1]) / n
        }); sum2!= n {
            fmt.Println("NO")
        } else {
            fmt.Println("YES")
        }
    }
}

func sum(a []int, f...func(int) int) int {
    s := 0
    for i, v := range a {
        if len(f) > 0 {
            s += f[0](i)
        } else {
            s += v
        }
    }
    return s
}

