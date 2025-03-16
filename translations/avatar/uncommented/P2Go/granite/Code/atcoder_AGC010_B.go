
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
    n, _ := strconv.Atoi(reader.ReadLine()[2:])
    a := make([]int, n)
    for i, v := range strings.Split(reader.ReadLine()[2:], " ") {
        a[i], _ = strconv.Atoi(v)
    }
    if sum := sum(a); sum%(n*(n+1)/2)!= 0 {
        fmt.Println("NO")
    } else {
        k := sum / (n * (n + 1) / 2)
        a = append(a, a[0])
        if sum := sum(make([]int, n, func(i int) int {
            return int((k-int64(a[i+1])+int64(a[i]))%int64(n))
        })); sum!= 0 {
            fmt.Println("NO")
        } else if sum := sum(make([]int, n, func(i int) int {
            return int((k-int64(a[i+1])+int64(a[i]))/int64(n)) >= 0
        })); sum!= n {
            fmt.Println("NO")
        } else {
            fmt.Println("YES")
        }
    }
}

func sum(a []int) int {
    s := 0
    for _, v := range a {
        s += v
    }
    return s
}

