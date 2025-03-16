
package main

import "fmt"
import "os"
import "bufio"

func main() {
    in := bufio.NewReader(os.Stdin)
    n, _ := fmt.Fscan(in, &n)
    k, _ := fmt.Fscan(in, &k)
    l := 0
    c := 1
    for i := 0; i < n; i++ {
        a, _ := fmt.Fscan(in, &a)
        if a == l {
            c += 1
        } else {
            c = 1
        }
        l = a
    }
    if c+k > n {
        fmt.Println(n - c)
    } else {
        fmt.Println(-1)
    }
}

