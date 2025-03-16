
package main

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    var n int
    var s string
    var rc int
    var gc int
    var bc int
    var result int

    n, _ = strconv.Atoi(os.Args[1])
    s = os.Args[2]

    for i := 0; i < len(s); i++ {
        if s[i] == 'R' {
            rc++
        } else if s[i] == 'G' {
            gc++
        } else {
            bc++
        }
    }

    result = rc * gc * bc

    for i := 1; i <= n; i++ {
        for k := i + 1; k <= n; k++ {
            if (i + k) % 2 == 0 {
                is := s[i-1]
                ks := s[k-1]
                js := s[(i+k)/2-1]
                if is != ks && ks != js && js != is {
                    result--
                }
            }
        }
    }

    fmt.Println(result)
}

