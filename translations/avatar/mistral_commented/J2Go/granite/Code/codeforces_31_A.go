

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
    fmt.Print("Enter the number of elements in the array: ")
    n, _ := strconv.Atoi(reader.ReadLine()[0])
    a := make([]int, n)
    fmt.Println("Enter the elements of the array:")
    for i := 0; i < n; i++ {
        a[i], _ = strconv.Atoi(reader.ReadLine()[0])
    }
    f := 0
    k := 0
    j := 0
    i := 0
    for k = 0; k < n; k++ {
        t := a[k]
        for i = 0; i < n; i++ {
            if i!= k {
                for j = 0; j < n-1; j++ {
                    if i!= j && t == (a[i]+a[j]) {
                        f = 1
                        break
                    }
                }
                if f == 1 {
                    break
                }
            }
        }
        if f == 1 {
            fmt.Printf("%d %d %d\n", k+1, j+1, i+1)
            f = 0
        }
    }
    if f == 0 {
        fmt.Println("-1")
    }
}

These comments should help in understanding the logic of each block of code in the given Go program.

Translate the above Go code to C++ and end with comment "