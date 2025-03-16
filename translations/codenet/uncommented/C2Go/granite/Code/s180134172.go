
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var n, k int
    var err error
    var p []int

    n, err = strconv.Atoi(reader.ReadLine())
    if err!= nil {
        panic(err)
    }

    k, err = strconv.Atoi(reader.ReadLine())
    if err!= nil {
        panic(err)
    }

    for i := 0; i < n; i++ {
        var num int
        num, err = strconv.Atoi(reader.ReadLine())
        if err!= nil {
            panic(err)
        }
        p = append(p, num)
    }

    for i := 0; i < n; i++ {
        l := i
        for j := i + 1; j < n; j++ {
            if p[j] < p[l] {
                l = j
            }
        }
        if l!= i {
            m := p[i]
            p[i] = p[l]
            p[l] = m
        }
    }

    var sum int
    for i := 0; i < k; i++ {
        sum += p[i]
    }

    fmt.Println(sum)
}

