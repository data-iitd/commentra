<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
<<<<<<< HEAD
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("Enter the number of elements")
    n, _ := strconv.Atoi(reader.ReadString('\n'))
    a := make([]int, n)
    b := make([]int, n)
    fmt.Println("Enter the elements of array a")
    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &a[i])
    }
    fmt.Println("Enter the elements of array b")
    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &b[i])
    }
    sum := 0
    for i := 0; i < n; i++ {
        if a[i] > b[i] {
=======
    var n int
    var a, b, sum int
    fmt.Scanf("%d", &n)
    a = make([]int, n)
    b = make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &a[i])
    }
    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &b[i])
        if a[i]-b[i] > 0 {
>>>>>>> 98c87cb78a (data updated)
            sum += a[i] - b[i]
        }
    }
    fmt.Println(sum)
}

