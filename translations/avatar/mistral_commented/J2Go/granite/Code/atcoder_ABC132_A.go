

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

    map := make(map[rune]int)

    for i := 0; i < len(targ); i++ {
        currentChar := targ[i]

        if _, ok := map[currentChar];!ok {
            map[currentChar] = 1
        } else {
            map[currentChar]++
        }
    }

    ok := true
    for _, value := range map {
        if value!= 2 {
            ok = false
            break
        }
    }

    if ok && len(map) == 2 {
        fmt.Println("Yes")
    } else {
        fmt.Println("No")
    }
}

Translate the above Go code to C++ and end with comment "