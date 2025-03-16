package main

import "fmt"

func main() {
    var a, b, c, d, e, k int
    fmt.Scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &k)

    fmt.Println("Yay!" if e-a <= k else ":(")
}

