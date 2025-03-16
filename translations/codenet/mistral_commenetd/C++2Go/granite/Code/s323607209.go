
package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("Enter the value of n:")
    n, _ := reader.ReadString('\n')
    fmt.Println("Enter the value of k:")
    k, _ := reader.ReadString('\n')
    nInt, _ := strconv.Atoi(string(n))
    kInt, _ := strconv.Atoi(string(k))
    var l, r int64 = 0, 0
    if kInt%2 == 0 {
        for i := 1; i <= nInt; i++ {
            if i%kInt == kInt/2 {
                l++
            } else if i%kInt == 0 {
                r++
            }
        }
        fmt.Println(l * l * l + r * r * r)
    } else {
        for i := 1; i <= nInt; i++ {
            if i%kInt == 0 {
                r++
            }
        }
        fmt.Println(r * r * r)
    }
}

