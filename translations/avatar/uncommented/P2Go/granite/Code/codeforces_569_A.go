
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

var (
    in  = bufio.NewReader(os.Stdin)
    out = bufio.NewWriter(os.Stdout)
)

func main() {
    var t, s, q int
    var ans int
    str := readline()
    t, _ = strconv.Atoi(str[0])
    s, _ = strconv.Atoi(str[1])
    q, _ = strconv.Atoi(str[2])
    ans = 0
    for s < t {
        s *= q
        ans++
    }
    fmt.Println(ans)
    out.Flush()
}

func readline() []string {
    str, _, err := in.ReadLine()
    if err!= nil {
        panic(err)
    }
    return strings.Split(string(str), " ")
}

