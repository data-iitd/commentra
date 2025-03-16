
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    var i int
    var alpha [26]int
    var ch byte
    var reader = bufio.NewReader(os.Stdin)

    for {
        ch, _ = reader.ReadByte()
        if ch == '\n' {
            break
        }
        if strings.ContainsRune("abcdefghijklmnopqrstuvwxyz", rune(ch)) {
            if strings.ContainsRune("ABCDEFGHIJKLMNOPQRSTUVWXYZ", rune(ch)) {
                alpha[ch-'A']++
            } else {
                alpha[ch-'a']++
            }
        }
    }

    ch = 'a'
    for i = 0; i < 26; i++ {
        fmt.Printf("%c : %d\n", ch, alpha[i])
        ch++
    }
}

