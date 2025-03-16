
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter the size of the array: ")
    size, _ := reader.ReadString('\n')
    size, _ = strconv.Atoi(size)
    arr := make([]byte, size)
    p := 97
    for i := 0; i < 4; i++ {
        for j := i; j < size; j += 4 {
            arr[j] = byte(p)
            p++
        }
    }
    fmt.Println(string(arr))
}

