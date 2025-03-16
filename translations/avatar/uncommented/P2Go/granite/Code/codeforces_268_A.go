
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    n, _ := strconv.Atoi(reader.ReadLine())
    q := make([][]string, n)
    for i := 0; i < n; i++ {
        q[i] = strings.Split(reader.ReadLine(), " ")
    }
    count := 0
    for i := 0; i < n; i++ {
        for j := 0; j < n; j++ {
            if i == j {
                continue
            }
            if q[i][0] == q[j][len(q[j])-1] {
                count++
            } else {
                continue
            }
        }
    }
    fmt.Println(count)
}
