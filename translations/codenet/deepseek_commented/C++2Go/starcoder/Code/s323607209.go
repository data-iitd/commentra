<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("Enter n and k:")
    input, _ := reader.ReadString('\n')
    input = strings.TrimSuffix(input, "\n")
    n, _ := strconv.Atoi(input)
    input, _ = reader.ReadString('\n')
    input = strings.TrimSuffix(input, "\n")
    k, _ := strconv.Atoi(input)
<<<<<<< HEAD
=======

>>>>>>> 98c87cb78a (data updated)
    l, r := 0, 0
    if k%2 == 0 {
        for i := 1; i <= n; i++ {
            if i%k == k/2 {
                l++
            } else if i%k == 0 {
                r++
            }
        }
        fmt.Println(l*l*l + r*r*r)
    } else {
        for i := 1; i <= n; i++ {
            if i%k == 0 {
                r++
            }
        }
        fmt.Println(r*r*r)
    }
}

