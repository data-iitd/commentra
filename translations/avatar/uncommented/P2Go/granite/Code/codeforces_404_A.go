
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    n, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())])
    s := make([]string, n)
    for i := 0; i < n; i++ {
        s[i] = reader.ReadLine()[2 : len(reader.ReadLine())]
    }
    flag := 0
    d1 := make([]string, n)
    d2 := make([]string, n)
    rem := make(map[string]bool)
    for i := 0; i < n; i++ {
        for j := 0; j < n; j++ {
            if i == j {
                d1[i] = string(s[i][j])
            }
            if i == n-j-1 {
                d2[i] = string(s[i][j])
            }
            if i!= j && i!= n-j-1 {
                rem[string(s[i][j])] = true
            }
        }
    }
    if len(rem)!= 1 {
        fmt.Println("NO")
    } else if d1!= d2 {
        fmt.Println("NO")
    } else if len(rem)!= 1 {
        fmt.Println("NO")
    } else if rem[d1[0]] {
        fmt.Println("NO")
    } else {
        fmt.Println("YES")
    }
}
