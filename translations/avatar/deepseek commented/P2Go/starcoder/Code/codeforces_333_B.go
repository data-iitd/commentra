
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)
    fmt.Println("Enter the number of rows and columns")
    input, _ := reader.ReadString('\n')
    input = strings.TrimSpace(input)
    n, m := strings.Split(input, " ")
    n, _ = strconv.Atoi(n)
    m, _ = strconv.Atoi(m)
    b := make([]int, 2*n)
    for i := 0; i < 2*n; i++ {
        b[i] = 1
    }
    b[0] = b[n-1] = b[n] = b[2*n-1] = 0
    for i := 0; i < m; i++ {
        input, _ := reader.ReadString('\n')
        input = strings.TrimSpace(input)
        r, c := strings.Split(input, " ")
        r, _ = strconv.Atoi(r)
        c, _ = strconv.Atoi(c)
        b[r-1] = b[n+c-1] = 0
    }
    if n%2 == 1 && b[n/2] == 1 && b[n+n/2] == 1 {
        b[n/2] = 0
    }
    fmt.Println(sum(b))
}

func sum(a []int) int {
    var s int
    for _, v := range a {
        s += v
    }
    return s
}

