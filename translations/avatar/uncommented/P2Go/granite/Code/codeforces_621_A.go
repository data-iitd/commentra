
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
    n, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())])
    s := strings.Split(reader.ReadLine()[2 : len(reader.ReadLine())], " ")
    a := make([]int, n)
    for i := 0; i < n; i++ {
        a[i], _ = strconv.Atoi(s[i])
    }
    odd := 0
    for i := 0; i < n; i++ {
        if a[i]%2 == 1 {
            odd++
        }
    }
    sum := 0
    ok := false
    for i := 0; i < n; i++ {
        if a[i]%2 == 0 {
            sum += a[i]
        } else {
            if ok || odd > 1 {
                sum += a[i]
                odd--
                ok =!ok
            }
        }
    }
    fmt.Println(sum)
}
