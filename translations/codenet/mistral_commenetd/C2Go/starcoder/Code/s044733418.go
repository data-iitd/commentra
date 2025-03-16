
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

func main() {
    var array [10]int
<<<<<<< HEAD
    var i int
    var j int
    var k int
    var temp int
    var str string
    var strs []string
    var num int
    var err error

    fmt.Println("Enter 10 integers:")
    for i = 0; i < 10; i++ {
        fmt.Scanf("%d", &array[i])
    }

    sort.Slice(array[:], func(i, j int) bool { return array[i] < array[j] })

    fmt.Println("The first three integers in ascending order are:")
    for i = 0; i < 3; i++ {
        fmt.Printf("%d\n", array[i])
=======
    for i := 0; i < 10; i++ {
        fmt.Scanf("%d", &array[i])
    }
    sort.Slice(array[:], func(i, j int) bool {
        return array[i] < array[j]
    })
    for i := 0; i < 3; i++ {
        fmt.Println(array[i])
>>>>>>> 98c87cb78a (data updated)
    }
}

