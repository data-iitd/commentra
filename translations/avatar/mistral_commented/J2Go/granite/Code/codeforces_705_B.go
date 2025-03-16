

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

var (
    reader = bufio.NewReader(os.Stdin)
    writer = bufio.NewWriter(os.Stdout)
)

func main() {
    tTemp, err := strconv.ParseInt(read(), 10, 64)
    checkError(err)
    t := int32(tTemp)

    for t0 := int32(0); t0 < t; t0++ {
        a0Temp, err := strconv.ParseInt(read(), 10, 64)
        checkError(err)
        a0 := int32(a0Temp)

        if a0 == 1 {
            if prevWinner == 0 {
                prevWinner = 2
            }

            if (a0-1)%2 == 0 {
                fmt.Fprintf(writer, "%d\n", prevWinner)
                prevWinner = (prevWinner + 1) % 2
            }
        }
    }

    writer.Flush()
}

func read() string {
    str, err := reader.ReadString('\n')
    if err == nil {
        str = strings.Replace(str, "\n", "", -1)
    }
    return str
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

var prevWinner int32 = 0

Translate the above Go code to C++ and end with comment "