
package main

import "fmt"

func main() {
    var l string
    fmt.Scan(&l)
    l = l + "."
    s := []rune(l[0:len(l)-1])
    p := []rune(l[len(l)-1:])
    i, _ := strconv.Atoi(string(p[0]))
    if s[len(s)-1] == '9' {
        fmt.Println("GOTO Vasilisa.")
    } else if s[len(s)-1] != '9' && i < 5 {
        fmt.Println(string(s))
    } else {
        s = string(s) + string(int(s) + 1)
        fmt.Println(s)
    }
}