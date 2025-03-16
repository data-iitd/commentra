

package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    s, _ := reader.ReadString('\n')
    t, _ := reader.ReadString('\n')

    ura := 0
    opa := 0

    tmap := make(map[string]int)

    for _, ch := range t {
        tmap[string(ch)]++
    }

    length := len(s)
    for i := 0; i < length; i++ {
        ch := string(s[i])
        if _, ok := tmap[ch]; ok {
            tmap[ch]--
            if tmap[ch] == 0 {
                delete(tmap, ch)
            }
            s = s[:i] + "Я" + s[i+1:]
            ura++
        }
    }

    for i := length - 1; i >= 0; i-- {
        ch := string(s[i])
        rch := reverse(ch)
        if _, ok := tmap[rch]; ok {
            tmap[rch]--
            if tmap[rch] == 0 {
                delete(tmap, rch)
            }
            opa++
        }
    }

    fmt.Println(ura, opa)
}

func reverse(ch string) string {
    if strings.ToLower(ch) == ch {
        return strings.ToUpper(ch)
    } else {
        return strings.ToLower(ch)
    }
}

