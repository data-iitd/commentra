
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func check(x int, y int) string {
    if y%2 == 0 {
        t := int(0.5 * float64(y)) - x
        if t >= 0 && (x-t) >= 0 {
            return "Yes"
        }
    }
    return "No"
}

func main() {
    reader := bufio.NewReader(os.Stdin)

    xTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    x := int(xTemp)

    yTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    y := int(yTemp)

    fmt.Println(check(x, y))
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

