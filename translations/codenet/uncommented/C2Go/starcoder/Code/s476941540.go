package main

import (
    "bufio"
    "fmt"
    "os"
    "unicode"
)

func main() {
    var (
        ch rune
        i  int
        alpha [26]int
    )

    scanner := bufio.NewScanner(os.Stdin)
    for scanner.Scan() {
        ch = rune(scanner.Text()[0])
        if unicode.IsLetter(ch) {
            if unicode.IsUpper(ch) {
                alpha[ch - 65]++
            } else {
                alpha[ch - 97]++
            }
        }
    }

    ch = 'a'
    for i = 0; i < 26; i++ {
        fmt.Printf("%c : %d\n", ch, alpha[i])
        ch++
    }
}

