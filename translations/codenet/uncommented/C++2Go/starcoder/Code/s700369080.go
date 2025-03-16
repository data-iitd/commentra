package main

import "fmt"

func main() {
    var x1, x2, y1, y2 int
    fmt.Scanf("%d %d %d %d", &x1, &y1, &x2, &y2)
    dx, dy := x2-x1, y2-y1
    x3, y3 := x2-dy, y2+dx
    x4, y4 := x1-dy, y1+dx
    fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
}

