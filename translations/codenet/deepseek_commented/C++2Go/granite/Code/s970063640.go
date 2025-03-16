
package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var n int
    var err error
    if n, err = strconv.Atoi(read(reader)); err!= nil {
        panic(err)
    }
    var a int
    if a, err = strconv.Atoi(read(reader)); err!= nil {
        panic(err)
    }
    s := make([]int, n)
    for i := 0; i < n; i++ {
        if s[i], err = strconv.Atoi(read(reader)); err!= nil {
            panic(err)
        }
    }
    sort.Ints(s)
    sum := 0
    for i := n - 1; i > n-a-1; i-- {
        sum += s[i]
    }
    fmt.Println(sum)
}

func read(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err!= nil {
        panic(err)
    }
    return string(str)
}

