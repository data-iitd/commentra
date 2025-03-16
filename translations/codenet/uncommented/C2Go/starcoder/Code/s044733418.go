package main

import "fmt"

func compare(a, b int) int {
    return b - a
}

func main() {
    var array [10]int
    for i := 0; i < 10; i++ {
        fmt.Scanf("%d", &array[i])
    }
    fmt.Println(array)
    fmt.Println(array[0:3])
    fmt.Println(array[3:6])
    fmt.Println(array[6:9])
    fmt.Println(array[9:10])
    fmt.Println(array[0:10:3])
    fmt.Println(array[0:10:4])
    fmt.Println(array[0:10:5])
    fmt.Println(array[0:10:6])
    fmt.Println(array[0:10:7])
    fmt.Println(array[0:10:8])
    fmt.Println(array[0:10:9])
    fmt.Println(array[0:10:10])
}

