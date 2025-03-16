

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
    fmt.Println("Enter the size of the array:")
    size, _ := reader.ReadString('\n')
    size = strings.TrimSpace(size)
    n, _ := strconv.Atoi(size)
    arr := make([]int, n)
    fmt.Println("Enter", n, "integers:")
    for i := 0; i < n; i++ {
        num, _ := reader.ReadString('\n')
        num = strings.TrimSpace(num)
        arr[i], _ = strconv.Atoi(num)
    }
    for i := 0; i < n-1; i++ {
        if arr[i+1] < arr[i]*2 && arr[i]!= arr[i+1] {
            fmt.Println("YES")
            return
        }
    }
    fmt.Println("NO")
}

