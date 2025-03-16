
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter a string: ")
    s, _ := reader.ReadString('\n')
    s = strings.TrimSpace(s)
    res := []string{}
    punctuation := ",.!?"
    for i := 0; i < len(s); i++ {
        if i >= 1 {
            if s[i] =='' {
                if res[len(res)-1]!= "" {
                    res = append(res, s[i:i+1])
                } else {
                    continue
                }
            } else {
                if strings.ContainsRune(punctuation, rune(s[i])) {
                    if res[len(res)-1] == "" {
                        res = res[:len(res)-1]
                    }
                    res = append(res, s[i:i+1])
                    res = append(res, "")
                } else {
                    res = append(res, s[i:i+1])
                }
            }
        } else {
            if s[i] =='' {
                continue
            }
            if strings.ContainsRune(punctuation, rune(s[i])) {
                continue
            }
            res = append(res, s[i:i+1])
        }
    }
    fmt.Println(strings.Join(res, ""))
}
