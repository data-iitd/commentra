

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

    nTemp, err := reader.ReadString('\n')
    checkError(err)
    n, err := strconv.ParseInt(strings.TrimSpace(nTemp), 10, 64)
    checkError(err)

    sTemp, err := reader.ReadString('\n')
    checkError(err)
    s := strings.TrimSpace(sTemp)

    rc := int64(0)
    gc := int64(0)
    bc := int64(0)

    for i := 0; i < len(s); i++ {
        switch s[i] {
        case 'R':
            rc++
        case 'G':
            gc++
        case 'B':
            bc++
        }
    }

    result := rc * gc * bc

    for i := 1; i <= n; i++ {
        for k := i + 1; k <= n; k++ {
            if (i+k)%2 == 0 {
                is := s[i-1]
                ks := s[k-1]
                js := s[(i+k)/2-1]

                if is!= ks && ks!= js && js!= is {
                    result--
                }
            }
        }
    }

    fmt.Println(result)
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

