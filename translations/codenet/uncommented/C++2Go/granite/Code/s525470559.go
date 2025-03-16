
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

type task struct {
    name string
    time int
}

func main() {
    reader := bufio.NewReader(os.Stdin)
    n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    q, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

    Q := make([]task, n)
    for i := 0; i < n; i++ {
        a := strings.Split(readLine(reader), " ")
        Q[i] = task{a[0], mustParseInt(a[1])}
    }

    elaps := 0
    for len(Q) > 0 {
        p := Q[0]
        Q = Q[1:]
        if p.time <= q {
            elaps += p.time
            fmt.Printf("%s %d\n", p.name, elaps)
        } else {
            p.time -= q
            elaps += q
            Q = append(Q, p)
        }
    }
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    panic(err)
}

func mustParseInt(s string) int {
    v, err := strconv.Atoi(s)
    if err!= nil {
        panic(err)
    }
    return v
}

