
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
    n, _ := strconv.Atoi(reader.ReadLine())
    arr := make([]int, n)
    sum := 0
    for i := 0; i < n; i++ {
        fmt.Print("Enter element ", i+1, ": ")
        arr[i], _ = strconv.Atoi(reader.ReadLine())
        sum += arr[i]
    }
    c := 0
    sb := strings.Builder{}
    for i := 0; i < n; i++ {
        if (sum-arr[i])%(n-1) == 0 && (sum-arr[i])/(n-1) == arr[i] {
            c++
            sb.WriteString(strconv.Itoa(i+1) + " ")
        }
    }
    fmt.Println("Number of elements that satisfy the condition:", c)
    fmt.Println("Indices of the elements that satisfy the condition:", sb.String())
}

