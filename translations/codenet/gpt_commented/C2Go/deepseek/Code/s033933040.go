package main

import "fmt"

func main() {
    var a, b, mawari, menseki int
    
    fmt.Scan(&a, &b)
    
    mawari = a + a + b + b
    menseki = a * b
    
    fmt.Println(menseki, mawari)
}

