
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    n, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1])
    p := make([]int, n)
    for i := 0; i < n; i++ {
        p[i], _ = strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1])
    }
    ans := 0
    for i := 0; i < n-2; i++ {
        if p[i] > p[i+1] && p[i+1] > p[i+2] {
            ans++
        }
        if p[i] < p[i+1] && p[i+1] < p[i+2] {
            ans++
        }
    }
    fmt.Println(ans)
}

