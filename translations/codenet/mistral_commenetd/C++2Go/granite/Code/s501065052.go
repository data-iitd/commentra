

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    N, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1])

    mem := make([]int, N+1)

    for i := 1; i <= N; i++ {
        P, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1])
        mem[P] = i
    }

    maxcnt := 1
    cnt := 1

    for i := 1; i < N; i++ {
        if mem[i] < mem[i+1] {
            cnt++
        } else {
            if cnt > maxcnt {
                maxcnt = cnt
            }
            cnt = 1
        }
    }

    if cnt > maxcnt {
        maxcnt = cnt
    }

    fmt.Println(N - maxcnt)
}

