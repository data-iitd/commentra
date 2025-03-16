
package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Fprintln(os.Stderr, "Enter the number of elements:")
    n, _ := reader.ReadString('\n')
    n, _ = strconv.Atoi(strings.TrimSpace(n))
    a := make([]int, n)
    fmt.Fprintln(os.Stderr, "Enter the elements:")
    for i := 0; i < n; i++ {
        a[i], _ = reader.ReadString('\n')
        a[i], _ = strconv.Atoi(strings.TrimSpace(a[i]))
    }
    sort.Ints(a)
    for i := 0; i < n-1; i++ {
        if a[i] == a[i+1] {
            fmt.Println("NO")
            return
        }
    }
    fmt.Println("YES")
}

