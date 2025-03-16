
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter the number of elements in the sequence: ")
    n, _ := strconv.Atoi(reader.ReadLine())
    fmt.Print("Enter the initial value of k: ")
    k, _ := strconv.Atoi(reader.ReadLine())

    i := 1
    req := 1

    for k-req >= 0 {
        if k-req >= 0 {
            k = k - req
        } else {
            break
        }
        i++
        if i%n!= 0 {
            req = i % n
        } else {
            req = n
        }
    }

    fmt.Println("The final value of k is:", k)
}

