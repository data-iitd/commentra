
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
    fmt.Println("Enter the number of elements in the list")
    n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
    fmt.Println("Enter the elements of the list")
    a := make([]int, n)
    for i := 0; i < n; i++ {
        a[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
    }
    if sum(a)%(n*(n+1)/2)!= 0 {
        fmt.Println("NO")
        return
    }
    k := sum(a)/(n*(n+1)/2)
    a = append(a, a[0])
    if sum([k-i+j%n for i, j := range a[1:]])!= 0 || sum([k-i+j/n >= 0 for i, j := range a[1:]])!= n {
        fmt.Println("NO")
        return
    }
    fmt.Println("YES")
}

func sum(a []int) int {
    var s int
    for _, v := range a {
        s += v
    }
    return s
}

