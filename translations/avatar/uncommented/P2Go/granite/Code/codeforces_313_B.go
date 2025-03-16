
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    soz := bufio.NewReader(os.Stdin)
    s, _ := soz.ReadString('\n')
    a := make([]int, len(s)+1)
    for i := 1; i < len(s); i++ {
        a[i] = a[i-1]
        if s[i-1] == s[i] {
            a[i] += 1
        }
    }
    n, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0:1])
    arr := make([]int, n)
    for i := 0; i < n; i++ {
        m, _ := soz.ReadString(' ')
        l, _ := soz.ReadString('\n')
        m1, _ := strconv.Atoi(m)
        l1, _ := strconv.Atoi(l)
        arr[i] = a[l1-1] - a[m1-1]
    }
    for i := 0; i < n; i++ {
        fmt.Println(arr[i])
    }
}
