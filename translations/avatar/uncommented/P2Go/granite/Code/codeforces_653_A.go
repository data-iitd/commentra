
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
    fmt.Println("Enter the number of elements:")
    nTemp, _ := reader.ReadString('\n')
    n, _ := strconv.Atoi(strings.TrimSpace(nTemp))
    fmt.Println("Enter the elements:")
    lTemp, _ := reader.ReadString('\n')
    lTemp = strings.TrimSpace(lTemp)
    l := strings.Split(lTemp, " ")
    lInt := make([]int, n)
    for i := 0; i < n; i++ {
        lInt[i], _ = strconv.Atoi(l[i])
    }
    for i := 0; i < n; i++ {
        if contains(lInt, lInt[i]+1) && contains(lInt, lInt[i]+2) {
            fmt.Println("YES")
            return
        }
    }
    fmt.Println("NO")
}

func contains(arr []int, target int) bool {
    for _, v := range arr {
        if v == target {
            return true
        }
    }
    return false
}

