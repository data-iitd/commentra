

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

    var a int
    fmt.Fscan(reader, &a)

    var t, h int

    for i := 0; i < a; i++ {
        taro, _ := reader.ReadString('\n')
        hana, _ := reader.ReadString('\n')

        lt := len(strings.TrimSpace(taro))
        lh := len(strings.TrimSpace(hana))

        l := lt
        if lt > lh {
            l = lh
        }

        tt := 0
        hh := 0

        if strings.Compare(strings.TrimSpace(taro), strings.TrimSpace(hana)) > 0 {
            t += 3
        } else if strings.Compare(strings.TrimSpace(hana), strings.TrimSpace(taro)) > 0 {
            h += 3
        } else if strings.Compare(strings.TrimSpace(hana), strings.TrimSpace(taro)) == 0 {
            h += 1
            t += 1
        }
    }

    fmt.Println(t, h)
}

