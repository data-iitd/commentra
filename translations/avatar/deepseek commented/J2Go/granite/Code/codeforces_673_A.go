

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
    fmt.Println("Enter the number of elements in the list `a`:")
    n, _ := reader.ReadString('\n')
    n, _ = strconv.Atoi(strings.TrimSpace(n))

    a := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Printf("Enter the %dth integer value:\n", i+1)
        value, _ := reader.ReadString('\n')
        a[i], _ = strconv.Atoi(strings.TrimSpace(value))
    }

    result, pos, flag := 0, 0, 0
    if a[0] > 15 {
        result = 15
    } else {
        for i := 1; i < n; i++ {
            if a[i]-a[i-1] > 15 {
                pos = i - 1
                flag = 1
                break
            }
        }
        if flag == 1 {
            result = a[pos] + 15
        } else {
            result = a[n-1] + 15
        }
    }

    if result > 90 {
        result = 90
    }

    fmt.Println("The final result is:", result)
}

