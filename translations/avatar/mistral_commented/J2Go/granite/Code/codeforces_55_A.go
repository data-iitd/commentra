

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
    fmt.Println("Enter the value of n:")
    text, _ := reader.ReadString('\n')
    n, _ := strconv.Atoi(strings.TrimSpace(text))

    i := 1
    k := 0
    p := 1
    flag := true
    a := make([]int, 1000)

    for k <= n {
        i += k
        if i >= n {
            for i >= n {
                i -= n
            }
        }
        a[i]++
        k++
    }

    for i = 0; i < n; i++ {
        if a[i] == 0 {
            flag = false
            break
        }
    }

    if flag {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
}

These comments should provide a clear understanding of what each part of the code does. Let me know if you need any further clarification.

Translate the above Go code to C++ and end with comment "