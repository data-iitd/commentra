
package main

import "fmt"
import "os"
import "strconv"

func main() {
    n, k := 0, 0
    fmt.Scanf("%d %d", &n, &k)
    i, req := 1, 1
    for k-req >= 0 {
        if k-req >= 0 {
            k = k - req
        } else {
            break
        }
        i++
        if i%n!= 0 {
            req = i % n
        } else {
            req = n
        }
    }
    fmt.Println(k)
}

