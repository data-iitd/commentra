<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("Enter the number of elements in the array")
    n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
    fmt.Println("Enter the number of queries")
    m, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
    fmt.Println("Enter the value of x")
    x, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
    a := make([]int, n)
    for i := 0; i < m; i++ {
        fmt.Println("Enter the value of the element")
        temp, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
        a[temp] = 1
    }
    ansl := 0
    ansr := 0
    for i := x; i <= n; i++ {
        ansr += a[i]
    }
    for i := x; i >= 0; i-- {
        ansl += a[i]
    }
    fmt.Println(min(ansl, ansr))
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

