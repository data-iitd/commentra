
package main

import "fmt"

func main() {
    var n string
    fmt.Scan(&n)
    a := []string{"10", "100", "1000", "10000", "100000"}
    new := 0
    for _, v := range n {
        new += int(v - '0')
    }
    if contains(a, n) {
        fmt.Println(10)
    } else {
        fmt.Println(new)
    }
}

func contains(s []string, e string) bool {
    for _, a := range s {
        if a == e {
            return true
        }
    }
    return false
}

