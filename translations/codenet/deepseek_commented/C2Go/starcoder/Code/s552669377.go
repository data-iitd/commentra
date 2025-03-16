<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
<<<<<<< HEAD
    var (
        i int
        n int
        tmp int
        min int = 1000000
        max int = -1000000
        sum int = 0
    )

    n, _ = strconv.Atoi(strings.TrimSpace(string(os.Stdin.Read(make([]byte, 1024)))))

    for i = 0; i < n; i++ {
        tmp, _ = strconv.Atoi(strings.TrimSpace(string(os.Stdin.Read(make([]byte, 1024)))))
=======
    var i, n int
    var tmp, min, max, sum int64
    fmt.Scanf("%d", &n)
    for i = 0; i < n; i++ {
        fmt.Scanf("%d", &tmp)
>>>>>>> 98c87cb78a (data updated)
        if min > tmp {
            min = tmp
        }
        if max < tmp {
            max = tmp
        }
        sum += tmp
    }
<<<<<<< HEAD

=======
>>>>>>> 98c87cb78a (data updated)
    fmt.Printf("%d %d %d\n", min, max, sum)
}

