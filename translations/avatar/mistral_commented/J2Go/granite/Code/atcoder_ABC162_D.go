

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    var n int64
    var s string
    fmt.Fscan(reader, &n)
    fmt.Fscan(reader, &s)

    rc := int64(0)
    gc := int64(0)
    bc := int64(0)

    for i := 0; i < len(s); i++ {
        if string(s[i]) == "R" {
            rc++
        } else if string(s[i]) == "G" {
            gc++
        } else {
            bc++
        }
    }

    result := rc * gc * bc

    for i := int64(1); i <= n; i++ {
        for k := i + 1; k <= n; k++ {
            if (i+k)%2 == 0 {
                is := string(s[i-1])
                ks := string(s[k-1])
                js := string(s[(i+k)/2-1])
                if is!= ks && ks!= js && js!= is {
                    result--
                }
            }
        }
    }

    fmt.Println(result)
}

