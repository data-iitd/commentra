

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
    fmt.Println("Enter the number of tasks:")
    n, _ := strconv.Atoi(reader.ReadLine()[0:1])
    fmt.Println("Enter the buffer size:")
    b, _ := strconv.Atoi(reader.ReadLine()[0:1])
    ans := make([]int64, n)
    q := make([]int64, 0)

    for i := 0; i < n; i++ {
        fmt.Println("Enter the start time and duration of the task:")
        input := reader.ReadLine()
        parts := strings.Split(string(input), " ")
        t, _ := strconv.Atoi(parts[0])
        d, _ := strconv.Atoi(parts[1])

        for len(q) > 0 && q[0] <= int64(t) {
            q = q[1:]
        }

        if len(q) <= b {
            ans[i] = (int64(t) + int64(d))
            if len(q) > 0 {
                ans[i] = int64(max(int(q[len(q)-1]), int(t))) + int64(d)
            }
            q = append(q, ans[i])
        } else {
            ans[i] = -1
        }
    }

    for i := 0; i < n; i++ {
        fmt.Printf("%d ", ans[i])
    }
    fmt.Println()
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

