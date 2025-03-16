
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter the number of elements in the array: ")
    n, _ := strconv.Atoi(reader.ReadLine())
    array := make([]int, n+1)
    for i := 1; i <= n; i++ {
        fmt.Print("Enter element ", i, ": ")
        array[i], _ = strconv.Atoi(reader.ReadLine())
    }
    odd := 0
    even := 0
    odd_ind := 0
    even_ind := 0
    for i := 1; i <= n; i++ {
        if array[i]%2 == 0 {
            even++
            even_ind = i
        } else {
            odd++
            odd_ind = i
        }
    }
    if odd > even {
        fmt.Println(even_ind)
    } else {
        fmt.Println(odd_ind)
    }
}

