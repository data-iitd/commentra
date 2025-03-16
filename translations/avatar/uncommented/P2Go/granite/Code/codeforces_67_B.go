
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
    fmt.Println("Enter the number of elements and the number of elements to be removed:")
    input, _ := reader.ReadString('\n')
    input = strings.TrimSpace(input)
    input = strings.Replace(input, "\n", "", -1)
    input = strings.Replace(input, " ", "", -1)
    inputSlice := strings.Split(input, ",")
    n, _ := strconv.Atoi(inputSlice[0])
    k, _ := strconv.Atoi(inputSlice[1])
    fmt.Println("Enter the elements:")
    input, _ = reader.ReadString('\n')
    input = strings.TrimSpace(input)
    input = strings.Replace(input, "\n", "", -1)
    input = strings.Replace(input, " ", "", -1)
    inputSlice = strings.Split(input, ",")
    M := make([]int, n)
    for i := 0; i < n; i++ {
        M[i], _ = strconv.Atoi(inputSlice[i])
    }
    m := 0
    for j := 0; j < n; j++ {
        for p := 0; p < n; p++ {
            if M[p] == 0 {
                fmt.Printf("%d ", p+1)
                break
            }
        }
        for l := 0; l < p+1-k; l++ {
            M[l] -= 1
        }
        M[p] -= 1
    }
    fmt.Println("