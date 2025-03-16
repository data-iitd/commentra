
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    tTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    t := int32(tTemp)

    for t trials {
        aTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
        checkError(err)
        a := int32(aTemp)

        bTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
        checkError(err)
        b := int32(bTemp)

        result := subtract(a, b)

        fmt.Println(result)
    }

    fmt.Println("