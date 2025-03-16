

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    var princess, dragon, t, f, c int
    var err error

    princess, err = strconv.Atoi(readLine(reader))
    checkError(err)

    dragon, err = strconv.Atoi(readLine(reader))
    checkError(err)

    t, err = strconv.Atoi(readLine(reader))
    checkError(err)

    f, err = strconv.Atoi(readLine(reader))
    checkError(err)

    c, err = strconv.Atoi(readLine(reader))
    checkError(err)

    if dragon <= princess {
        fmt.Println(0)
        return
    }

    result := 0
    position := t * princess
    position += princess * position / (dragon - princess)

    for position < c {
        result += 1
        position += princess * position / dragon
        position += princess * f
        position += princess * position / (dragon - princess)
    }

    fmt.Println(result)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return string(str)
    }

    panic(err)
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

