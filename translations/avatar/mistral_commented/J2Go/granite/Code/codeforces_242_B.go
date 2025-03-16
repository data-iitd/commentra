

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("Enter the number of elements in the arrays:")
    n, _ := strconv.Atoi(reader.ReadLine()[0:1])
    a := make([]int, n)
    b := make([]int, n)
    left := 1000000005
    right := 0
    for i := 0; i < n; i++ {
        fmt.Println("Enter the elements of the first array:")
        a[i], _ = strconv.Atoi(reader.ReadLine()[0:1])
        fmt.Println("Enter the elements of the second array:")
        b[i], _ = strconv.Atoi(reader.ReadLine()[0:1])
        if a[i] < left {
            left = a[i]
        }
        if b[i] > right {
            right = b[i]
        }
    }
    for i := 0; i < n; i++ {
        if a[i] == left && b[i] == right {
            fmt.Println(i + 1)
            return
        }
    }
    fmt.Println(-1)
}

