
package main

import "fmt"

func main() {
    var n, k int
    fmt.Scan(&n, &k)
    n++
    var z int
    if n%k!= 0 {
        z = k - n%k
    }
    fmt.Println(n + z)
}

