
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
    var nd []string
    nd, _ = reader.ReadString('\n')
    nd = strings.Split(nd, " ")
    n, _ := strconv.Atoi(nd[0])
    d, _ := strconv.Atoi(nd[1])
    var x []int
    x = make([]int, n)
    var m int = 0
    var q int
    var a int
    nd, _ = reader.ReadString('\n')
    nd = strings.Split(nd, " ")
    for i := 0; i < n; i++ {
        x[i], _ = strconv.Atoi(nd[i])
    }
    for a = 0; a < n-1; a++ {
        if x[a] >= x[a+1] {
            q = (x[a] - x[a+1]) / d + 1
            m = m + q
            x[a+1] = x[a+1] + q * d
        }
    }
    fmt.Println(m)
}
