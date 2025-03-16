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
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("Enter the number of elements in the array")
    input, _ := reader.ReadString('\n')
    input = strings.Replace(input, "\n", "", -1)
    N, _ := strconv.Atoi(input)
    A := make([]int, N)
    fmt.Println("Enter the elements of the array")
    for i := 0; i < N; i++ {
        fmt.Println("Enter the element at index", i)
        input, _ := reader.ReadString('\n')
        input = strings.Replace(input, "\n", "", -1)
        A[i], _ = strconv.Atoi(input)
    }

    m := A[0]
    M := A[0]
    for i := 0; i < N; i++ {
        if A[i] < m {
            m = A[i]
        }
        if A[i] > M {
            M = A[i]
        }
    }

    fmt.Println(M - m)
}

