<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "os"
    "strings"
)

func main() {
    var c, ans string
    fmt.Scanf("%s", &c)
    for i := 0; c[i]!= '\0'; i++ {
        if c[i]!= 'B' {
            ans += string(c[i])
        } else {
            ans = ans[:len(ans)-1]
        }
    }
    fmt.Println(ans)
}

