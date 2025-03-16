

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

type Box struct {
    num int
    red bool
}

func main() {
    reader := bufio.NewReader(os.Stdin)
    N, _ := strconv.Atoi(readLine(reader))
    M, _ := strconv.Atoi(readLine(reader))
    B := make([]*Box, N)
    B[0] = &Box{1, true}
    for i := 1; i < N; i++ {
        B[i] = &Box{1, false}
    }
    for i := 0; i < M; i++ {
        x, _ := strconv.Atoi(readLine(reader))
        y, _ := strconv.Atoi(readLine(reader))
        B[x-1].moveTo(B[y-1])
    }
    counter := 0
    for _, b := range B {
        if b.red {
            counter++
        }
    }
    fmt.Println(counter)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return string(str)
    }
    return ""
}

func (b *Box) moveTo(other *Box) {
    if b.num == 0 {
        return
    } else if b.num == 1 {
        b.num = 0
        other.num++
        if b.red {
            other.red = true
        }
        b.red = false
    } else {
        b.num--
        other.num++
        if b.red {
            other.red = true
        }
    }
}

