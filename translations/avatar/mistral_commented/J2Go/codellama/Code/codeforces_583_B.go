
package main

import (
    "fmt"
    "os"
    "bufio"
    "strconv"
)

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    for scanner.Scan() {
        n, _ := strconv.Atoi(scanner.Text())
        a := make([]int, n)
        b := make([]int, n)
        s := -1
        for i := 0; i < n; i++ {
            scanner.Scan()
            a[i], _ = strconv.Atoi(scanner.Text())
            b[i] = 0
        }
        tem := 1
        q := 0
        for q != n {
            s++
            if tem == 1 {
                for i := 0; i < n; i++ {
                    if a[i] <= q && b[i] == 0 {
                        b[i] = 1
                        q++
                    }
                }
                tem = 0
            } else {
                for i := n - 1; i >= 0; i-- {
                    if a[i] <= q && b[i] == 0 {
                        b[i] = 1
                        q++
                    }
                }
                tem = 1
            }
        }
        fmt.Println(s)
    }
}

