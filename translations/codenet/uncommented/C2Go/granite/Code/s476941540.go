
package main

import (
    "bufio"
    "fmt"
    "os"
    "unicode"
)

func main() {
    alpha := make([]int, 26)
    scanner := bufio.NewScanner(os.Stdin)
    for scanner.Scan() {
        for _, r := range scanner.Bytes() {
            if unicode.IsLetter(r) {
                alpha[unicode.ToLower(r)-'a']++
            }
        }
    }
    for i, r := range "abcdefghijklmnopqrstuvwxyz" {
        fmt.Printf("%c : %d\n", r, alpha[i])
    }
}
