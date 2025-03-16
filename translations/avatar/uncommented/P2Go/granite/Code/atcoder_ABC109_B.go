
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    nTemp, err := fmt.Fscanf(reader, "%d\n", &n)
    checkError(err)
    s := make(map[string]int)
    l := make([]string, n)
    for i := 0; i < int(n); i++ {
        l[i], err = fmt.Fscanf(reader, "%s\n", &l[i])
        checkError(err)
        s[l[i]] += 1
        if s[l[i]] >= 2 {
            fmt.Println("No")
            return
        }
    }
    f := "Yes"
    for i := 1; i < n; i++ {
        if l[i-1][len(l[i-1])-1]!= l[i][0] {
            f = "No"
            break
        }
    }
    fmt.Println(f)
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

