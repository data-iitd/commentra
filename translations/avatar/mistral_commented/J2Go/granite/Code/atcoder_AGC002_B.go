
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

type Box struct {
    num  int
    red  bool
}

func main() {
    reader := bufio.NewReader(os.Stdin)

    N, _ := strconv.Atoi(read(reader))
    M, _ := strconv.Atoi(read(reader))

    boxes := make([]*Box, N)

    boxes[0] = &Box{1, true}

    for i := 1; i < N; i++ {
        boxes[i] = &Box{1, false}
    }

    for i := 0; i < M; i++ {
        x, _ := strconv.Atoi(read(reader))
        y, _ := strconv.Atoi(read(reader))

        boxes[x-1].moveTo(boxes[y-1])
    }

    counter := 0
    for _, box := range boxes {
        if box.red {
            counter++
        }
    }

    fmt.Println(counter)
}

func read(reader *bufio.Reader) string {
    str, _, _ := reader.ReadLine()
    return string(str)
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

