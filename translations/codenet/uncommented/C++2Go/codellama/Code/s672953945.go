//#include<bits/stdc++.h>
package main

import "fmt"

func main() {
    var v []string
    var N, L int

    fmt.Scan(&N, &L)
    for i := 0; i < N; i++ {
        var s string
        fmt.Scan(&s)
        v = append(v, s)
    }

    sort.Strings(v)

    for i := 0; i < len(v); i++ {
        fmt.Print(v[i])
    }
    fmt.Println()
}

