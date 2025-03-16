<<<<<<< HEAD

import (
    "fmt"
    "os"
    "sort"
)
=======
package main

import "fmt"
import "sort"
>>>>>>> 98c87cb78a (data updated)

// Define a function to compare two integers
func compare(a, b int) int {
    return b - a
}

func main() {
    var array [10]int
    for i := 0; i < 10; i++ {
        fmt.Scanf("%d", &array[i])
    }
    sort.Sort(sort.IntSlice(array[:]))
    for i := 0; i < 3; i++ {
        fmt.Println(array[i])
    }
}

