

package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    s, _ := reader.ReadString('\n')
    s = strings.TrimSpace(s)
    targ := []rune(s)
    m := make(map[rune]int)
    for _, c := range targ {
        m[c]++
    }
    keys := make([]rune, 0, len(m))
    for k := range m {
        keys = append(keys, k)
    }
    sort.Slice(keys, func(i, j int) bool {
        return keys[i] < keys[j]
    })
    ok := true
    for _, k := range keys {
        if m[k]!= 2 {
            ok = false
            break
        }
    }
    if ok && len(keys) == 2 {
        fmt.Println("Yes")
    } else {
        fmt.Println("No")
    }
}

