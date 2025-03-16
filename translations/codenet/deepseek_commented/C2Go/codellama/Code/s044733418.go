package main

import "fmt"

func compare(a, b *int) int {
    return *b - *a
}

func main() {
    array := make([]int, 10)
    for i := 0; i < 10; i++ {
        fmt.Scan(&array[i])
    }
    qsort(array, 10, sizeof(int), compare)
    for i := 0; i < 3; i++ {
        fmt.Println(array[i])
    }
}

