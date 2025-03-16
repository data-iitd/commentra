
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
    fmt.Println("Enter the values of A:")
    text, _ := reader.ReadString('\n')
    A := make([]int, 4)
    for i, v := range strings.Split(text, " ") {
        A[i], _ = strconv.Atoi(v)
    }
    if A[1] <= A[2] || A[3] <= A[0] {
        fmt.Println(0)
    } else {
        A = append(A[:1], A[2:]...)
        A = append(A[:2], A[3:]...)
        fmt.Println(A[1] - A[0])
    }
}
