
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("Enter the value of n:")
    n, _ := strconv.Atoi(reader.ReadLine()[0])
    fmt.Println("Enter the value of k:")
    k, _ := strconv.Atoi(reader.ReadLine()[0])

    var l, r int64 = 0, 0
    if k%2 == 0 {
        for i := 1; i <= n; i++ {
            if i%k == k/2 {
                l++
            } else if i%k == 0 {
                r++
            }
        }
        fmt.Println(l * l * l + r * r * r)
    } else {
        for i := 1; i <= n; i++ {
            if i%k == 0 {
                r++
            }
        }
        fmt.Println(r * r * r)
    }
}

